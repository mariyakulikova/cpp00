/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:58:06 by mkulikov          #+#    #+#             */
/*   Updated: 2025/02/14 11:55:12 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

using std::cout;
using std::endl;

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts() {
	return _nbAccounts;
}

int Account::getTotalAmount() {
	return _totalAmount;
}

int Account::getNbDeposits() {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

void Account::_displayTimestamp(void) {
	std::time_t now = std::time(NULL);
	struct tm *t = std::localtime(&now);
	char buf[20];
	std::strftime(buf,sizeof(buf), "[%Y%m%d_%H%M%S] ", t);
	cout << buf;
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	cout << "accounts:" << getNbAccounts()
		 << ";total:" << getTotalAmount()
		 << ";deposits:" << getNbDeposits()
		 << ";withdrawals:" << getNbWithdrawals() << endl;
}

int Account::checkAmount(void) const {
	return _amount;
}

Account::~Account() {
	_displayTimestamp();
	cout << "index:" << _accountIndex
		 << ";amount:" << checkAmount()
		 << ";closed" << endl;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	cout << "index:" << _accountIndex
		 << ";amount:" << checkAmount()
		 << ";deposits:" << _nbDeposits
		 << ";withdrawals:" << _nbWithdrawals << endl;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	cout << "index:" << _accountIndex
		 << ";p_amount:" << checkAmount() - deposit
		 << ";deposit:" << deposit
		 << ";amount:" << checkAmount()
		 << ";nb_deposits:" << _nbDeposits << endl;
}

Account::Account(int initial_deposit)
		: _accountIndex(getNbAccounts())
		, _amount(initial_deposit)
		, _nbDeposits(0)
		, _nbWithdrawals(0) {
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	cout << "index:" << _accountIndex
		 << ";amount:" << _amount
		 << ";created" << endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	if (withdrawal > checkAmount()) {
		cout << "index:" << _accountIndex
			 << ";p_amount:" << checkAmount()
			 << ";withdrawal:" << "refused"
			 << endl;
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals = 1;
	_totalNbWithdrawals++;
	cout << "index:" << _accountIndex
			 << ";p_amount:" << checkAmount() + withdrawal
			 << ";withdrawal:" << withdrawal
			 << ";amount:" << checkAmount()
			 << ";nb_withdrawals:" << _nbWithdrawals
			 << endl;

	return true;
}
