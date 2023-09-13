/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:52:24 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/13 10:31:09 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"

using std::cout;
using std::clog;
using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

MateriaSource::MateriaSource(void) : _memory() {
    clog << "\033[2mMateriaSource default constructor called\033[0m" << endl;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
    clog << "\033[2mMateriaSource copy constructor called\033[0m" << endl;
    *this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    clog << "\033[2mMateriaSource copy assignment operator called\033[0m" << endl;
    int i = 0;
    while (i < SLOTS && _memory[i]) {
        delete _memory[i];
        _memory[i++] = NULL;
    }
    i = 0;
    while (i < SLOTS && other._memory[i]) {
        _memory[i] = other._memory[i]->clone();
        i++;
    }
    return (*this);
}

MateriaSource::~MateriaSource(void) {
    clog << "\033[2mMateriaSource destructor called\033[0m" << endl;
    for (int i = 0; i < SLOTS; i++) {
        delete _memory[i];
    }
}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

void MateriaSource::learnMateria(AMateria *m) {
    int i = 0;
    while (i < SLOTS && _memory[i]) {
        i++;
    }
    if (i < SLOTS) {
        _memory[i] = m;
    }
}

AMateria *MateriaSource::createMateria(const std::string &type) {
    int i = 0;
    while (i < SLOTS && _memory[i]) {
        if (_memory[i]->getType() == type) {
            return (_memory[i]->clone());
        }
        i++;
    }
    return (0);
}
