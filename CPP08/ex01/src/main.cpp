/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:46:55 by arabenst          #+#    #+#             */
/*   Updated: 2023/11/22 18:08:41 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include "../include/Span.hpp"

using std::cout;
using std::endl;

void tryAddNumber(Span &sp, int num) {
    cout << "Try adding number: ";
    try {
        sp.addNumber(num);
        cout << "Success!" << endl;
    } catch (std::exception &e) {
        cout << "Exception: " << e.what() << endl;
    }
}

template <typename InputIt>
void tryAddRange(Span &sp, const InputIt &first, const InputIt &last) {
    cout << "Try adding range: ";
    try {
        sp.addRange(first, last);
        cout << "Success!" << endl;
    } catch (std::exception &e) {
        cout << "Exception: " << e.what() << endl;
    }
}

void tryShortestSpan(Span &sp) {
    cout << "Try shortest span: ";
    try {
        cout << sp.shortestSpan() << endl;
    } catch (std::exception &e) {
        cout << "Exception: " << e.what() << endl;
    }
}

void tryLongestSpan(Span &sp) {
    cout << "Try longest span : ";
    try {
        cout << sp.longestSpan() << endl;
    } catch (std::exception &e) {
        cout << "Exception: " << e.what() << endl;
    }
}

int main(void) {
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        cout << sp.shortestSpan() << endl;
        cout << sp.longestSpan() << endl;
    }
    cout << endl;
    {
        Span sp(2);
        tryAddNumber(sp, 0);
        tryAddNumber(sp, 1);
        tryAddNumber(sp, 2);
    }
    cout << endl;
    {
        Span sp(5);
        tryShortestSpan(sp);
        tryLongestSpan(sp);
        sp.addNumber(0);
        tryShortestSpan(sp);
        tryLongestSpan(sp);
        sp.addNumber(100);
        tryShortestSpan(sp);
        tryLongestSpan(sp);
    }
    cout << endl;
    {
        const int arr[] = {8, 6, 7, 3, 3, 1, 6, 9, 4, 9};
        std::set<int> set(arr, arr + 10);
        
        Span sp(10);
        tryAddRange(sp, set.begin(), set.end());
        tryShortestSpan(sp);
        tryLongestSpan(sp);
    }
    cout << endl;
    {
        std::srand(std::time(NULL));
        std::vector<int> vec;
        for (int i = 0; i < 20000; i++) {
            vec.push_back(std::rand());
        }
        
        Span sp(20000);
        tryAddRange(sp, vec.begin(), vec.end());
        tryShortestSpan(sp);
        tryLongestSpan(sp);
    }
    return (EXIT_SUCCESS);
}
