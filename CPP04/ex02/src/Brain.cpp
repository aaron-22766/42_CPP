/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:30:55 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/11 08:51:50 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

using std::cout;
using std::clog;
using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

Brain::Brain(void) {
    clog << "\033[2mBrain default constructor called\033[0m" << endl;
}

Brain::Brain(const Brain &other) {
    clog << "\033[2mBrain copy constructor called\033[0m" << endl;
    *this = other;
}

Brain &Brain::operator=(const Brain &other) {
    clog << "\033[2mBrain copy assignment operator called\033[0m" << endl;
    for (int i = 0; i < NB_IDEAS; i++) {
        ideas[i] = other.ideas[i];
    }
    return (*this);
}

Brain::~Brain(void) {
    clog << "\033[2mBrain destructor called\033[0m" << endl;
}
