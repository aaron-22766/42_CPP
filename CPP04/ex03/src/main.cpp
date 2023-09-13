/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:52:58 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/13 10:19:22 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"
#include "../include/Character.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"

int main(void) {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    std::cout << me->getName() << std::endl;
    AMateria* tmp;
    tmp = src->createMateria("ice");
    std::cout << tmp->getType() << std::endl;
    me->equip(tmp);
    tmp = src->createMateria("cure");
    std::cout << tmp->getType() << std::endl;
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    std::cout << bob->getName() << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;
    return (EXIT_SUCCESS);
}
