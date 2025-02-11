/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:09:25 by mkulikov          #+#    #+#             */
/*   Updated: 2025/02/11 19:55:45 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <stdlib.h>
#include <string.h>
#include <iostream>

# define MAX_SIZE 8;

class PhoneBook {
private:
	Contact contacts[MAX_SIZE];
	int curr_idx;
	int added_num;
	void add();
	void search();
	void exit();

Public:
	PhoneBook();
	PhoneBook(int curr_idx, int add_num);
	PhoneBook(const PhoneBook &other);
	PhoneBook &operator=(const PhoneBook &other);
	~PhoneBook();
	void run();
};

#endif
