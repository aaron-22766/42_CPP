/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:33:05 by arabenst          #+#    #+#             */
/*   Updated: 2023/10/05 10:28:59 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

/* ************************************************************************** */
/*                             TEMPLATE FUNCTIONS                             */
/* ************************************************************************** */

template <typename T>
void swap(T &a, T &b);

template <typename T>
const T &min(const T &a, const T &b);

template <typename T>
const T &max(const T &a, const T &b);

#endif