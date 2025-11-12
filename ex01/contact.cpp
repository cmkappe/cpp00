/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:18:41 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/10/27 15:57:24 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Contact.hpp"

Contact::Contact() {}

Contact::~Contact(){}



	void	Contact::setFirstName(std::string fn){ _firstName = fn; }
	
	void	Contact::setLastName(std::string ln){ _lastName = ln; }
	
	void	Contact::setNickname(std::string nn){ _nickname = nn; }

	void	Contact::setPhoneNum(std::string pn) { _phoneNum = pn; }

	void	Contact::setDarkestSecret(std::string ds) { _darkestSecret = ds; }



	std::string	Contact::getFirstName(){ return (_firstName); }
	
	std::string	Contact::getLastName(){ return _lastName; }
	
	std::string	Contact::getNickname(){ return _nickname; }

	std::string	Contact::getPhoneNum() { return _phoneNum; }

	std::string	Contact::getDarkestSecret() { return _darkestSecret; }

	