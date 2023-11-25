/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:36:36 by arabenst          #+#    #+#             */
/*   Updated: 2023/11/25 14:40:24 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"
#include <cstdlib>

int main(int argc, char *argv[]) {
    try {
        PmergeMe(argc - 1, argv + 1);
    } catch (const std::exception &e) {
        std::cerr << "Error: " << std::endl << e.what() << std::endl;
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}
