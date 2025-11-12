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
#include "./Contact.hpp"
#include "./Phonebook.hpp"

/* At program start-up, the phonebook is empty and the user is prompted to enter one
of three commands. The program only accepts ADD, SEARCH and EXIT. */


int main()
{
	Phonebook	pb;
	std::string	text;
	
	std::cout << "\nWelcome to this *awesome* phonebook!\n"
		<< "You can enter the following commands:\nADD, SEARCH and/or EXIT\n\n";

	while (text != "EXIT")
	{
		std::cin >> text;
		if (text == "ADD")
			pb.addNewContact();
		else if (text == "SEARCH")
			pb.searchForContact();
		else if (text == "EXIT")
			exit(EXIT_SUCCESS) ; 
		else
			std::cout << "Please try again with one of the following commands:\nADD, SEARCH or EXIT " 
				<< std::endl;
	}
	
	return (0);
}