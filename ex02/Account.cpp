/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:58:06 by mkulikov          #+#    #+#             */
/*   Updated: 2025/02/13 22:32:35 by mkulikov         ###   ########.fr       */
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
	return _nbWithdrawals;
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
	cout << " accounts:" << getNbAccounts()
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
		 << ":deposits:" << _nbDeposits
		 << "withdrawls:" << _nbWithdrawals << endl;
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

Account::Account(int initial_deposit) {

}

bool Account::makeWithdrawal(int withdrawal) {

}

Account::Account() {

}
