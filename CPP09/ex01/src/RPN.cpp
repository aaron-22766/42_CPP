/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:36:27 by arabenst          #+#    #+#             */
/*   Updated: 2023/11/23 11:50:06 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

static void tryOperation(std::stack<int> &values, char c) {
    size_t op = std::string(OPERATORS).find(c);
    if (op == std::string::npos) {
        throw std::runtime_error("invalid character");
    } else if (values.size() < 2) {
        throw std::runtime_error("invalid notation");
    }
    int b = values.top();
    values.pop();
    int a = values.top();
    values.pop();
    switch (op) {
        case ADD:
            values.push(a + b);
            return ;
        case SUBTRACT:
            values.push(a - b);
            return ;
        case MULTIPLY:
            values.push(a * b);
            return ;
        case DIVIDE:
            values.push(a / b);
            return ;
    }
}

int rpn(const std::string input) {
    std::stack<int> values;
    for (size_t i = 0; i < input.length(); ++i) {
        size_t temp = i;
        i = input.find_first_not_of(WHITESPACES, i);
        if (i == std::string::npos) {
            break ;
        } else if (temp && i == temp) {
            throw std::runtime_error("expected space separator");
        }
        if (std::isdigit(input[i])) {
            values.push(input[i] - '0');
        } else {
            tryOperation(values, input[i]);
        }
    }
    if (values.size() != 1) {
        throw std::runtime_error("invalid notation");
    }
    return (values.top());
}
