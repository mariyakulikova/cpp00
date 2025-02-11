/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:35:53 by mkulikov          #+#    #+#             */
/*   Updated: 2025/02/11 19:57:36 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

PhoneBook::PhoneBook()
		: curr_idx(0)
		, added_num(0)
{}

PhoneBook::PhoneBook(int curr_idx, int added_num)
		: curr_idx(curr_idx)
		, added_num(added_num)
{}

PhoneBook::PhoneBook(const PhoneBook &other)
		: curr_idx(other.curr_idx)
		, added_num(other.added_num)
{
	for (int i = 0; i < other.added_num; i++) {
		contacts[i] = other.contacts[i];
	}
}

PhoneBook &PhoneBook::operator=(const PhoneBook &other) {
	if (this != &other) {
		curr_idx = other.curr_idx;
		added_num = other.added_num;
		for (int i = 0; i < other.added_num; i++) {
			contacts[i] = other.contacts[i];
		}
	}
}

PhoneBook::~PhoneBook()
{}

void PhoneBook::run() {
	string input;

	while (true) {
		cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (getline(cin, input)) {
			break ;
		}
		if (input.compare("ADD") == 0) {
			add(); // TODO ADD
		} else if (input.compare("SEARCH") == 0) {
			search(); // TODO SEARCH
		} else if (input.compare("EXIT") == 0) {
			break ;
		} else {
			cout << "Invalid command." << endl;
		}
	}
	cout << "Exiting crappy awesome phonebook." << endl;
}
