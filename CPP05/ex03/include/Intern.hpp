/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:48:18 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/21 10:52:34 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

/* ************************************************************************** */
/*                                  INCLUDE                                   */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

/* ************************************************************************** */
/*                                   CLASS                                    */
/* ************************************************************************** */

class Intern {

public:

    Intern(void);
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern(void);

    AForm *makeForm(std::string formName, std::string formTarget) const;

};

#endif