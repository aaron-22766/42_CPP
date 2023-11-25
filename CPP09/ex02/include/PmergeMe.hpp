/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:36:33 by arabenst          #+#    #+#             */
/*   Updated: 2023/11/25 15:25:22 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

/* ************************************************************************** */
/*                                  INCLUDE                                   */
/* ************************************************************************** */

# include <string>
# include <iomanip>
# include <iostream>
# include <sstream>
# include <stdexcept>
# include <sys/time.h>
# include <stdint.h>
# include <algorithm>
# include <iterator>
# include <vector>
# include <deque>
# include "utils.tpp"

/* ************************************************************************** */
/*                                  TYPEDEF                                   */
/* ************************************************************************** */

typedef std::vector<std::pair<int, int> > Pairs;

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

// PmergeMe.cpp
void PmergeMe(int argc, char *argv[]);

// Vector.cpp
void fj_sort(std::vector<int> &vec);

// Deque.cpp
void fj_sort(std::deque<int> &deq);

// Pairs.cpp
void sortEachPair(Pairs &pairs);
Pairs mergeSortPairs(Pairs &pairs);

// utils.tpp
template <typename T>
bool isSorted(T &cont);

#endif