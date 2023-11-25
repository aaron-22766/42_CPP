/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:36:20 by arabenst          #+#    #+#             */
/*   Updated: 2023/11/23 11:38:45 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"
#include <cstdlib>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Error: wrong number of arguments" << std::endl;
        return (EXIT_FAILURE);
    }
    try {
        std::cout << rpn(argv[1]) << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}
