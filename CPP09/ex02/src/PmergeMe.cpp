/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:36:44 by arabenst          #+#    #+#             */
/*   Updated: 2023/11/25 15:26:39 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

static int getValue(const std::string str) {
    if (str.empty()) {
        throw std::runtime_error("empty argument");
    }
    if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-') {
        throw std::runtime_error("not a number: \'" + str + "\'");
    }
    for (size_t i = 1; i < str.length(); ++i) {
        if (!isdigit(str[i])) {
            throw std::runtime_error("not a number: \'" + str + "\'");
        }
    }
    int res;
    std::istringstream iss(str);
    if (!(iss >> res)) {
        throw std::runtime_error("not a valid int: " + str);
    } else if (res < 0) {
        throw std::runtime_error("negative number: " + str);
    }
    return (res);
}

void printVector(std::vector<int> &vec, std::string when) {
    cout << when << ": ";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

static void printTime(unsigned long long us, size_t size, std::string cont) {
    cout << "Time to process a range of " << size
         << " elements with std::" << cont << " : ";
    double duration = static_cast<double>(us);
    if (us >= 60000000) {
        cout << fixed << setprecision(5) << duration / 60000000.0 << " m";
    } else if (us >= 1000000) {
        cout << fixed << setprecision(5) << duration / 1000000.0 << " s";
    } else if (us >= 1000) {
        cout << fixed << setprecision(5) << duration / 1000.0 << " ms";
    } else {
        cout << us << " us";
    }
    cout << endl;
}

static unsigned long long currentTime(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (static_cast<unsigned long long>(tv.tv_sec) * 1000000 + tv.tv_usec);
}

void PmergeMe(int argc, char *argv[]) {
    if (argc == 0) {
        throw std::runtime_error("no arguments");
    }
    
    std::vector<int> input;
    for (int i = 0; i < argc; ++i) {
        input.push_back(getValue(argv[i]));
    }
    
    printVector(input, "Before");

    std::vector<int> vec(input);
    unsigned long long vecTime = currentTime();
    fj_sort(vec);
    vecTime = currentTime() - vecTime;
    
    std::deque<int> deq(input.begin(), input.end());
    unsigned long long deqTime = currentTime();
    fj_sort(deq);
    deqTime = currentTime() - deqTime;
    
    // Check if the containers are sorted correctly
    std::sort(input.begin(), input.end());
    for (size_t i = 0; i < input.size(); ++i) {
        if (vec[i] != input[i])
            throw std::runtime_error("vector not sorted");
        if (*(deq.begin() + i) != input[i])
            throw std::runtime_error("deque not sorted");
    }

    printVector(vec, "After ");

    printTime(vecTime, input.size(), "vector");
    printTime(deqTime, input.size(), "deque");
}
