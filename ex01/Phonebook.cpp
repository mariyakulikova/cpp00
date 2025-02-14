/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:35:53 by mkulikov          #+#    #+#             */
/*   Updated: 2025/02/14 12:38:14 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

using std::cout;
using std::cin;
using std::string;
using std::getline;
using std::endl;
using std::setw;
using std::right;
using std::istringstream;

PhoneBook::PhoneBook()
		: nextIdx(0)
		, contactCount(0)
{}

PhoneBook::PhoneBook(int nextIdx, int contactCount)
		: nextIdx(nextIdx)
		, contactCount(contactCount)
{}

PhoneBook::PhoneBook(const PhoneBook &other)
		: nextIdx(other.nextIdx)
		, contactCount(other.contactCount)
{
	for (int i = 0; i < other.contactCount; i++) {
		contacts[i] = other.contacts[i];
	}
}

PhoneBook &PhoneBook::operator=(const PhoneBook &other) {
	if (this != &other) {
		nextIdx = other.nextIdx;
		contactCount = other.contactCount;
		for (int i = 0; i < other.contactCount; i++) {
			contacts[i] = other.contacts[i];
		}
	}
	return *this;
}

PhoneBook::~PhoneBook()
{}

bool PhoneBook::requestFieldInput(const string &fieldName, string &buf) {
	cout << "Enter " << fieldName << ":\n> ";
	getline(cin, buf);
	if (buf.empty()) {
		cout << "Field " << fieldName << " can not be empty\n" << endl;
		return false;
	}
	return true;
}

bool PhoneBook::isValidPhoneNumber(const string &phoneNumber) {
	for (string::const_iterator iter = phoneNumber.begin(); iter != phoneNumber.end(); ++iter) {
		if (!std::isdigit(*iter)) {
			cout << "Phone number must contain only digits" << endl;
			return false;
		}
	}
	return true;
}

void PhoneBook::addNewContact() {
	Contact contact;
	string buf;

	while (!requestFieldInput("first name", buf)) {}
	contact.setFirstName(buf);

	while (!requestFieldInput("last name", buf)) {}
	contact.setLastName(buf);

	while (!requestFieldInput("nickname", buf)) {}
	contact.setNickName(buf);

	while (!requestFieldInput("phone number", buf)
			|| !isValidPhoneNumber(buf)) {}
	contact.setPhoneNumber(buf);

	while (!requestFieldInput("darkest secret", buf)) {}
	contact.setDarkestSecret(buf);
	contacts[nextIdx] = contact;
	if (contactCount < 8) {
		contactCount++;
	}
	nextIdx = (nextIdx + 1) % 8;
}

bool PhoneBook::isEmpty() {
	if (contactCount == 0)
		return true;
	return false;
}

string PhoneBook::formatStr(const string &str) {
	return str.length() > 10 ? (str.substr(0, 9) + ".") : str;
}

void PhoneBook::printTable() {
	cout << setw(10) << right << "Index" << "|"
		 << setw(10) << right << "First name" << "|"
		 << setw(10) << right << "Last name" << "|"
		 << setw(10) << right << "Nickname" << endl;
	for (int i = 0; i < contactCount; i++) {
		cout << setw(10) << right << i << "|"
			 << setw(10) << right << formatStr(contacts[i].getFirstName()) << "|"
			 << setw(10) << right << formatStr(contacts[i].getLastName()) << "|"
			 << setw(10) << right << formatStr(contacts[i].getNickName()) << endl;
	}
}

void PhoneBook::showContact(int idx) {
	cout << "First name: " << contacts[idx].getFirstName() << "\n"
		 << "Last name: " << contacts[idx].getLastName() << "\n"
		 << "Nickname: " << contacts[idx].getNickName() << "\n"
		 << "Phone number: " << contacts[idx].getPhoneNumber() << "\n"
		 << "Darkest secret: " << contacts[idx].getDarkestSecret() << "\n";
}

void PhoneBook::search() {
	int idx = 0;

	if (isEmpty()) {
		cout << "Phone book is empty" << endl;
		return ;
	}
	printTable();
	cout << "Please select contact index" << "\n> ";
	string str;
	getline(cin, str);
	istringstream iss(str);
	iss >> idx;
	if (idx > -1 && idx < contactCount) {
		showContact(idx);
	}
	cout << "Invalid index\n";
	return ;
}

void PhoneBook::exit() {
	cout << "Exiting crappy awesome phonebook" << endl;
}
