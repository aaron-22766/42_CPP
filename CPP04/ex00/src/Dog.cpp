/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:12:46 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/09 15:27:21 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

using std::cout;
using std::clog;
using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

Dog::Dog(void) : Animal() {
    clog << "\033[2mDog default constructor called\033[0m" << endl;
    type = "Dog";
}

Dog::Dog(const Dog &other) {
    clog << "\033[2mDog copy constructor called\033[0m" << endl;
    *this = other;
}

Dog &Dog::operator=(const Dog &other) {
    clog << "\033[2mDog copy assignment operator called\033[0m" << endl;
    type = other.type;
    return (*this);
}

Dog::~Dog(void) {
    clog << "\033[2mDog destructor called\033[0m" << endl;
}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

void Dog::makeSound(void) const {
    cout << "woof" << endl;
}
