/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:41:11 by arabenst          #+#    #+#             */
/*   Updated: 2023/10/05 13:25:10 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/* ************************************************************************** */
/*                               TEMPLATE CLASS                               */
/* ************************************************************************** */

template <typename T>
class Array {

public:

    Array(void);
    Array(unsigned int n);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array(void);

    unsigned int size(void) const;
    
    T &operator[](unsigned int index);

    class OutOfBoundsException : public std::exception {
    public:
        virtual const char *what(void) const throw();
    };

private:

    T *_array;
    unsigned int _size;

};

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
    memcpy(_array, other._array, _size * sizeof(T));
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
    delete[] _array;
    _size = other._size;
    _array = new T[_size];
    memcpy(_array, other._array, _size * sizeof(T));
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
