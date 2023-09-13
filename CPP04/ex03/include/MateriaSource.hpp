/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:50:05 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/12 13:12:25 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

/* ************************************************************************** */
/*                                  INCLUDE                                   */
/* ************************************************************************** */

# include "IMateriaSource.hpp"

/* ************************************************************************** */
/*                                  DEFINES                                   */
/* ************************************************************************** */

# define SLOTS 4

/* ************************************************************************** */
/*                                   CLASS                                    */
/* ************************************************************************** */

class MateriaSource : public IMateriaSource {

public:

    MateriaSource(void);
    MateriaSource(const MateriaSource &other);
    MateriaSource &operator=(const MateriaSource &other);
    ~MateriaSource(void);
    
    void learnMateria(AMateria *m);
    AMateria *createMateria(const std::string &type);

private:

    AMateria *_memory[SLOTS];

};

#endif