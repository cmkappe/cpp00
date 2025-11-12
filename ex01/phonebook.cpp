/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:50:05 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/11/05 15:31:53 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Contact.hpp"
#include "./Phonebook.hpp"
#include <string>
#include <iostream>
#include <limits>

Phonebook::Phonebook() : i(0), contactCount(0) {}
Phonebook::~Phonebook(){}


	bool isDigitsOnly(const std::string &str) {
		return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
		}


	static std::string read(bool flag)
	{
		std::string input;
		Phonebook	pb;

		while (input.empty()) {
			std::getline(std::cin, input);
			if (std::cin.eof()) {
    			std::cin.clear();
      			clearerr(stdin);
			}
			if (flag == false){
				if (!isDigitsOnly(input)){
					std::cout << "\n\nOnly numeric values allowed!\n";
					std::cout << "Please try again to add a phone number.\n";
					(read(false));
				}
			}	
		}
		return input;
	}
	
	std::string	formatField(std::string str){
		if (str.length() > 10)
			return str.substr(0, 9) + ".";
		return std::string(10 - str.length(), ' ') + str;
	}


	void	Phonebook::searchForContact(){
		
		std::string	input_index;

		// display all saved contacts
		std::cout << "_____________________________________________"
			<< std::endl
			<< "| Index    |First Name| Last Name| Nickname | "
			<< std::endl
			<< "---------------------------------------------"
			<< std::endl;
			
			for (int i = 0; i < contactCount; i++)
			{
				std::cout << "|" << formatField(std::to_string(i))
					<< "|" << formatField(_arr_contacts[i].getFirstName())
					<< "|" << formatField(_arr_contacts[i].getLastName())
					<< "|" << formatField(_arr_contacts[i].getNickname())
					<< "|" << std::endl;
			}
			
		// prompt user for specific index
		std::cout << "\n\nEnter Index to display contact information:\n";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (std::getline(std::cin, input_index)){
			int index = std::atoi(input_index.c_str());
			if (index < 0 || index >= i)
				std::cout << "Invalid index!\n";
			else
			{
				std::cout << "First name: " << _arr_contacts[index].getFirstName() << std::endl;
				std::cout << "Last name: " << _arr_contacts[index].getLastName() << std::endl;
				std::cout << "Nickname: " << _arr_contacts[index].getNickname() << std::endl;
				std::cout << "Phone number: " << _arr_contacts[index].getPhoneNum() << std::endl;
				std::cout << "Darkest secret: " << _arr_contacts[index].getDarkestSecret() << std::endl;
			}
			
		}
		std::cout << "\n\nAvailable options: ADD, SEARCH or EXIT\n\n";	
	}
	
	
	void	Phonebook::addNewContact()
	{
		Contact		newContact;
		std::string	input;
		int			flagNum;

		flagNum = 0;

		std::cout << "\nPlease submit the following contact information:\n";
		std::cout << "\nFirst name: \n";

		newContact.setFirstName(read(true));
		
		std::cout << "Last name: \n";
		newContact.setLastName(read(true));

		std::cout << "Nickname: \n";
		newContact.setNickname(read(true));
		
		std::cout << "Phone number: \n";
		newContact.setPhoneNum(read(false));
		
		std::cout << "Darkest secret: \n";
		newContact.setDarkestSecret(read(true));

		_arr_contacts[i % 8] = newContact;
		if (contactCount < 8)
			++contactCount;
		++i;

		std::cout << "\n\nContact saved.\n\n Available options: ADD, SEARCH or EXIT\n\n";
		
	}
	