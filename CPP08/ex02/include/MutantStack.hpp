/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:40:04 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/27 16:43:10 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

/* ************************************************************************** */
/*                                  INCLUDE                                   */
/* ************************************************************************** */

# include <stack>
# include <deque>
# include <iterator>

/* ************************************************************************** */
/*                                   CLASS                                    */
/* ************************************************************************** */

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

public:

    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    
    iterator begin(void);
    const_iterator begin(void) const;
    iterator end(void);
    const_iterator end(void) const;

};

#include "../src/MutantStack.tpp"

#endif