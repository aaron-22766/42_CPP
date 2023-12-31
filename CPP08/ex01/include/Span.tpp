/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:37:04 by arabenst          #+#    #+#             */
/*   Updated: 2023/11/22 16:05:10 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

template <typename InputIt>
void Span::addRange(const InputIt &first, const InputIt &last) {
    for (InputIt it = first; it != last; ++it) {
        addNumber(*it);
    }
}
