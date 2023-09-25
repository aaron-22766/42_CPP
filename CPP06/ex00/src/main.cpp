/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:11:21 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/25 08:23:14 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

using std::cerr;
using std::endl;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Wrong number of arguments! Expected: 1" << endl;
        return (EXIT_FAILURE);
    }
    try {
        ScalarConverter::convert(argv[1]);
    } catch (std::exception &e) {
        cerr << "Conversion failed: " << e.what() << endl;
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}
