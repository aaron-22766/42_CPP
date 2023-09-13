/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:47:23 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/13 10:25:57 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"

using std::cout;
using std::clog;
using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

Ice::Ice(void) : AMateria("ice") {
    clog << "\033[2mIce default constructor called\033[0m" << endl;
}

Ice::Ice(const Ice &other) : AMateria("ice") {
    clog << "\033[2mIce copy constructor called\033[0m" << endl;
    (void)other;
}

Ice &Ice::operator=(const Ice &other) {
    clog << "\033[2mIce copy assignment operator called\033[0m" << endl;
    (void)other;
    return (*this);
}

Ice::~Ice(void) {
    clog << "\033[2mIce destructor called\033[0m" << endl;
}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

AMateria *Ice::clone(void) const {
    return (new Ice());
}

void Ice::use(ICharacter &target) {
    cout << "* shoots an ice bolt at " << target.getName() << " *" << endl;
}

