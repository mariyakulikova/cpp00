/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:13:15 by mkulikov          #+#    #+#             */
/*   Updated: 2025/02/10 17:24:17 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(const std::string& first)
{
	firstName = first;
}

void Contact::setLastName(const std::string& last)
{
	lastName = last;
}

void Contact::setNickName(const std::string& nick)
{
	nickName = nick;
}

void Contact::setPhoneNumber(const std::string& number)
{
	phoneNumber = number;
}

void Contact::setDarkestSecret(const std::string& secret)
{
	darkestSecret = secret;
}

std::string Contact::getFirstName() const
{
	return firstName;
};

std::string Contact::getLastName() const
{
	return lastName;
};

std::string Contact::getNickName() const
{
	return nickName;
};

std::string Contact::getPhoneNumber() const
{
	return phoneNumber;
};

std::string Contact::getDarkestSecret() const
{
	return darkestSecret;
};
