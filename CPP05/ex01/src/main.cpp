/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:53:56 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/21 10:06:53 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

using std::cout;
using std::endl;

int main(void) {
    try {
        Bureaucrat b("Bob", 60);
        Form f = Form("#42", 0, 150);

        cout << b << endl << f << endl;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    cout << endl;
    try {
        Bureaucrat b("Bob", 60);
        Form f = Form("#42", 1, 151);

        cout << b << endl << f << endl;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    cout << endl;
    try {
        Bureaucrat b("Bob", 60);
        Form f = Form("#42", 50, 50);

        cout << b << endl << f << endl;
        b.signForm(f);
        cout << f << endl;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    cout << endl;
    try {
        Bureaucrat b("Bob", 1);
        Form f = Form("#42", 1, 1);

        cout << b << endl << f << endl;
        b.signForm(f);
        cout << f << endl;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
}
