/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:47:26 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/06 16:09:13 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

HumanB::~HumanB(void) {}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

void HumanB::attack(void) const {
    std::cout << name << " attacks with their ";
    if (!weapon) {
	    std::cout << "fists because they don't have a weapon" << std::endl;
    } else {
	    std::cout << weapon->getType() << std::endl;
    }
}
