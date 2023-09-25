/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:19:25 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/25 08:20:32 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

void ScalarConverter::printChar(void) {
    cout << "char: ";
    if (SC::_type == T_SPECIAL
        || SC::_value < std::numeric_limits<char>::min()
        || SC::_value > std::numeric_limits<char>::max()) {
        cout << "impossible";
    } else if (SC::_value < 32 || SC::_value > 126) {
        cout << "Non displayable";
    } else {
        cout << "'" << static_cast<char>(SC::_value) << "'";
    }
    cout << endl;
}

void ScalarConverter::printInt(void) {
    cout << "int: ";
    if (SC::_type == T_SPECIAL
        || SC::_value < std::numeric_limits<int>::min()
        || SC::_value > std::numeric_limits<int>::max()) {
        cout << "impossible";
    } else {
        cout << static_cast<int>(SC::_value);
    }
    cout << endl;
}

void ScalarConverter::printFloat(void) {
    cout << "float: ";
    if (SC::_type != T_SPECIAL
        && (SC::_value < -std::numeric_limits<float>::max()
        || SC::_value > std::numeric_limits<float>::max())) {
        cout << "impossible";
    } else {
        cout << std::fixed << std::setprecision(1)
             << static_cast<float>(SC::_value) << "f";
    }        
    cout << endl;
}

void ScalarConverter::printDouble(void) {
    cout << "double: " << std::fixed << std::setprecision(1)
         << SC::_value << endl;
}
