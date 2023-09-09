/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:56:23 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/09 15:07:27 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

int main(void) {
    {
        DiamondTrap person1(DiamondTrap("Elendil"));
        person1.printStats();
        DiamondTrap person2(person1);
        person2.printStats();
        DiamondTrap person3 = person2;
        person3.printStats();
        DiamondTrap elendil;

        elendil = person3;
        elendil.printStats();
        elendil.attack("Sauron");
        elendil.printStats();
        elendil.takeDamage(100);
        elendil.printStats();
        elendil.takeDamage(100);
        elendil.printStats();
    }
    std::cout << std::endl;
    {
        DiamondTrap *aragorn = new DiamondTrap("Aragorn");
    
        aragorn->whoAmI();
        aragorn->guardGate();
        aragorn->printStats();
        aragorn->attack("Sauron");
        aragorn->printStats();
        aragorn->takeDamage(5);
        aragorn->printStats();
        aragorn->attack("Sauron");
        aragorn->printStats();
        aragorn->beRepaired(100);
        aragorn->printStats();
        aragorn->attack("Sauron");
        aragorn->printStats();
        aragorn->highFivesGuys();
        delete aragorn;
    }
    return (EXIT_SUCCESS);
}
