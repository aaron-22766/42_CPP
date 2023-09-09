/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:54:02 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/09 14:52:29 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

using std::cout;
using std::clog;
using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

ClapTrap::ClapTrap(void) :
    _name("Unnamed"), _health(10), _energy(10), _damage(0) {
    clog << "\033[2mClapTrap default constructor called\033[0m" << endl;
}

ClapTrap::ClapTrap(std::string name) :
    _name(name), _health(10), _energy(10), _damage(0) {
    clog << "\033[2mClapTrap name constructor called\033[0m" << endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    clog << "\033[2mClapTrap copy constructor called\033[0m" << endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    clog << "\033[2mClapTrap copy assignment operator called\033[0m" << endl;
    _name = other._name;
    _health = other._health;
    _energy = other._energy;
    _damage = other._damage;
    return (*this);
}

ClapTrap::~ClapTrap(void) {
    clog << "\033[2mClapTrap destructor called\033[0m" << endl;
}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

void ClapTrap::attack(const std::string &target) {
    if (_health && _energy) {
        cout << "\033[2mClapTrap\033[0m " << _name << " attacks " << target
             << " causing " << _damage << " points of damage!" << endl;
        _energy--;
    } else if (_health == 0) {
        cout << "\033[2mClapTrap\033[0m " << _name
             << " is already dead!" << endl;
    } else if (_energy == 0) {
        cout << "\033[2mClapTrap\033[0m " << _name
             << " has no energy to attack!" << endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_health == 0) {
        cout << "\033[2mClapTrap\033[0m " << _name
             << " is already dead!" << endl;
        return ;
    }
    cout << "\033[2mClapTrap\033[0m " << _name << " takes "
         << amount << " points of damage!" << endl;
    if (amount < _health) {
        _health -= amount;
    } else {
        _health = 0;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energy == 0) {
        cout << "\033[2mClapTrap\033[0m " << _name
             << " has no energy to heal!" << endl;
        return ;
    }
    cout << "\033[2mClapTrap\033[0m " << _name << " heals " 
         << amount << " HP!" << endl;
    _health += amount;
    _energy--;
}

void ClapTrap::printStats(void) const {
    clog << "\033[2mClapTrap " << _name << " stats: h(" << _health
         << "), e(" << _energy << "), d(" << _damage << ")\033[0m" << endl;
}
