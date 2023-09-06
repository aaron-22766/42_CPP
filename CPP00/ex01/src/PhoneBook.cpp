/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:50:09 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/05 16:19:19 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _contactsIndex(0), _contactsCount(0) {}

PhoneBook::~PhoneBook(void) {}

Contact	PhoneBook::getContact(int index) const {
	return (_contacts[index]);
}

int		PhoneBook::getContactsCount(void) const {
	return (_contactsCount);
}

void	PhoneBook::addContact(void) {
    _contacts[_contactsIndex].newContact();
    _contactsIndex = ++_contactsIndex % MAX_CONTACTS;
	std::cout << "Successfully added new contact";
    if (_contactsCount == MAX_CONTACTS) {
		std::cout << " (oldest was replaced)";
	}
	std::cout << std::endl;
    if (_contactsCount < MAX_CONTACTS) {
        _contactsCount++;
    }
}

static bool	isValidInt(const std::string &str) {
	for (size_t i = (str[0] == '+' || str[0] == '-'); i < str.length(); i++) {
		if (!std::isdigit(str[i])) {
			return (false);
		}
	}
	return (true);
}

void	PhoneBook::searchPhoneBook(void) const {
	std::string	input;
	int			index;

	std::cout << std::endl << *this << std::endl;
	if (_contactsCount == 0) {
		return ;
	}
	while (true) {
		input = promptForInput("contact index");
		index = std::atoi(input.c_str());
		if (isValidInt(input) && index >= 0 && index < _contactsCount) {
			std::cout << std::endl << _contacts[index] << std::endl;
			return ;
		}
		std::cout << "Please enter a number in range 0 - "
			<< (_contactsCount - 1) << std::endl;
	}
}

std::string	PhoneBook::promptForInput(std::string prompt) {
	std::string	input;

	while (true) {
		std::cout << "Enter " << prompt << ": ";
		if (!getline(std::cin, input)) {
			if (std::cin.eof()) {
				std::exit(EXIT_SUCCESS);
			}
			std::cerr << "Error while reading input!" << std::endl;
			std::exit(EXIT_FAILURE);
		}
		if (input.empty()) {
			std::cout << "Field cannot be empty!" << std::endl;
		} else {
			return (input);
		}
	}
}

static void	printColumn(std::string content) {
	if (content.length() > 10) {
		std::cout << content.substr(0, 9) << '.';
	} else {
		std::cout << std::setw(10) << content;
	}
	std::cout << '|';
}

std::ostream	&operator<<(std::ostream &os, const PhoneBook &phonebook) {
	os << std::string(45, '-') << std::endl << '|';
	printColumn("Index");
	printColumn("First Name");
	printColumn("Last Name");
	printColumn("Nickname");
	os << std::endl << '|' << std::string(43, '-') << '|' << std::endl;
	if (phonebook.getContactsCount() == 0) {
		os << '|' << std::string(16, ' ') << "NO CONTACTS"
			<< std::string(16, ' ') << '|' << std::endl;
	} else {
		for (int i = 0; i < phonebook.getContactsCount(); i++) {
			os << '|';
			printColumn(std::to_string(i));
			printColumn(phonebook.getContact(i).getFirstName());
			printColumn(phonebook.getContact(i).getLastName());
			printColumn(phonebook.getContact(i).getNickname());
			os << std::endl;
		}
	}
	os << std::string(45, '-') << std::endl;
	return (os);
}
