/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:47:00 by arabenst          #+#    #+#             */
/*   Updated: 2023/11/22 17:54:57 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

/* ************************************************************************** */
/*                                  INCLUDE                                   */
/* ************************************************************************** */

# include <vector>
# include <iterator>
# include <algorithm>
# include <exception>
# include <cmath>

/* ************************************************************************** */
/*                                   CLASS                                    */
/* ************************************************************************** */

class Span {

public:

    Span(void);
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span(void);

    void addNumber(int num);
    
    unsigned int shortestSpan(void);
    unsigned int longestSpan(void);
    
    template <typename InputIt>
    void addRange(const InputIt &first, const InputIt &last);

private:

    class SpanFullException : public std::exception {
    public:
        virtual const char *what(void) const throw();
    };
    
    class NoSpanFound : public std::exception {
    public:
        virtual const char *what(void) const throw();
    };

    std::vector<int> _numbers;
    unsigned int _maxSize;

};

# include "Span.tpp"

#endif