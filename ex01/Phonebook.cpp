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

#include "./Phonebook.hpp"
#include <string>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cctype>
#include <sstream>

Phonebook::Phonebook() : contactCount(0) {}
Phonebook::~Phonebook(){}

// -----------------------------------------------------
// *** HELPER FUNCTIONS ***
// -----------------------------------------------------

bool isDigitsOnly(const std::string &str) {
	if (str.empty())
		return false;
	return std::all_of(str.begin(), str.end(), ::isdigit);
}

static std::string read(bool flag)
{
	std::string input;

	while (true) {
		std::getline(std::cin, input);
		if (std::cin.eof())
			return "";
		
		// Trim whitespace
		size_t start = input.find_first_not_of(" \t\r\n");
		if (start == std::string::npos)
			input = "";
		else
			input = input.substr(start, input.find_last_not_of(" \t\r\n") - start + 1);
		
		if (!input.empty()) {
			if (flag == false) {	// Phone validation?
				if (!isDigitsOnly(input)) {
					std::cout << "\n\nOnly numeric values allowed!\n";
					std::cout << "Please try again.\n\n";
				}
				else
					return input;	// phone is valid, can be returned
			} 
			else
				return input;		// any text is valid, can be returned
		}
	}
	return input;
}

static std::string intToString(int num)
{
	std::ostringstream oss;		// Create a string stream
	oss << num;					// Put the number into the stream
	return oss.str();			// Convert stream to string and return
}

std::string	formatField(std::string str){
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return std::string(10 - str.length(), ' ') + str;
}

// -----------------------------------------------------
// *** MEMBER FUNCTIONS ***
// -----------------------------------------------------

void	Phonebook::searchForContact(){
	
	std::string	input_index;
	
	if (contactCount == 0) {
		std::cout << "Phonebook is empty!\n";
		std::cout << "\nAvailable options: ADD, SEARCH or EXIT\n\n";
		return ;
	}
	// display all saved contacts
	std::cout << "_____________________________________________"
		<< std::endl
		<< "| Index    |First Name| Last Name| Nickname | "
		<< std::endl
		<< "---------------------------------------------"
		<< std::endl;
		
		for (int i = 0; i < contactCount; i++)
		{
			std::cout << "|" << formatField(intToString(i))
				<< "|" << formatField(_arr_contacts[i].getFirstName())
				<< "|" << formatField(_arr_contacts[i].getLastName())
				<< "|" << formatField(_arr_contacts[i].getNickname())
				<< "|" << std::endl;
		}
	// ask user for specific index
	std::cout << "\n\nEnter Index to display contact information:\n";
	if (std::getline(std::cin, input_index)){
		if (!isDigitsOnly(input_index)) {
			std::cout << "Invalid index!\n";
		} else {
			int index = std::atoi(input_index.c_str());
			if (index < 0 || index >= contactCount)
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
	}
	std::cout << "\n\nAvailable options: ADD, SEARCH or EXIT\n\n";	
}

void	Phonebook::addNewContact()
{
	Contact		newContact;

	std::cout << "\nPlease submit the following contact information:\n";
	std::cout << "\nFirst name: \n";
	std::string first = read(true);
	std::cout << "Last name: \n";
	std::string last = read(true);
	std::cout << "Nickname: \n";
	std::string nick = read(true);
	std::cout << "Phone number: \n";
	std::string phone = read(false);
	std::cout << "Darkest secret: \n";
	std::string secret = read(true);
	
	newContact.setFirstName(first);
	newContact.setLastName(last);
	newContact.setNickname(nick);
	newContact.setPhoneNum(phone);
	newContact.setDarkestSecret(secret);
	
	// If full, remove oldest (at index 0) and shift all left
	if (contactCount >= 8)
	{
		for (int j = 0; j < 7; j++)
			_arr_contacts[j] = _arr_contacts[j + 1];
		_arr_contacts[7] = newContact;
	}
	else
	{
		_arr_contacts[contactCount] = newContact;
		++contactCount;
	}

	std::cout << "\n\nContact saved.\n\n Available options: ADD, SEARCH or EXIT\n\n";
}
