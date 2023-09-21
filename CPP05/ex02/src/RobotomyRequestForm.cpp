/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 08:32:53 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/21 10:45:45 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "../include/RobotomyRequestForm.hpp"

using std::cout;
using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

RobotomyRequestForm::RobotomyRequestForm(void) :
    AForm("RobotomyRequestForm", 72, 45), _target("No target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
    AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
    AForm(other), _target(other._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    _target = other._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    checkRequirements(executor);
    srand(time(NULL));
    std::string drillingNoise[4] = {"Brrrrr", "Zzzzzz", "Pfffff", "Tzzzzz"};
    for (int i = 0; i < 10; i++) {
        cout << drillingNoise[rand() % 4] << endl;
        if (rand() % 3 == 0) {
            break ;
        }
        sleep(1);
    }
    if (rand() % 2) {
        cout << _target << " has been robotomized successfully" << endl;
    } else {
        cout << "Failed to robotomize " << _target << endl;
    }
}
