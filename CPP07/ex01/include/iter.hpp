/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:53:12 by arabenst          #+#    #+#             */
/*   Updated: 2023/10/05 10:33:28 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

/* ************************************************************************** */
/*                             TEMPLATE FUNCTIONS                             */
/* ************************************************************************** */

template <typename T>
void print(const T &data);

template <typename T>
void iter(const T *array, const size_t len, void (*f)(const T &));

#endif