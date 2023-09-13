/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:55:25 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/13 10:26:05 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"

using std::cout;
using std::clog;
using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

Cure::Cure(void) : AMateria("cure") {
    clog << "\033[2mCure default constructor called\033[0m" << endl;
}

Cure::Cure(const Cure &other) : AMateria("cure") {
    clog << "\033[2mCure copy constructor called\033[0m" << endl;
    (void)other;
}

Cure &Cure::operator=(const Cure &other) {
    clog << "\033[2mCure copy assignment operator called\033[0m" << endl;
    (void)other;
    return (*this);
}

Cure::~Cure(void) {
    clog << "\033[2mCure destructor called\033[0m" << endl;
}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

AMateria *Cure::clone(void) const {
    return (new Cure());
}

void Cure::use(ICharacter &target) {
    cout << "* heals " << target.getName() << "’s wounds *" << endl;
}

