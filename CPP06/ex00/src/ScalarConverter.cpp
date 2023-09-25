/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:09:05 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/25 08:23:27 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

/* ************************************************************************** */
/*                          PRIVATE: SPECIAL METHODS                          */
/* ************************************************************************** */

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    static_cast<void>(other);
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    static_cast<void>(other);
    return (*this);
}

ScalarConverter::~ScalarConverter(void) {}

/* ************************************************************************** */
/*                             PUBLIC: EXCEPTIONS                             */
/* ************************************************************************** */

const char *ScalarConverter::InvalidInputException::what(void) const throw() {
    return ("Invalid Input");
}

/* ************************************************************************** */
/*                         PRIVATE: STATIC VARIABLES                          */
/* ************************************************************************** */

std::string ScalarConverter::_s;
int8_t ScalarConverter::_type;
double ScalarConverter::_value;
