/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:15:02 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/13 10:04:02 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

/* ************************************************************************** */
/*                                  INCLUDE                                   */
/* ************************************************************************** */

# include "AAnimal.hpp"
# include "Brain.hpp"

/* ************************************************************************** */
/*                                   CLASS                                    */
/* ************************************************************************** */

class Dog : public AAnimal {

public:

    Dog(void);
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    ~Dog(void);

    void makeSound(void) const;
    bool setIdea(int index, std::string idea);
    std::string getIdea(int index);
    
private:

    Brain *brain;

};

#endif