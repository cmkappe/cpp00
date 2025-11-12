#pragma once

#include <string>

class Contact
{
	private:
		std::string	_firstName;
		std::string _lastName;
		std::string _nickname;
		std::string	_phoneNum;
		std::string	_darkestSecret;

	public:
		Contact();
		~Contact();

		void	setFirstName(std::string fn);
		void	setLastName(std::string ln);
		void	setNickname(std::string nn);
		void	setPhoneNum(std::string pn);
		void	setDarkestSecret(std::string ds);

		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickname();
		std::string	getPhoneNum();
		std::string	getDarkestSecret();
};

