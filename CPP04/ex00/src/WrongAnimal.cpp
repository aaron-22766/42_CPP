/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:16:55 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/13 09:51:01 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"

using std::cout;
using std::clog;
using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

WrongAnimal::WrongAnimal(void) : type("Unspecified Animal") {
    clog << "\033[2mWrongAnimal default constructor called\033[0m" << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
    clog << "\033[2mWrongAnimal copy constructor called\033[0m" << endl;
    *this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    clog << "\033[2mWrongAnimal copy assignment operator called\033[0m" << endl;
    type = other.type;
    return (*this);
}

WrongAnimal::~WrongAnimal(void) {
    clog << "\033[2mWrongAnimal destructor called\033[0m" << endl;
}

/* ************************************************************************** */
/*                             PUBLIC: ACCESSORS                              */
/* ************************************************************************** */

std::string WrongAnimal::getType(void) const {
    return (type);
}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

void WrongAnimal::makeSound(void) const {
    cout << endl;
}
