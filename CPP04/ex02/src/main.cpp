/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:56:23 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/13 10:08:57 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include "../include/Dog.hpp"

using std::cout;
using std::endl;

int main(void) {
    {
        const AAnimal *animals[2];
        
        animals[0] = new Dog();
        animals[1] = new Cat();
        animals[0]->makeSound();
        animals[1]->makeSound();
        delete animals[0];
        delete animals[1];
    }
    cout << endl;
    {
        Dog dog1;

        dog1.setIdea(0, "Dog1 Idea");
        cout << dog1.getIdea(0) << endl;
        
        Dog dog2(dog1);
        
        dog2.setIdea(0, "Dog2 different Idea");
        cout << dog2.getIdea(0) << endl;
        cout << dog1.getIdea(0) << endl;
    }
    {
        // AAnimal animal;
    }
    return (EXIT_SUCCESS);
}
