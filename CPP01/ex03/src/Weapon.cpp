/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:42:32 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/08 10:47:22 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {}

Weapon::~Weapon(void) {}

const std::string &Weapon::getType(void) const {
	return (type);
}

void Weapon::setType(std::string type) {
	this->type = type;
}
