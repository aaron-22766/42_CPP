/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:41:52 by arabenst          #+#    #+#             */
/*   Updated: 2023/11/22 18:43:35 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/* ************************************************************************** */
/*                                   CLASS                                    */
/* ************************************************************************** */

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

public:

    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    
    iterator begin(void);
    iterator end(void);
    const_iterator begin(void) const;
    const_iterator end(void) const;

};

/* ************************************************************************** */
/*                         PUBLIC: TEMPLATE FUNCTIONS                         */
/* ************************************************************************** */

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator
    MutantStack<T, Container>::begin(void) {
    return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator
    MutantStack<T, Container>::end(void) {
    return (this->c.end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator
    MutantStack<T, Container>::begin(void) const {
    return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator
    MutantStack<T, Container>::end(void) const {
    return (this->c.end());
}
