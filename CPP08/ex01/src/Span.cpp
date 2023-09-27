/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:47:29 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/27 11:25:36 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

Span::Span(void) : _maxSize(-1) {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span &other) {
    *this = other;
}

Span &Span::operator=(const Span &other) {
    _maxSize = other._maxSize;
    _span.clear();
    std::copy(other._span.begin(), other._span.end(), _span.begin());
    return (*this);
}

Span::~Span(void) {}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

void Span::addNumber(int num) {
    if (_span.size() == _maxSize) {
        throw Span::SpanFullException();
    } else {
        _span.push_back(num);
    }
}

unsigned int Span::shortestSpan(void) {
    if (_span.size() < 2) {
        throw Span::NoSpanFound();
    }
    unsigned int shortest = -1;
    for (Span::Iter it1 = _span.begin(); it1 != --_span.end(); it1++) {
        for (Span::Iter it2 = (it1 + 1); it2 != _span.end(); it2++) {
            unsigned int dist = Span::distance(it1, it2);
            if (dist < shortest) {
                shortest = dist;
            }
        }
    }
    return (shortest);
}

unsigned int Span::longestSpan(void) {
    if (_span.size() < 2) {
        throw Span::NoSpanFound();
    }
    return (Span::distance(std::max_element(_span.begin(), _span.end()),
                           std::min_element(_span.begin(), _span.end())));
}

/* ************************************************************************** */
/*                          PRIVATE: STATIC METHODS                           */
/* ************************************************************************** */

unsigned int Span::distance(const Span::Iter &a, const Span::Iter &b) {
    return (std::abs(*a - *b));
}

/* ************************************************************************** */
/*                            PRIVATE: EXCEPTIONS                             */
/* ************************************************************************** */

const char *Span::SpanFullException::what(void) const throw() {
    return ("span full");
}

const char *Span::NoSpanFound::what(void) const throw() {
    return ("no span found");
}
