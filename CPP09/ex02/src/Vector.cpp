/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:04:34 by arabenst          #+#    #+#             */
/*   Updated: 2023/11/25 15:07:58 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

static int catchStraggler(std::vector<int> &vec) {
    int straggler = -1;
    if (vec.size() % 2) {
        straggler = *vec.rbegin();
        vec.pop_back();
    }
    return (straggler);
}

static Pairs createPairs(std::vector<int> &vec) {
    Pairs pairs;
    while (vec.size()) {
        std::pair<int, int> newPair;
        newPair.first = vec.front();
        vec.erase(vec.begin());
        newPair.second = vec.front();
        vec.erase(vec.begin());
        pairs.push_back(newPair);
    }
    return (pairs);
}

static void insertNumber(std::vector<int> &vec, int n) {
    vec.insert(std::upper_bound(vec.begin(), vec.end(), n), n);
}

static void insertPairs(std::vector<int> &vec, Pairs &pairs) {
    for (size_t i = 0; i < pairs.size(); ++i) {
        vec.push_back(pairs[i].second);
    }
    vec.insert(vec.begin(), pairs.front().first);
    
    uint16_t jacobsthal[] = {
        3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845
    };

    uint8_t i = 0;
    size_t prev = 0;
    size_t current = jacobsthal[i];
    while (current < pairs.size()) {
        do {
            insertNumber(vec, pairs[current].first);
        } while (--current > prev);
        prev = jacobsthal[i];
        current = jacobsthal[++i];
    }
    while (++prev < pairs.size()) {
        insertNumber(vec, (pairs.begin() + prev)->first);
    }
}

void fj_sort(std::vector<int> &vec) {
    if (isSorted(vec)) {
        return ;
    }
    int straggler = catchStraggler(vec);
    Pairs pairs = createPairs(vec);
    sortEachPair(pairs);
    pairs = mergeSortPairs(pairs);
    insertPairs(vec, pairs);
    if (straggler != -1) {
        insertNumber(vec, straggler);
    }
}
