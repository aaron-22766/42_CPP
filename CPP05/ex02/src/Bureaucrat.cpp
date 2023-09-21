/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:55:26 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/21 10:31:00 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

using std::cout;
using std::endl;

/* ************************************************************************** */
/*                          PUCLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

Bureaucrat::Bureaucrat(void) : _name("(Unnamed)"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) :
    _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    _grade = other._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat(void) {}

/* ************************************************************************** */
/*                             PUBLIC: ACCESSORS                              */
/* ************************************************************************** */

std::string Bureaucrat::getName(void) const {
    return (_name);
}

int Bureaucrat::getGrade(void) const {
    return (_grade);
}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

void Bureaucrat::incrementGrade(void) {
    if (_grade == 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    _grade--;
}

void Bureaucrat::decrementGrade(void) {
    if (_grade == 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    _grade++;
}

void Bureaucrat::signForm(AForm &form) const {
    cout << _name << " ";
    try {
        form.beSigned(*this);
        cout << "signed " << form.getName();
    } catch (std::exception &e) {
        cout << "couldn't sign " << form.getName() << " because " << e.what();
    }
    cout << endl;
}

void Bureaucrat::executeForm(const AForm &form) const {
    try {
        form.execute(*this);
        cout << _name << " executed " << form.getName();
    } catch (std::exception &e) {
        cout << _name << " failed to execute " << form.getName() << " because " << e.what();
    }
    cout << endl;
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
    return ("grade is too low");
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
    return ("grade is too high");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs) {
	return (os << rhs.getName() << " is a bureaucrat with grade " << rhs.getGrade());
}
