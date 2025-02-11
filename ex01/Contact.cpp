/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:13:15 by mkulikov          #+#    #+#             */
/*   Updated: 2025/02/11 18:37:26 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
	: firstName("")
	, lastName("")
	, nickName("")
	, phoneNumber("")
	, darkestSecret("")
{}

Contact::Contact(const string &firstName
				, const string &lastName
				, const string &nickName
				, const string &phoneNumber
				, const string &darkestSecret)
	: firstName(firstName)
	, lastName(lastName)
	, nickName(nickName)
	, phoneNumber(phoneNumber)
	, darkestSecret(darkestSecret)
{}

Contact::Contact(const Contact &other)
		: firstName(other.firstName)
		, lastName(other.lastName)
		, nickName(other.nickName)
		, phoneNumber(other.phoneNumber)
		, darkestSecret(other.darkestSecret)
{}

Contact& Contact::operator=(const Contact &contact) {
	if (this != &contact) {
		firstName = contact.firstName;
		lastName = contact.lastName;
		nickName = contact.nickName;
		phoneNumber = contact.phoneNumber;
		darkestSecret = contact.darkestSecret;
	}
	return *this;
}

Contact::~Contact()
{}

void Contact::setFirstName(const string& first) {
	this->firstName = first;
}

void Contact::setLastName(const string& last) {
	this->lastName = last;
}

void Contact::setNickName(const string& nick) {
	this->nickName = nick;
}

void Contact::setPhoneNumber(const string& number) {
	this->phoneNumber = number;
}

void Contact::setDarkestSecret(const string& secret) {
	this->darkestSecret = secret;
}

string Contact::getFirstName() const {
	return firstName;
};

string Contact::getLastName() const {
	return lastName;
};

string Contact::getNickName() const {
	return nickName;
};

string Contact::getPhoneNumber() const {
	return phoneNumber;
};

string Contact::getDarkestSecret() const {
	return darkestSecret;
};
