/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:52:43 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/21 11:51:12 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

using std::cerr;
using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

Intern::Intern(void) {}

Intern::Intern(const Intern &other) {
    (void)other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return (*this);
}

Intern::~Intern(void) {}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

AForm *Intern::makeForm(std::string formName, std::string formTarget) const {
    std::string forms[] = {"shrubbery creation",
                           "robotomy request",
                           "presidential pardon"};
    int f = 0;
    while (f < 3) {
        if (forms[f] == formName) {
            break ;
        }
        f++;
    }
    switch (f) {
        case 0:
            return (new ShrubberyCreationForm(formTarget));
        case 1:
            return (new RobotomyRequestForm(formTarget));
        case 2:
            return (new PresidentialPardonForm(formTarget));
    }
    cerr << "Intern is not able to make a '" << formName << "' form" << endl;
    return (NULL);
}
