/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:12:27 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/13 10:04:30 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

using std::cout;
using std::clog;
using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

Cat::Cat(void) : AAnimal() {
    clog << "\033[2mCat default constructor called\033[0m" << endl;
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat &other) {
    clog << "\033[2mCat copy constructor called\033[0m" << endl;
    brain = new Brain();
    *this = other;
}

Cat &Cat::operator=(const Cat &other) {
    clog << "\033[2mCat copy assignment operator called\033[0m" << endl;
    type = other.type;
    *brain = *other.brain;
    return (*this);
}

Cat::~Cat(void) {
    clog << "\033[2mCat destructor called\033[0m" << endl;
    delete brain;
}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

void Cat::makeSound(void) const {
    cout << "meow" << endl;
}

bool Cat::setIdea(int index, std::string idea) {
    if (index < 0 || index > NB_IDEAS - 1) {
        return (false);
    }
    brain->ideas[index] = idea;
    return (true);
}

std::string Cat::getIdea(int index) {
    if (index < 0 || index > NB_IDEAS - 1) {
        return ("");
    }
    return (brain->ideas[index]);
}
