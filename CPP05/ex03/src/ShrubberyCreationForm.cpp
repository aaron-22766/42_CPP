/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 08:23:38 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/22 12:41:33 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "../include/ShrubberyCreationForm.hpp"

using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm(void) :
    AForm("ShrubberyCreationForm", 145, 137), _target("No target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
    AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    _target = other._target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    checkRequirements(executor);
    std::ofstream file(_target + "_shrubbery", std::ios_base::app);
    if (file.is_open() == false) {
        throw ShrubberyCreationForm::FileOpenFailException();
    }
    file << "                           ┬▓▌─" << endl
    << "               .▌           *            ╫┌" << endl
    << "               ╨▌¬                      ╘╫╙" << endl
    << "                      τ   ▄    Φ   ⌐" << endl
    << "                      ▐⌐  *▌  ▌   ▐w" << endl
    << "     .▌             z  ▌▌* *▓█  *▌▓  µ            .▌." << endl
    << "     ╨█╙        ╥   ▌   ▀▄  ██  ▄▀   ▓   /        ╙█╨" << endl
    << "                 ▌  ╙▌╙▀ ╙▓,██╓▓*─▀╙▓M  ▌" << endl
    << "            ⌐Φ   *▄ ▐M     ████     ▐▄ ▐    &~" << endl
    << "         W_  ▐⌐   ▓▄Ñ  ╓▀▀▄*██ ▄▀▀µ  ╙▄▓   JW  ,4" << endl
    << "          ▓ ╒▀╨▀⌐X_▓▄  ╙  *▓██▓   M  ▄▀╓Ω╒▀╙▀─ ▌" << endl
    << ".▄▌╓      ╘▄▓    ┌▌ └▀Φ▄,  ▐██*  ╓▄&▀  ╫     █▐*      ╓▓▄." << endl
    << " *M        ╙█_  ╒▀╙     └▀▓▄██▄▓▀└     ╨▀⌐  ╓█Ñ        ▐" << endl
    << "         φ   ▀▌▄╬▄   _,╓,_ ▓██▌ _╓╓,_   ▄▄▄▌▀   Æ" << endl
    << "         ▐▌▄    └▓▓▀╙└  └╙▀▓██▓▀╙`  └╙▀▓▓└    ▄╫M" << endl
    << "       ─ ▐▌    ▄▀    ╓&▓▀▀▀▓██▓▀▀▀▌W,    ▀▄    ╫M ╒" << endl
    << "      ,▓▄,▀▄▄▄▀*    ▓* █   └██*   ▌ └▌    └▀▄▄▄▀╓æ▓," << endl
    << "      ╙   └╙█      ╫▓_  ▓   ██   ▌  _▓▌      █╙└   ▀" << endl
    << "            ╙*  τ▄▀        ╒██         ▀▄∩  τ╙" << endl
    << "                           J██─" << endl
    << "                           ▐██w" << endl
    << "                           ▐██M" << endl
    << "                           ╟██M" << endl
    << "                           ╫██▌" << endl
    << "                           ╫██▌" << endl
    << "                           ╫██▌" << endl
    << "                           ▓██▌" << endl
    << "                           ▓██▌" << endl
    << "                          ╓████_" << endl
    << "                         ▄██████▄" << endl
    << "                 ,▄▄▄▄▄▓████▓▓████▓▌▄▄▄▄," << endl
    << "              ┌▌╙  ▄Ñ  ▐╨        ╙W  ╟▄  ╙▀" << endl
    << "              └                          └" << endl;
    file.close();
}

/* ************************************************************************** */
/*                             PUBLIC: EXCEPTIONS                             */
/* ************************************************************************** */

const char *ShrubberyCreationForm::FileOpenFailException::what(void) const throw() {
    return ("failed to open file");
}
