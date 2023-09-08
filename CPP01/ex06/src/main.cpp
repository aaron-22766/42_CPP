/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:27:52 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/08 11:04:36 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Error! Wrong number of arguments. Expected: 1" << std::endl;
		return (EXIT_FAILURE);
	}
    
	Harl harl;
    
	harl.complainFiltered(argv[1]);
	return (EXIT_SUCCESS);
}
