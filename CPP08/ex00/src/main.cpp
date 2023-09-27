/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:38:21 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/27 11:13:54 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
// #include <multiset>
#include <ctime>

using std::cout;
using std::endl;

template <typename T>
void printContainer(T &container) {
    cout << "[";
    typename T::iterator itr = container.begin();
    for (; itr != --container.end(); itr++) {
        cout << *itr << ", ";
    }
    cout << *itr << "]" << endl;
}

template <typename T>
void verboseFind(T &haystack, const int &needle) {
    cout << "Searching: " << needle << ", ";
    typename T::iterator it = easyfind(haystack, needle);
    if (it != haystack.end()) {
        cout << "found at index: " << std::distance(haystack.begin(), it);
    } else {
        cout << "not found!";
    }
    cout << endl;
}

template <typename T>
void testContainer(std::string name, T &container) {
    cout << endl << name << ":" << endl;
    printContainer(container);
    for (int i = 0; i < 5; i++) {
        verboseFind(container, rand() % 10);
    }
}

int main(void) {
    std::srand(std::time(NULL));
    const int arr[] = {8, 6, 7, 3, 3, 1, 6, 9, 4, 9};

    std::vector<int> vector(arr, arr + 10);
    testContainer("Vector", vector);
    
    std::list<int> list(arr, arr + 10);
    testContainer("List", list);

    std::deque<int> deque(arr, arr + 10);
    testContainer("Deque", deque);

    std::multiset<int> multiset(arr, arr + 10);
    testContainer("Multiset", multiset);

    std::set<int> set(arr, arr + 10);
    testContainer("Set", set);
    
    return (EXIT_SUCCESS);
}
