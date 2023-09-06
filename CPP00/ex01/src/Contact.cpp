/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:35:22 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/05 15:49:24 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

std::string	Contact::getFirstName(void) const {
	return (_firstName);
}

std::string	Contact::getLastName(void) const {
	return (_lastName);
}

std::string	Contact::getNickname(void) const {
	return (_nickname);
}

std::string	Contact::getPhoneNumber(void) const {
	return (_phoneNumber);
}

std::string	Contact::getDarkestSecret(void) const {
	return (_darkestSecret);
}

void	Contact::newContact(void) {
	_firstName = PhoneBook::promptForInput("first name");
	_lastName = PhoneBook::promptForInput("last name");
	_nickname = PhoneBook::promptForInput("nickname");
	_phoneNumber = PhoneBook::promptForInput("phone number");
	_darkestSecret = PhoneBook::promptForInput("darkest secret");
}

std::ostream	&operator<<(std::ostream &os, const Contact &contact) {
	os << "Contact:" << std::endl;
	os << "\tFirst Name:\t" << contact.getFirstName() << std::endl;
	os << "\tLast Name:\t" << contact.getLastName() << std::endl;
	os << "\tNickname:\t" << contact.getNickname() << std::endl;
	os << "\tPhone Number:\t" << contact.getPhoneNumber() << std::endl;
	os << "\tDarkest Secret:\t" << contact.getDarkestSecret() << std::endl;
	return (os);
}
