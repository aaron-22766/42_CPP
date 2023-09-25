/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:28:07 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/25 10:30:24 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctime>
#include <sys/time.h>
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

using std::cout;
using std::endl;

Base *generate(void) {
    switch (std::rand() % 3) {
        case 0:
            return (new A());
        case 1:
            return (new B());
        case 2:
            return (new C());
    }
    return (NULL);
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p)) {
        cout << "A";
    } else if (dynamic_cast<B *>(p)) {
        cout << "B";
    } else {
        cout << "C";
    }
}

void identify(Base &p) {
    try {
        static_cast<void>(dynamic_cast<A&>(p));
        cout << "A";
    } catch (...) {
        try {
            static_cast<void>(dynamic_cast<B&>(p));
            cout << "B";
        } catch (...) {
            cout << "C";
        }
    }
}

int main(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
	std::srand(tv.tv_usec);
    for (int i = 0; i < 10; i++) {
        Base *ptr = generate();
        identify(ptr);
        identify(*ptr);
        cout << endl;
        delete ptr;
    }
    return (EXIT_SUCCESS);
}
