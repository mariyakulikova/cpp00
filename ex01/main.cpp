/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:27:17 by mkulikov          #+#    #+#             */
/*   Updated: 2025/02/10 17:35:30 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	Contact c("1", "2", "3", "4", "5");

	std::cout << c.getFirstName() << " " << c.getLastName() << " " << c.getPhoneNumber() << " " << c.getDarkestSecret() << std::endl;
	return (0);
}
