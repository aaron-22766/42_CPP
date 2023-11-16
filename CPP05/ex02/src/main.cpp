/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:53:56 by arabenst          #+#    #+#             */
/*   Updated: 2023/11/16 15:21:39 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

using std::cout;
using std::endl;

int main(void) {
    {
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
    }
    cout << endl;
    {
        Bureaucrat b("Marvin", 1);
        RobotomyRequestForm r("Marvin");
        PresidentialPardonForm p("Arthur Dent");
        ShrubberyCreationForm s("Earth 2.0");

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
    }
}
