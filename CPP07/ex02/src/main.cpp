/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:41:26 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/25 14:51:14 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"
#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::endl;

template <typename T>
std::string numberToString(T num)
{
    std::ostringstream ss;
    ss << num;
    return (ss.str());
}

template <typename T>
void printArray(Array<T> &array, std::string name) {
    cout << name << ": " << array.size() << endl << "[";
    for (unsigned int i = 0; i < array.size(); i++) {
        cout << array[i] << ((i + 1 != array.size()) ? ", " : "");
    }
    cout << "]" << endl;
}

template <typename T>
void writeStringArray(Array<T> &array, std::string content) {
    for (unsigned int i = 0; i < array.size(); i++) {
        array[i] = content + "_" + numberToString(i);
    }
}

int main(void) {
    try {
        Array<int> intArray;
        cout << "intArray: " << intArray.size() << endl;
        cout << intArray[0];
    } catch (std::exception &e) {
        cout << "Exception: " << e.what() << endl;
    }
    
    cout << endl << std::string(60, '-') << endl << endl;
    
    {
        Array<int> *intArray = new Array<int>(15);
        for (unsigned int i = 0; i < intArray->size(); i++) {
            (*intArray)[i] = i * 9;
        }
        printArray(*intArray, "intArray");
        try {
            cout << (*intArray)[100];
        } catch (std::exception &e) {
            cout << "Exception: " << e.what() << endl;
        }
        delete intArray;
    }
    
    cout << endl << std::string(60, '-') << endl << endl;
    
    {
        Array<std::string> strArray1(3);
        writeStringArray(strArray1, "Hello");
        printArray(strArray1, "strArray1");
        Array<std::string> strArray2(5);
        writeStringArray(strArray2, "World");
        printArray(strArray2, "strArray2");
        cout << endl << "Copying strArray2 to strArray1..." << endl << endl;
        strArray1 = strArray2;
        printArray(strArray1, "strArray1");
        printArray(strArray2, "strArray2");
        cout << endl << "Changing strArray2..." << endl << endl;
        writeStringArray(strArray2, "Goodbye");
        printArray(strArray1, "strArray1");
        printArray(strArray2, "strArray2");
    }
    return (EXIT_SUCCESS);
}
