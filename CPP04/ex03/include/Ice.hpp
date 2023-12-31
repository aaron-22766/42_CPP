/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:51:02 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/12 11:16:54 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

/* ************************************************************************** */
/*                                  INCLUDE                                   */
/* ************************************************************************** */

# include "AMateria.hpp"

/* ************************************************************************** */
/*                                   CLASS                                    */
/* ************************************************************************** */

class Ice : public AMateria {

public:

    Ice(void);
    Ice(const Ice &other);
    Ice &operator=(const Ice &other);
    ~Ice(void);
    
    AMateria *clone(void) const;
    void use(ICharacter &target);

private:


};

#endif