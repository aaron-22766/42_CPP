/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:54:02 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/09 15:00:59 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

using std::cout;
using std::clog;
using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap() {
    clog << "\033[2mDiamondTrap default constructor called\033[0m" << endl;
    _health = FragTrap::_health;//100
    ScavTrap scav;
    _energy = scav.getEnergy();//50
    _damage = FragTrap::_damage;//30
}

DiamondTrap::DiamondTrap(std::string name) :
    ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name) {
    clog << "\033[2mDiamondTrap name constructor called\033[0m" << endl;
    _health = FragTrap::_health;//100
    // _energy = ScavTrap::getEnergy();
    ScavTrap scav;
    _energy = scav.getEnergy();//50
    _damage = FragTrap::_damage;//30
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) :
    ClapTrap(other), ScavTrap(other), FragTrap(other) {
    clog << "\033[2mDiamondTrap copy constructor called\033[0m" << endl;
    *this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    clog << "\033[2mDiamondTrap copy assignment operator called\033[0m" << endl;
    _name = other._name;
    _health = other._health;
    _energy = other._energy;
    _damage = other._damage;
    return (*this);
}

DiamondTrap::~DiamondTrap(void) {
    clog << "\033[2mDiamondTrap destructor called\033[0m" << endl;
}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

void DiamondTrap::whoAmI(void) const {
    cout << "\033[2mDiamondTrap\033[0m " << _name
         << " goes by the alias " << ClapTrap::_name << "." << endl;
}

void DiamondTrap::printStats(void) const {
    clog << "\033[2mDiamondTrap " << _name << " stats: h(" << _health
         << "), e(" << _energy << "), d(" << _damage << ")\033[0m" << endl;
}
