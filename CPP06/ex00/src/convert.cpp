/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:19:58 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/23 20:33:58 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

#define WHITESPACES " \n\t\r\f\v"

static std::string trim(std::string str) {
    str.erase(0, str.find_first_not_of(WHITESPACES));
    str.erase(str.find_last_not_of(WHITESPACES) + 1);
    return (str);
}

void ScalarConverter::convert(const std::string input) {
    if (input.length() == 0) {
        throw SC::InvalidInputException();
    }
    SC::_s = trim(input);
    SC::checkType();
    SC::readValue();
    SC::printChar();
    SC::printInt();
    SC::printFloat();
    SC::printDouble();
}
