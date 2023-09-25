/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:27:26 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/25 08:33:05 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

/* ************************************************************************** */
/*                                  INCLUDE                                   */
/* ************************************************************************** */

# include "Data.hpp"

/* ************************************************************************** */
/*                                   CLASS                                    */
/* ************************************************************************** */

class Serializer {

public:

    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);

private:

    Serializer(void);
    Serializer(const Serializer &other);
    Serializer &operator=(const Serializer &other);
    ~Serializer(void);

};

#endif