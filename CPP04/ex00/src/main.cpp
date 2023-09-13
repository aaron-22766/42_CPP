/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:56:23 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/09 15:38:51 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"

using std::cout;
using std::endl;

int main(void) {
    {
        const Animal* meta = new Animal();
        const Animal* i = new Cat();
        const Animal* j = new Dog();
        cout << "What does the " << meta->getType() << " say?" << endl;
        meta->makeSound();
        cout << "What does the " << i->getType() << " say?" << endl;
        i->makeSound();
        cout << "What does the " << j->getType() << " say?" << endl;
        j->makeSound();

        delete meta;
        delete i;
        delete j;
    }
    cout << endl;
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();
        cout << "What does the " << meta->getType() << " say?" << endl;
        meta->makeSound();
        cout << "What does the " << i->getType() << " say?" << endl;
        i->makeSound();

        delete meta;
        delete i;
    }
    return (EXIT_SUCCESS);
}
