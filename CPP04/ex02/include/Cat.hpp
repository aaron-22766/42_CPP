/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:13:19 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/13 10:03:56 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

/* ************************************************************************** */
/*                                  INCLUDE                                   */
/* ************************************************************************** */

# include "AAnimal.hpp"
# include "Brain.hpp"

/* ************************************************************************** */
/*                                   CLASS                                    */
/* ************************************************************************** */

class Cat : public AAnimal {

public:

    Cat(void);
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    ~Cat(void);

    void makeSound(void) const;
    bool setIdea(int index, std::string idea);
    std::string getIdea(int index);

private:

    Brain *brain;

};

#endif