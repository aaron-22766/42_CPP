/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:40:49 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/26 08:18:38 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

/* ************************************************************************** */
/*                                  INCLUDE                                   */
/* ************************************************************************** */

# include <exception>

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

# include "../src/Array.tpp"

#endif