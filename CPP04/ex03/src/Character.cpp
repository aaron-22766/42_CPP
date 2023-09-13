/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:51:49 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/13 10:38:37 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"
#include "../include/Character.hpp"

using std::cout;
using std::clog;
using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

Character::Character(void) : _inventory() {
    clog << "\033[2mCharacter default constructor called\033[0m" << endl;
}

Character::Character(const std::string name) : _name(name), _inventory() {
    clog << "\033[2mCharacter name constructor called\033[0m" << endl;
}

Character::Character(const Character &other) {
    clog << "\033[2mCharacter copy constructor called\033[0m" << endl;
    *this = other;
}

Character &Character::operator=(const Character &other) {
    clog << "\033[2mCharacter copy assignment operator called\033[0m" << endl;
    _name = other._name;
    
    int i = 0;
    while (i < SLOTS && _inventory[i]) {
        delete _inventory[i];
        _inventory[i++] = NULL;
    }
    i = 0;
    while (i < SLOTS && other._inventory[i]) {
        _inventory[i] = other._inventory[i]->clone();
        i++;
    }
    return (*this);
}

Character::~Character(void) {
    clog << "\033[2mCharacter destructor called\033[0m" << endl;
    for (int i = 0; i < SLOTS; i++) {
        delete _inventory[i];
    }
}

/* ************************************************************************** */
/*                             PUBLIC: ACCESSORS                              */
/* ************************************************************************** */

const std::string &Character::getName(void) const {
    return (_name);
}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

void Character::equip(AMateria *m) {
    int i = 0;
    while (i < SLOTS && _inventory[i]) {
        i++;
    }
    if (i < SLOTS) {
        _inventory[i] = m;
    }
}

void Character::unequip(int idx) {
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
    if (_inventory[idx]) {
        _inventory[idx]->use(target);
    }
}
