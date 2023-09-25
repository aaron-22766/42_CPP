/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:32:16 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/25 08:48:29 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Data.hpp"

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

Data::Data(void) : proof("empty") {}

Data::Data(const Data &other) {
    *this = other;
}

Data &Data::operator=(const Data &other) {
    proof = other.proof;
    return (*this);
}

Data::~Data(void) {}
