/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:54:02 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/09 13:39:09 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

using std::cout;
using std::clog;
using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

ScavTrap::ScavTrap(void) : ClapTrap() {
    clog << "\033[2mScavTrap default constructor called\033[0m" << endl;
    _health = 100;
    _energy = 50;
    _damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    clog << "\033[2mScavTrap name constructor called\033[0m" << endl;
    _health = 100;
    _energy = 50;
    _damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) {
    clog << "\033[2mScavTrap copy constructor called\033[0m" << endl;
    *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    clog << "\033[2mScavTrap copy assignment operator called\033[0m" << endl;
    _name = other._name;
    _health = other._health;
    _energy = other._energy;
    _damage = other._damage;
    return (*this);
}

ScavTrap::~ScavTrap(void) {
    clog << "\033[2mScavTrap destructor called\033[0m" << endl;
}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

void ScavTrap::attack(const std::string &target) {
    if (_health && _energy) {
        cout << "\033[2mScavTrap\033[0m " << _name << " attacks " << target
             << " causing " << _damage << " points of damage!" << endl;
        _energy--;
    } else if (_health == 0) {
        cout << "\033[2mScavTrap\033[0m " << _name
             << " is already dead!" << endl;
    } else if (_energy == 0) {
        cout << "\033[2mScavTrap\033[0m " << _name
             << " has no energy to attack!" << endl;
    }
}

void ScavTrap::guardGate(void) const {
    cout << "\033[2mScavTrap\033[0m " << _name
         << " guards the gates to Minas Tirith now." << endl;
}

void ScavTrap::printStats(void) const {
    clog << "\033[2mScavTrap " << _name << " stats: h(" << _health
         << "), e(" << _energy << "), d(" << _damage << ")\033[0m" << endl;
}
