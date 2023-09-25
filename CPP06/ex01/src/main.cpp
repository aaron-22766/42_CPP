/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:33:17 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/25 08:51:01 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"
#include <iostream>

int main(void) {
    Data *ptr = new Data();
    std::cout << ptr->proof << std::endl;
    
    uintptr_t ser = Serializer::serialize(ptr);
    Data *des = Serializer::deserialize(ser);

    ptr->proof = "Serialization successfull!";
    std::cout << des->proof << std::endl;
    delete ptr;
    return (EXIT_SUCCESS);
}
