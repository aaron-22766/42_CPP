/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:58:33 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/13 10:23:04 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"

using std::cout;
using std::clog;
using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

AMateria::AMateria(void) {
    clog << "\033[2mAMateria default constructor called\033[0m" << endl;
}

AMateria::AMateria(const std::string &type) : _type(type) {
    clog << "\033[2mAMateria type constructor called\033[0m" << endl;
}

AMateria::AMateria(const AMateria &other) {
    clog << "\033[2mAMateria copy constructor called\033[0m" << endl;
    (void)other;
}

AMateria &AMateria::operator=(const AMateria &other) {
    clog << "\033[2mAMateria copy assignment operator called\033[0m" << endl;
    (void)other;
    return (*this);
}

AMateria::~AMateria(void) {
    clog << "\033[2mAMateria destructor called\033[0m" << endl;
}

/* ************************************************************************** */
/*                             PUBLIC: ACCESSORS                              */
/* ************************************************************************** */
    
const std::string &AMateria::getType() const {
    return (_type);
}

void AMateria::use(ICharacter &target) {
    (void)target;
    cout << "[ useless option ]" << endl;
}
