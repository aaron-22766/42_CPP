/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:53:56 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/21 10:07:02 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

using std::cout;
using std::endl;

int main(void) {
    try {
        Bureaucrat b("Frodo", 1);
        
        cout << b << endl;
        b.decrementGrade();
        cout << b << endl;
        b.incrementGrade();
        cout << b << endl;
        b.incrementGrade();
        cout << b << endl;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    cout << endl;
    try {
        Bureaucrat b("Sam", 10);
        
        cout << b << endl;
        b.incrementGrade();
        cout << b << endl;
        b.decrementGrade();
        cout << b << endl;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    cout << endl;
    try {
        Bureaucrat b("Merry", 100);
        
        cout << b << endl;
        b.decrementGrade();
        cout << b << endl;
        b.incrementGrade();
        cout << b << endl;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    cout << endl;
    try {
        Bureaucrat b("Pippin", 150);
        
        cout << b << endl;
        b.incrementGrade();
        cout << b << endl;
        b.decrementGrade();
        cout << b << endl;
        b.decrementGrade();
        cout << b << endl;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    cout << endl;
    try {
        Bureaucrat b("Gandalf", 0);
        
        cout << b << endl;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    cout << endl;
    try {
        Bureaucrat b("Aragorn", 151);
        
        cout << b << endl;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    cout << endl;
    try {
        Bureaucrat b("Legolas", -10);
        
        cout << b << endl;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    cout << endl;
    try {
        Bureaucrat b("Gimli", 1111);
        
        cout << b << endl;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    cout << endl;
    try {
        Bureaucrat b("Boromir", __INT_MAX__);
        
        cout << b << endl;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
}
