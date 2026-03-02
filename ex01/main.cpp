/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:56:33 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/11/05 15:26:52 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <algorithm>
#include "./Contact.hpp"
#include "./Phonebook.hpp"

static std::string toUppercase(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	return str;
}

/* At program start-up, the phonebook is empty and the user is prompted to enter one
of three commands. The program only accepts ADD, SEARCH and EXIT. */

int main()
{
	Phonebook	pb;
	std::string	text;
	
	std::cout << "\nWelcome to this *awesome* phonebook!\n"
		<< "You can enter the following commands:\nADD, SEARCH and/or EXIT\n\n";

	while (true)
	{
		std::getline(std::cin, text);
		if (std::cin.eof())
			break ;
		
		text = toUppercase(text);

		if (text == "ADD")
			pb.addNewContact();
		else if (text == "SEARCH")
			pb.searchForContact();
		else if (text == "EXIT")
			break ;
		else
		{
			std::cout << "Please try again with one of the following commands:\n";
			std::cout << "ADD, SEARCH or EXIT\n" << std::endl;
		}
	}
	return (0);
}
