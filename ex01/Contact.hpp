/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:13:04 by mkulikov          #+#    #+#             */
/*   Updated: 2025/02/12 14:40:19 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

using std::string;

class Contact {
private:
	string firstName;
	string lastName;
	string nickName;
	string phoneNumber;
	string darkestSecret;

public:
	Contact();
	Contact(const string &firstName
			, const string &lastName
			, const string &nickName
			, const string &phoneNumber
			, const string &darkestSecret);
	Contact(const Contact &other);
	Contact& operator=(const Contact &contact);
	~Contact();

	void setFirstName(const string &first);
	void setLastName(const string &last);
	void setNickName(const string &nick);
	void setPhoneNumber(const string &number);
	void setDarkestSecret(const string &secret);

	string getFirstName() const;
	string getLastName() const;
	string getNickName() const;
	string getPhoneNumber() const;
	string getDarkestSecret() const;
};

#endif
