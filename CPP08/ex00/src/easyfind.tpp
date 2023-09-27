/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:38:02 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/26 12:06:00 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &haystack, const int &needle) {
    return (std::find(haystack.begin(), haystack.end(), needle));
}
