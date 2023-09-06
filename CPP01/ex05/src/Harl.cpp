/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:42:32 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/06 16:16:38 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

using std::cout;
using std::clog;
using std::endl;

Harl::Harl(void) {}

Harl::~Harl(void) {}

int Harl::getLevelIndex(std::string level) {
	std::string	level_names[NB_LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < NB_LEVELS; i++) {
		if (level == level_names[i]) {
            return (i);
		}
	}
    return (-1);
}

void Harl::complain(std::string level) {
    void (Harl::*complain[NB_LEVELS])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int levelIndex = Harl::getLevelIndex(level);

    if (levelIndex < 0) {
        std::cerr << "Invalid complain level!" << endl;
    } else {
        (this->*complain[levelIndex])();
    }
}

void Harl::debug(void) {
    clog << "\033[2m[ DEBUG ]\033[0m" << endl;
	cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << endl << endl;
}

void Harl::info(void) {
    clog << "\033[2m[ INFO ]\033[0m" << endl;
	cout << "I cannot believe adding extra bacon costs more money." << endl << "You didn’t put enough bacon in my burger!" << endl << "If you did, I wouldn’t be asking for more!" << endl << endl;
}

void Harl::warning(void) {
    clog << "\033[2m[ WARNING ]\033[0m" << endl;
	cout << "I think I deserve to have some extra bacon for free." << endl << "I’ve been coming for years whereas you started working here since last month." << endl << endl;
}

void Harl::error(void) {
    clog << "\033[2m[ ERROR ]\033[0m" << endl;
	cout << "This is unacceptable! I want to speak to the manager now." << endl << endl;
}
