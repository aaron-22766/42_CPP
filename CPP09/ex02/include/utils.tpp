/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:06:07 by arabenst          #+#    #+#             */
/*   Updated: 2023/11/25 15:24:55 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
bool isSorted(T &cont) {
    int prev = -1;
    for (typename T::iterator it = cont.begin(); it != cont.end(); ++it) {
        if (prev > *it) {
            return (false);
        }
        prev = *it;
    }
    return (true);
}
