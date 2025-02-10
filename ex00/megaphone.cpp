/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:18:26 by mkulikov          #+#    #+#             */
/*   Updated: 2025/02/10 16:45:04 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str(argv[i]);
			for (size_t j = 0; j < str.length(); j++)
			{
				std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(str[j])));
			}
			if (i < argc - 1)
			{
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
