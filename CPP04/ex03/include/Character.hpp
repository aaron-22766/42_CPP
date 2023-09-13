/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:48:58 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/12 12:58:07 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

/* ************************************************************************** */
/*                                  INCLUDE                                   */
/* ************************************************************************** */

# include "ICharacter.hpp"

/* ************************************************************************** */
/*                                  DEFINES                                   */
/* ************************************************************************** */

# define SLOTS 4

/* ************************************************************************** */
/*                                   CLASS                                    */
/* ************************************************************************** */

class Character : public ICharacter {

public:

    Character(void);
    Character(const std::string name);
    Character(const Character &other);
    Character &operator=(const Character &other);
    ~Character(void);

    const std::string &getName(void) const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);

private:

    std::string _name;
    AMateria *_inventory[SLOTS];

};

#endif