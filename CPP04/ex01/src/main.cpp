/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:56:23 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/13 09:58:08 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include "../include/Dog.hpp"

using std::cout;
using std::endl;

int main(void) {
    {
        const Animal *animals[10];
        
        for (int i = 0; i < 5; i++) {
            animals[i] = new Dog();
            cout << endl;
        }
        for (int i = 5; i < 10; i++) {
            animals[i] = new Cat();
            cout << endl;
        }
        for (int i = 0; i < 10; i++) {
            delete animals[i];
            cout << endl;
        }
    }
    cout << endl << endl;
    {
        Dog dog1;

        for (int i = 0; i < NB_IDEAS; i++) {
            dog1.setIdea(i, "1#" + std::to_string(i + 1));
        }
        for (int i = 0; i < NB_IDEAS; i++) {
            cout << dog1.getIdea(i) << " ";
        }
        cout << endl;
        
        Dog dog2(dog1);
        
        for (int i = 0; i < NB_IDEAS; i++) {
            dog2.setIdea(i, "2!" + std::to_string(i + 1));
        }
        for (int i = 0; i < NB_IDEAS; i++) {
            cout << dog2.getIdea(i) << " ";
        }
        cout << endl << endl << "Dog1's original ideas:" << endl << endl;
        for (int i = 0; i < NB_IDEAS; i++) {
            cout << dog1.getIdea(i) << " ";
        }
        cout << endl;
    }
    return (EXIT_SUCCESS);
}
