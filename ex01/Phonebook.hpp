/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:09:25 by mkulikov          #+#    #+#             */
/*   Updated: 2025/02/13 18:05:39 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <string>

#define MAX_SIZE 8

class PhoneBook {
private:
	Contact contacts[MAX_SIZE];
	int curr_idx;
	int added_num;
	void printTable();
	bool isEmpty();
	bool requestFieldInput(const string &field, string &buf);
	bool isValidPhoneNumber(const string &phoneNumber);
	string formatStr(const string &str);
	void showContact(int idx);

public:
	PhoneBook();
	PhoneBook(int curr_idx, int add_num);
	PhoneBook(const PhoneBook &other);
	PhoneBook &operator=(const PhoneBook &other);
	~PhoneBook();
	void addNewContact();
	void search();
	void exit();
};

#endif
