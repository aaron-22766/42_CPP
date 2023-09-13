/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:54:02 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/11 09:43:00 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

using std::cout;
using std::clog;
using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

Animal::Animal(void) : type("Unspecified Animal") {
    clog << "\033[2mAnimal default constructor called\033[0m" << endl;
}

Animal::Animal(const Animal &other) {
    clog << "\033[2mAnimal copy constructor called\033[0m" << endl;
    *this = other;
}

Animal &Animal::operator=(const Animal &other) {
    clog << "\033[2mAnimal copy assignment operator called\033[0m" << endl;
    type = other.type;
    return (*this);
}

Animal::~Animal(void) {
    clog << "\033[2mAnimal destructor called\033[0m" << endl;
}

/* ************************************************************************** */
/*                             PUBLIC: ACCESSORS                              */
/* ************************************************************************** */

std::string Animal::getType(void) const {
    return (type);
}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

void Animal::makeSound(void) const {
    cout << endl;
}
