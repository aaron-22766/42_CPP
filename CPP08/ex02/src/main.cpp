/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:42:23 by arabenst          #+#    #+#             */
/*   Updated: 2023/11/22 18:44:21 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MutantStack.hpp"
#include <iostream>
#include <cstdlib>
#include <list>

using std::cout;
using std::endl;

int main(void) {
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        cout << mstack.top() << endl;
        mstack.pop();
        cout << mstack.size() << endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite) {
            cout << *it << endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    cout << endl;
    {
        std::list<int> mlist;
        mlist.push_back(5);
        mlist.push_back(17);
        cout << mlist.back() << endl;
        mlist.pop_back();
        cout << mlist.size() << endl;
        mlist.push_back(3);
        mlist.push_back(5);
        mlist.push_back(737);
        mlist.push_back(0);
        std::list<int>::iterator it = mlist.begin();
        std::list<int>::iterator ite = mlist.end();
        ++it;
        --it;
        while (it != ite) {
            cout << *it << endl;
            ++it;
        }
    }
    return (EXIT_SUCCESS);
}
