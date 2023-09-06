/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 09:01:53 by arabenst          #+#    #+#             */
/*   Updated: 2023/09/06 11:18:12 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "../include/Account.hpp"

using std::cout;
using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

Account::Account(int initial_deposit) :
    _accountIndex(Account::_nbAccounts),
    _amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0) {
    Account::_nbAccounts++;
    Account::_totalAmount += _amount;
    Account::_displayTimestamp();
    cout << " index:" << _accountIndex
         << ";amount:" << _amount
         << ";created" << endl;
}

Account::~Account(void) {
    Account::_displayTimestamp();
    cout << " index:" << _accountIndex
         << ";amount:" << _amount
         << ";closed" << endl;
}

/* ************************************************************************** */
/*                          PUBLIC: STATIC ACCESSORS                          */
/* ************************************************************************** */

int	Account::getNbAccounts(void) {
    return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void) {
    return (Account::_totalAmount);
}

int	Account::getNbDeposits(void) {
    return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
    return (Account::_totalNbWithdrawals);
}

/* ************************************************************************** */
/*                           PUBLIC: STATIC METHODS                           */
/* ************************************************************************** */

void	Account::displayAccountsInfos(void) {
    Account::_displayTimestamp();
    cout << " accounts:" << Account::_nbAccounts
         << ";total:" << Account::_totalAmount
         << ";deposits:" << Account::_totalNbDeposits
         << ";withdrawals:" << Account::_totalNbWithdrawals << endl;
}

/* ************************************************************************** */
/*                             PUBLIC: ACCESSORS                              */
/* ************************************************************************** */

int		Account::checkAmount(void) const {
    return (_amount);
}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

void	Account::makeDeposit(int deposit) {
    Account::_displayTimestamp();
    cout << " index:" << _accountIndex
         << ";p_amount:" << _amount
         << ";deposit:" << deposit;
    _amount += deposit;
    Account::_totalAmount += deposit;
    _nbDeposits++;
    Account::_totalNbDeposits++;
    cout << ";amount:" << _amount
         << ";nb_deposits:" << _nbDeposits << endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
   Account::_displayTimestamp();
    cout << " index:" << _accountIndex
         << ";p_amount:" << _amount
         << ";withdrawal:";
    if (_amount < withdrawal) {
        cout << "refused" << endl;
        return (false);
    }
    _amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    _nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    cout << withdrawal
         << ";amount:" << _amount
         << ";nb_withdrawals:" << _nbWithdrawals << endl;
    return (true);
}

void	Account::displayStatus(void) const {
    Account::_displayTimestamp();
    cout << " index:" << _accountIndex
         << ";amount:" << _amount
         << ";deposits:" << _nbDeposits
         << ";withdrawals:" << _nbWithdrawals << endl;
}

/* ************************************************************************** */
/*                          PRIVATE: SPECIAL METHODS                          */
/* ************************************************************************** */

Account::Account(void) {}

/* ************************************************************************** */
/*                          PRIVATE: STATIC METHODS                           */
/* ************************************************************************** */

void	Account::_displayTimestamp(void) {
    time_t now = time(0);
    struct tm* ltm = localtime(&now);
    char formattedTime[18];

    std::strftime(formattedTime, 18, "[%Y%m%d_%H%M%S]", ltm);
    cout << formattedTime;
}

/* ************************************************************************** */
/*                         PRIVATE: STATIC VARIABLES                          */
/* ************************************************************************** */

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

