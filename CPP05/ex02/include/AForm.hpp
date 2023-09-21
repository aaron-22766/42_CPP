/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:54:45 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/21 10:19:55 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

/* ************************************************************************** */
/*                                  INCLUDE                                   */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

/* ************************************************************************** */
/*                                   CLASS                                    */
/* ************************************************************************** */

class AForm {

public:

    AForm(void);
    AForm(std::string name, int signGrade, int executeGrade);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm(void);
    
    std::string getName(void) const;
    bool isSigned(void) const;
    int getSignGrade(void) const;
    int getExecuteGrade(void) const;
    
    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(const Bureaucrat &executor) const = 0;

    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what(void) const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what(void) const throw();
    };
    
    class FormUnsignedException : public std::exception {
    public:
        virtual const char *what(void) const throw();
    };

protected:

    void checkRequirements(const Bureaucrat &bureaucrat) const;

private:

    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _executeGrade;

};

std::ostream &operator<<(std::ostream &os, const AForm &rhs);

#endif