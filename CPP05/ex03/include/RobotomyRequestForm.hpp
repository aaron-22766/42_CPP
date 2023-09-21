/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 08:21:48 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/21 10:19:47 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

/* ************************************************************************** */
/*                                  INCLUDE                                   */
/* ************************************************************************** */

# include "AForm.hpp"

/* ************************************************************************** */
/*                                   CLASS                                    */
/* ************************************************************************** */

class RobotomyRequestForm : public AForm {

public:

    RobotomyRequestForm(void);
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    ~RobotomyRequestForm(void);

    void execute(const Bureaucrat &executor) const;
    
private:

    std::string _target;

};

#endif