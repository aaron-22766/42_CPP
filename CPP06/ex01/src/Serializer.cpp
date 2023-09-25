/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:29:44 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/25 08:48:00 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

uintptr_t Serializer::serialize(Data *ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data *>(raw));
}

/* ************************************************************************** */
/*                          PRIVATE: SPECIAL METHODS                          */
/* ************************************************************************** */

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer &other) {
    static_cast<void>(other);
}

Serializer &Serializer::operator=(const Serializer &other) {
    static_cast<void>(other);
    return (*this);
}

Serializer::~Serializer(void) {}
