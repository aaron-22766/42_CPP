/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:55:07 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/22 12:42:02 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

AForm::AForm(void) : _name("(Unnamed)"), _signGrade(150), _executeGrade(150) {}

AForm::AForm(std::string name, int signGrade, int executeGrade) :
    _name(name), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (_signGrade < 1 || _executeGrade < 1) {
        throw AForm::GradeTooHighException();
    }
    if (_signGrade > 150 || _executeGrade > 150) {
        throw AForm::GradeTooLowException();
    }
}

AForm::AForm(const AForm &other) :
    _name(other._name), _isSigned(other._isSigned),
    _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}

AForm &AForm::operator=(const AForm &other) {
    _isSigned = other._isSigned;
    return (*this);
}

AForm::~AForm(void) {}

/* ************************************************************************** */
/*                             PUBLIC: ACCESSORS                              */
/* ************************************************************************** */

std::string AForm::getName(void) const {
    return (_name);
}

bool AForm::isSigned(void) const {
    return (_isSigned);
}

int AForm::getSignGrade(void) const {
    return (_signGrade);
}

int AForm::getExecuteGrade(void) const {
    return (_executeGrade);
}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade) {
        throw AForm::GradeTooLowException();
    }
    _isSigned = true;
}

/* ************************************************************************** */
/*                             PUBLIC: EXCEPTIONS                             */
/* ************************************************************************** */

const char *AForm::GradeTooHighException::what(void) const throw() {
    return ("grade is too high");
}

const char *AForm::GradeTooLowException::what(void) const throw() {
    return ("grade is too low");
}

const char *AForm::FormUnsignedException::what(void) const throw() {
    return ("form is unsigned");
}

/* ************************************************************************** */
/*                             PROTECTED: METHODS                             */
/* ************************************************************************** */

void AForm::checkRequirements(const Bureaucrat &bureaucrat) const {
    if (_isSigned == false) {
        throw AForm::FormUnsignedException();
    }
    if (bureaucrat.getGrade() > _executeGrade) {
        throw AForm::GradeTooLowException();
    }
}

/* ************************************************************************** */
/*                             PUBLIC: OVERLOADS                              */
/* ************************************************************************** */

std::ostream &operator<<(std::ostream &os, const AForm &rhs) {
    return (os << "|| Form: " << rhs.getName() << endl
               << "|| is " << (rhs.isSigned() ? "signed" : "unsigned") << endl
               << "|| sign grade is " << rhs.getSignGrade() << endl
               << "|| execute grade is " << rhs.getExecuteGrade());
}
