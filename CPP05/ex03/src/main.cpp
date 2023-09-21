/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:53:56 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/21 11:53:32 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

using std::cout;
using std::endl;

int main(void) {
    try {
        Bureaucrat ben("Ben", 17);
        Intern intern;
        AForm* form;
        form = intern.makeForm("robotomy request", "Bender");
        form->execute(ben);
        delete form;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    cout << endl;
    try {
        Bureaucrat ben("Ben", 17);
        Intern intern;
        AForm* form;
        form = intern.makeForm("garbage", "Bender");
        delete form;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    cout << endl;
    try {
        Bureaucrat ben("Ben", 17);
        Intern intern;
        AForm* form;
        form = intern.makeForm("shrubbery creation", "Bender");
        form->beSigned(ben);
        form->execute(ben);
        delete form;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    cout << endl;
    try {
        Bureaucrat ben("Ben", 17);
        Intern intern;
        AForm* form;
        form = intern.makeForm("robotomy request", "Bender");
        form->beSigned(ben);
        form->execute(ben);
        delete form;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    cout << endl;
    try {
        Bureaucrat ben("Ben", 17);
        Intern intern;
        AForm* form;
        form = intern.makeForm("presidential pardon", "Bender");
        form->beSigned(ben);
        form->execute(ben);
        delete form;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
}
