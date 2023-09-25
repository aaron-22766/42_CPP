/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:19:50 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/23 20:29:26 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

void ScalarConverter::trimFloatExtension(void) {    
    if (SC::_type == T_CHAR) {
        return ;
    } else if (SC::_type == T_SPECIAL) {
        bool sign = (SC::_s[0] == '+' || SC::_s[0] == '-');
        if (!((!SC::_s.compare(0, 3, "nan") || !SC::_s.compare(sign, 3, "inf"))
            && SC::_s.length() - sign == 4 && SC::_s[3 + sign] == 'f')) {
            return ;
        }
    }
    size_t f = SC::_s.rfind('f');
    if (f != std::string::npos) {
        SC::_s.erase(f);
    }
}

void ScalarConverter::readValue(void) {
    trimFloatExtension();
    if (SC::_type == T_CHAR) {
        if (SC::_s.length()) {
            SC::_value = static_cast<double>(SC::_s[0]);
        } else {
            SC::_value = static_cast<double>(' ');
        }
    } else {
        std::istringstream ss(SC::_s);
        if (!(ss >> SC::_value)) {
            throw SC::InvalidInputException();
        }
    }
}
