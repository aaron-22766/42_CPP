/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:53:56 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/21 10:37:54 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

using std::cout;
using std::endl;

int main(void) {
    try {
        Bureaucrat b("Bob", 140);
        ShrubberyCreationForm s("home");
        RobotomyRequestForm r("robot");
        PresidentialPardonForm p("John");
        
        b.executeForm(s);
        b.signForm(s);
        b.executeForm(s);
        cout << endl;
        b.executeForm(r);
        b.signForm(r);
        b.executeForm(r);
        cout << endl;
        b.executeForm(p);
        b.signForm(p);
        b.executeForm(p);
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    cout << endl;
    try {
        Bureaucrat b("Zaphod", 1);
        ShrubberyCreationForm s("Earth 2.0");
        RobotomyRequestForm r("Marvin");
        PresidentialPardonForm p("Arthur Dent");
        
        b.executeForm(s);
        b.signForm(s);
        b.executeForm(s);
        cout << endl;
        b.executeForm(r);
        b.signForm(r);
        b.executeForm(r);
        cout << endl;
        b.executeForm(p);
        b.signForm(p);
        b.executeForm(p);
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
}
