/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:53:32 by arabenst          #+#    #+#             */
/*   Updated: 2023/11/17 12:56:08 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <string>
#include "../include/iter.hpp"

template <typename T>
void iter(const T *array, const size_t len, void (*f)(const T &)) {
    for (size_t i = 0; i < len; i++) {
        f(array[i]);
    }
}

template <typename T>
void print(const T &data) {
    std::cout << data << std::endl;
}

int main(void) {
    {
        int arr[5] = {72, 3737, 648, 2, 3764};
        iter(arr, 5, print<const int>);
    }
    std::cout << std::endl;
    {
        float arr[3] = {7.2f, 3.737f, 64.8f};
        iter(arr, 3, print<float>);
    }
    std::cout << std::endl;
    {
        std::string arr[2] = {"Hello", "World"};
        iter(arr, 2, print<std::string>);
    }
    return (EXIT_SUCCESS);
}
