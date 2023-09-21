/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 08:20:41 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/21 10:19:49 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

/* ************************************************************************** */
/*                                  INCLUDE                                   */
/* ************************************************************************** */

# include "AForm.hpp"

/* ************************************************************************** */
/*                                   CLASS                                    */
/* ************************************************************************** */

class PresidentialPardonForm : public AForm {

public:

    PresidentialPardonForm(void);
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    ~PresidentialPardonForm(void);
    
    void execute(const Bureaucrat &executor) const;

private:

    std::string _target;

};

#endif