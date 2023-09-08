/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:27:52 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/08 10:33:38 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using std::endl;

int	main(void) {
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "Address of string:\t\t" << &string << endl
              << "Address held by stringPTR:\t" << stringPTR << endl
              << "Address held by stringREF:\t" << &stringREF << endl
              << endl
              << "Value of string:\t\t" << string << endl
              << "Value pointed to by stringPTR:\t" << *stringPTR << endl
              << "Value pointed to by stringREF:\t" << stringREF << endl;
	return (EXIT_SUCCESS);
}
