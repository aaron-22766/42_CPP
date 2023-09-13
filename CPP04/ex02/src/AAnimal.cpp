/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:54:02 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/13 10:07:54 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AAnimal.hpp"

using std::cout;
using std::clog;
using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

AAnimal::AAnimal(void) : type("Unspecified Animal") {
    clog << "\033[2mAAnimal default constructor called\033[0m" << endl;
}

AAnimal::AAnimal(const AAnimal &other) {
    clog << "\033[2mAAnimal copy constructor called\033[0m" << endl;
    *this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
    clog << "\033[2mAAnimal copy assignment operator called\033[0m" << endl;
    type = other.type;
    return (*this);
}

AAnimal::~AAnimal(void) {
    clog << "\033[2mAAnimal destructor called\033[0m" << endl;
}

/* ************************************************************************** */
/*                             PUBLIC: ACCESSORS                              */
/* ************************************************************************** */

std::string AAnimal::getType(void) const {
    return (type);
}
