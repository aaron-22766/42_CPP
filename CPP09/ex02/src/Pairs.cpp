/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pairs.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:07:08 by arabenst          #+#    #+#             */
/*   Updated: 2023/11/25 15:07:24 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

void sortEachPair(Pairs &pairs) {
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].first > pairs[i].second) {
            int temp = pairs[i].first;
            pairs[i].first = pairs[i].second;
            pairs[i].second = temp;
        }
    }
}

static Pairs merge(Pairs &a, Pairs &b) {
    Pairs result;
    while (a.size() && b.size()) {
        if (a[0].second < b[0].second) {
            result.push_back(a[0]);
            a.erase(a.begin());
        } else {
            result.push_back(b[0]);
            b.erase(b.begin());
        }
    }
    while (a.size()) {
        result.push_back(a[0]);
        a.erase(a.begin());
    }
    while (b.size()) {
        result.push_back(b[0]);
        b.erase(b.begin());
    }
    return (result);
}

Pairs mergeSortPairs(Pairs &pairs) {
    if (pairs.size() == 1) {
        return (pairs);
    }
    Pairs left(pairs.begin(), pairs.begin() + (pairs.size() / 2));
    Pairs right(pairs.begin() + (pairs.size() / 2), pairs.end());
    left = mergeSortPairs(left);
    right = mergeSortPairs(right);
    return (merge(left, right));
}
