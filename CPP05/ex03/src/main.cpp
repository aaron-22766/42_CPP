/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:53:56 by arabenst          #+#    #+#             */
/*   Updated: 2023/11/16 15:30:40 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

using std::cout;
using std::endl;

int main(void) {
    {
        Intern intern;
        intern.makeForm("garbage", "Bender");
    }
    cout << endl;
    {
        Bureaucrat ben("Ben", 17);
        Intern intern;
        AForm* form;
        form = intern.makeForm("robotomy request", "Bender");
        ben.executeForm(*form);
        delete form;
    }
    cout << endl;
    {
        Bureaucrat ben("Ben", 17);
        Intern intern;
        AForm* form;
        form = intern.makeForm("shrubbery creation", "Bender");
        ben.signForm(*form);
        ben.executeForm(*form);
        delete form;
    }
    cout << endl;
    {
        Bureaucrat ben("Ben", 17);
        Intern intern;
        AForm* form;
        form = intern.makeForm("robotomy request", "Bender");
        ben.signForm(*form);
        ben.executeForm(*form);
        delete form;
    }
    cout << endl;
    {
        Bureaucrat ben("Ben", 17);
        Intern intern;
        AForm* form;
        form = intern.makeForm("presidential pardon", "Bender");
        ben.signForm(*form);
        ben.executeForm(*form);
        delete form;
    }
}
