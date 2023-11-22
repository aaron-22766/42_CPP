/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:47:29 by arabenst          #+#    #+#             */
/*   Updated: 2023/11/22 18:09:52 by arabenst         ###   ########.fr       */
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
    _numbers.clear();
    std::copy(other._numbers.begin(), other._numbers.end(), _numbers.begin());
    return (*this);
}

Span::~Span(void) {}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

void Span::addNumber(int num) {
    if (_numbers.size() == _maxSize) {
        throw Span::SpanFullException();
    } else {
        _numbers.push_back(num);
    }
}

unsigned int Span::shortestSpan(void) {
    if (_numbers.size() < 2) {
        throw Span::NoSpanFound();
    }

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    
    unsigned int shortest = -1;
    unsigned int tempSpan;

    for (size_t i = 1; i < sorted.size(); ++i) {
        tempSpan = sorted[i] - sorted[i - 1];
        if (tempSpan < shortest) {
            shortest = tempSpan;
        }
    }
    return (shortest);
}

unsigned int Span::longestSpan(void) {
    if (_numbers.size() < 2) {
        throw Span::NoSpanFound();
    }
    return (*std::max_element(_numbers.begin(), _numbers.end())
            - *std::min_element(_numbers.begin(), _numbers.end()));
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
