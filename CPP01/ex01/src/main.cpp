/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:27:52 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/06 16:10:43 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

#define FOO_N 5
#define BAR_N 3

int	main(void) {
	Zombie *fooHorde = zombieHorde(FOO_N, "Foo");
	Zombie *barHorde = zombieHorde(BAR_N, "Bar");

	for (int i = 0; i < FOO_N; i++) {
		fooHorde[i].announce();
	}
    for (int i = 0; i < BAR_N; i++) {
		barHorde[i].announce();
	}
	delete[] fooHorde;
	delete[] barHorde;
	return (EXIT_SUCCESS);
}
