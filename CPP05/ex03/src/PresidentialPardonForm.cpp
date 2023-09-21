/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 08:33:30 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/21 10:45:49 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

using std::cout;
using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

PresidentialPardonForm::PresidentialPardonForm(void) :
    AForm("PresidentialPardonForm", 25, 5), _target("No target") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
    AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    _target = other._target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    checkRequirements(executor);
    cout << _target << " has been pardoned by Zaphod Beeblebrox" << endl;
}
