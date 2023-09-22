/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:55:07 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/22 12:41:46 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

Form::Form(void) : _name("(Unnamed)"), _signGrade(150), _executeGrade(150) {}

Form::Form(std::string name, int signGrade, int executeGrade) :
    _name(name), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (_signGrade < 1 || _executeGrade < 1) {
        throw Form::GradeTooHighException();
    }
    if (_signGrade > 150 || _executeGrade > 150) {
        throw Form::GradeTooLowException();
    }
}

Form::Form(const Form &other) :
    _name(other._name), _isSigned(other._isSigned),
    _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}

Form &Form::operator=(const Form &other) {
    _isSigned = other._isSigned;
    return (*this);
}

Form::~Form(void) {}

/* ************************************************************************** */
/*                             PUBLIC: ACCESSORS                              */
/* ************************************************************************** */

std::string Form::getName(void) const {
    return (_name);
}

bool Form::isSigned(void) const {
    return (_isSigned);
}

int Form::getSignGrade(void) const {
    return (_signGrade);
}

int Form::getExecuteGrade(void) const {
    return (_executeGrade);
}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade) {
        throw Form::GradeTooLowException();
    }
    _isSigned = true;
}

/* ************************************************************************** */
/*                             PUBLIC: EXCEPTIONS                             */
/* ************************************************************************** */

const char *Form::GradeTooHighException::what(void) const throw() {
    return ("grade is too high");
}

const char *Form::GradeTooLowException::what(void) const throw() {
    return ("grade is too low");
}

/* ************************************************************************** */
/*                             PUBLIC: OVERLOADS                              */
/* ************************************************************************** */

std::ostream &operator<<(std::ostream &os, const Form &rhs) {
    return (os << "|| Form: " << rhs.getName() << endl
               << "|| is " << (rhs.isSigned() ? "signed" : "unsigned") << endl
               << "|| sign grade is " << rhs.getSignGrade() << endl
               << "|| execute grade is " << rhs.getExecuteGrade());
}
