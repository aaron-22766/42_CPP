/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deque.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:04:34 by arabenst          #+#    #+#             */
/*   Updated: 2023/11/25 15:07:00 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

static int catchStraggler(std::deque<int> &deq) {
    int straggler = -1;
    if (deq.size() % 2) {
        straggler = *deq.rbegin();
        deq.pop_back();
    }
    return (straggler);
}

static Pairs createPairs(std::deque<int> &deq) {
    Pairs pairs;
    while (deq.size()) {
        std::pair<int, int> newPair;
        newPair.first = deq.front();
        deq.erase(deq.begin());
        newPair.second = deq.front();
        deq.erase(deq.begin());
        pairs.push_back(newPair);
    }
    return (pairs);
}

static void insertNumber(std::deque<int> &deq, int n) {
    deq.insert(std::upper_bound(deq.begin(), deq.end(), n), n);
}

static void insertPairs(std::deque<int> &deq, Pairs &pairs) {
    for (size_t i = 0; i < pairs.size(); ++i) {
        deq.push_back(pairs[i].second);
    }
    deq.insert(deq.begin(), pairs.front().first);
    
    uint16_t jacobsthal[] = {
        3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845
    };

    uint8_t i = 0;
    size_t prev = 0;
    size_t current = jacobsthal[i];
    while (current < pairs.size()) {
        do {
            insertNumber(deq, pairs[current].first);
        } while (--current > prev);
        prev = jacobsthal[i];
        current = jacobsthal[++i];
    }
    while (++prev < pairs.size()) {
        insertNumber(deq, (pairs.begin() + prev)->first);
    }
}

void fj_sort(std::deque<int> &deq) {
    if (isSorted(deq)) {
        return ;
    }
    int straggler = catchStraggler(deq);
    Pairs pairs = createPairs(deq);
    sortEachPair(pairs);
    pairs = mergeSortPairs(pairs);
    insertPairs(deq, pairs);
    if (straggler != -1) {
        insertNumber(deq, straggler);
    }
}
