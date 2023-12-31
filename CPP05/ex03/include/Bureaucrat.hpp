/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:54:36 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/21 10:10:27 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

/* ************************************************************************** */
/*                                  INCLUDE                                   */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <exception>

/* ************************************************************************** */
/*                                  CLASSES                                   */
/* ************************************************************************** */

class AForm;

class Bureaucrat {

public:

    Bureaucrat(void);
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat(void);
    
    std::string getName(void) const;
    int getGrade(void) const;
    
    void incrementGrade(void);
    void decrementGrade(void);
    
    void signForm(AForm &form) const;
    void executeForm(const AForm &form) const;
    
    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what(void) const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what(void) const throw();
    };

private:

    const std::string _name;
    int _grade;

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs);

#endif