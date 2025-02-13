/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:27:17 by mkulikov          #+#    #+#             */
/*   Updated: 2025/02/13 18:04:55 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::getline;
using std::endl;

int main(void)
{
	PhoneBook phonebook;
	string buf;

	while (true) {
		cout << "\nEnter a command (ADD, SEARCH, EXIT):" << "\n" << "> ";
		if (!getline(cin, buf)) {
			break ;
		}
		if (buf.compare("ADD") == 0) {
			phonebook.addNewContact();
		} else if (buf.compare("SEARCH") == 0) {
			phonebook.search();
		} else if (buf.compare("EXIT") == 0) {
			phonebook.exit();
			break ;
		} else {
			cout << "Invalid command" << endl;
		}
	}
	return (0);
}
