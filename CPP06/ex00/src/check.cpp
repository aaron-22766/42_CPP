/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:19:55 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/23 20:35:29 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

static bool isChar(const std::string &str) {
    return (str.length() == 0 || (str.length() == 1 && !std::isdigit(str[0])));
}

static bool isSpecial(const std::string &str) {
    if (!str.compare(0, 3, "nan") && (str.length() == 3
        || (str.length() == 4 && str[3] == 'f'))) {
        return (true);
    }
    bool sign = (str[0] == '+' || str[0] == '-');
    if (!str.compare(sign, 3, "inf") && (str.length() - sign == 3
        || (str.length() - sign == 4 && str[3 + sign] == 'f'))) {
        return (true);
    }
    return (false);
}

static bool isDigitOrPeriod(const char c, bool &period) {
    if (std::isdigit(c)) {
        return (true);
    } else if (c == '.' && period == false) {
        period = true;
        return (true);
    }
    return (false);
}

static bool isNum(const std::string &str) {
    size_t i = (str[0] == '+' || str[0] == '-');
    bool period = false;

    if (std::isdigit(str[i]) == false && str[i] != '.') {
        return (false);
    }
    while (i < str.length() && isDigitOrPeriod(str[i], period)) {
        i++;
    }
    if (i && str[i] == 'f' && std::isdigit(str[i - 1])) {
        i++;
    }
    return (i == str.length());
}

void ScalarConverter::checkType(void) {
    if (isChar(SC::_s)) {
        SC::_type = T_CHAR;
    } else if (isSpecial(SC::_s)) {
        SC::_type = T_SPECIAL;
    } else if (isNum(SC::_s)) {
        SC::_type = T_NUM;
    } else {
        throw SC::InvalidInputException();
    }
}
