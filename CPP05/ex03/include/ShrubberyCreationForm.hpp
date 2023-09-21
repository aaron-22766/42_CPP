/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 08:22:11 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/21 10:19:44 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

/* ************************************************************************** */
/*                                  INCLUDE                                   */
/* ************************************************************************** */

# include "AForm.hpp"

/* ************************************************************************** */
/*                                   CLASS                                    */
/* ************************************************************************** */

class ShrubberyCreationForm : public AForm {

public:

    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm(void);

    void execute(const Bureaucrat &executor) const;
    
    class FileOpenFailException : public std::exception {
    public:
        virtual const char *what(void) const throw();
    };

private:

    std::string _target;

};

#endif