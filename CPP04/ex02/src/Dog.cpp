/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:12:46 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/13 10:04:41 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

using std::cout;
using std::clog;
using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

Dog::Dog(void) : AAnimal() {
    clog << "\033[2mDog default constructor called\033[0m" << endl;
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog &other) {
    clog << "\033[2mDog copy constructor called\033[0m" << endl;
    brain = new Brain();
    *this = other;
}

Dog &Dog::operator=(const Dog &other) {
    clog << "\033[2mDog copy assignment operator called\033[0m" << endl;
    type = other.type;
    *brain = *other.brain;
    return (*this);
}

Dog::~Dog(void) {
    clog << "\033[2mDog destructor called\033[0m" << endl;
    delete brain;
}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

void Dog::makeSound(void) const {
    cout << "woof" << endl;
}

bool Dog::setIdea(int index, std::string idea) {
    if (index < 0 || index > NB_IDEAS - 1) {
        return (false);
    }
    brain->ideas[index] = idea;
    return (true);
}

std::string Dog::getIdea(int index) {
    if (index < 0 || index > NB_IDEAS - 1) {
        return ("");
    }
    return (brain->ideas[index]);
}
