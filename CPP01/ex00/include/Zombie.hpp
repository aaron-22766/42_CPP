/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:29:47 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/06 13:07:24 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <cstdlib>

/* ************************************************************************** */
/*                                   CLASS                                    */
/* ************************************************************************** */

class Zombie {

public:

    Zombie(std::string name);
    ~Zombie(void);

    void announce(void);

private:

    std::string	name;

};

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif