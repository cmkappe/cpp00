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


void	Contact::setFirstName( const std::string fn){ _firstName = fn; }

void	Contact::setLastName(const std::string ln){ _lastName = ln; }

void	Contact::setNickname(const std::string nn){ _nickname = nn; }	

void	Contact::setPhoneNum(const std::string pn) { _phoneNum = pn; }

void	Contact::setDarkestSecret(const std::string ds) { _darkestSecret = ds; }


std::string	Contact::getFirstName() const { return (_firstName); }

std::string	Contact::getLastName() const { return _lastName; }

std::string	Contact::getNickname() const { return _nickname; }

std::string	Contact::getPhoneNum() const { return _phoneNum; }

std::string	Contact::getDarkestSecret() const { return _darkestSecret; }	