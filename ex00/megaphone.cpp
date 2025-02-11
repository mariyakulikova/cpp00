/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:18:26 by mkulikov          #+#    #+#             */
/*   Updated: 2025/02/11 15:10:56 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::toupper;


int	main(int argc, char **argv) {
	if (argc == 1) {
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
	}
	else {
		for (int i = 1; i < argc; i++) {
			string str(argv[i]);
			for (size_t j = 0; j < str.length(); j++) {
				cout << static_cast<char>(toupper(static_cast<unsigned char>(str[j])));
			}
		}
		cout << endl;
	}
	return (0);
}
