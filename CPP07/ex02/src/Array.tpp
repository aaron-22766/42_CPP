/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:41:11 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/25 14:02:53 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

template <typename T>
Array<T>::Array(void) : _size(0) {
    _array = NULL;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n) {
    _array = new T[_size];
}

template <typename T>
Array<T>::Array(const Array &other) : _size(other._size) {
    _array = new T[_size];
    for (unsigned int i = 0; i < _size; i++) {
        _array[i] = other._array[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
    delete[] _array;
    _size = other._size;
    _array = new T[_size];
    for (unsigned int i = 0; i < _size; i++) {
        _array[i] = other._array[i];
    }
    return (*this);
}

template <typename T>
Array<T>::~Array(void) {
    delete[] _array;
}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

template <typename T>
unsigned int Array<T>::size(void) const {
    return (_size);
}

/* ************************************************************************** */
/*                              PUBLIC: OVERLOAD                              */
/* ************************************************************************** */

template <typename T>
T &Array<T>::operator[](unsigned int index) {
    if (index < _size) {
        return (_array[index]);
    } else {
        throw Array<T>::OutOfBoundsException();
    }
}

/* ************************************************************************** */
/*                             PUBLIC: EXCEPTIONS                             */
/* ************************************************************************** */

template <typename T>
const char *Array<T>::OutOfBoundsException::what(void) const throw() {
    return ("index out of bounds");
}
