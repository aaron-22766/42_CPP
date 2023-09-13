/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:12:27 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/09 15:27:17 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

using std::cout;
using std::clog;
using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

Cat::Cat(void) : Animal() {
    clog << "\033[2mCat default constructor called\033[0m" << endl;
    type = "Cat";
}

Cat::Cat(const Cat &other) {
    clog << "\033[2mCat copy constructor called\033[0m" << endl;
    *this = other;
}

Cat &Cat::operator=(const Cat &other) {
    clog << "\033[2mCat copy assignment operator called\033[0m" << endl;
    type = other.type;
    return (*this);
}

Cat::~Cat(void) {
    clog << "\033[2mCat destructor called\033[0m" << endl;
}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

void Cat::makeSound(void) const {
    cout << "meow" << endl;
}
