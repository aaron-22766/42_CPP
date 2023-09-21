/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:54:45 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/21 09:36:26 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

/* ************************************************************************** */
/*                                  INCLUDE                                   */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

/* ************************************************************************** */
/*                                   CLASS                                    */
/* ************************************************************************** */

class Form {

public:

    Form(void);
    Form(std::string name, int signGrade, int executeGrade);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form(void);
    
    std::string getName(void) const;
    bool isSigned(void) const;
    int getSignGrade(void) const;
    int getExecuteGrade(void) const;
    
    void beSigned(const Bureaucrat &bureaucrat);

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
    bool _isSigned;
    const int _signGrade;
    const int _executeGrade;

};

std::ostream &operator<<(std::ostream &os, const Form &rhs);

#endif