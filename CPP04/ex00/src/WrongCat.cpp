/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:17:34 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/09 15:34:37 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

using std::cout;
using std::clog;
using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

WrongCat::WrongCat(void) : WrongAnimal() {
    clog << "\033[2mWrongCat default constructor called\033[0m" << endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) {
    clog << "\033[2mWrongCat copy constructor called\033[0m" << endl;
    *this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    clog << "\033[2mWrongCat copy assignment operator called\033[0m" << endl;
    type = other.type;
    return (*this);
}

WrongCat::~WrongCat(void) {
    clog << "\033[2mWrongCat destructor called\033[0m" << endl;
}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

void WrongCat::makeSound(void) const {
    cout << "meow" << endl;
}
