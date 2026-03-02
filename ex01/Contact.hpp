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

		void	setFirstName(const std::string fn);
		void	setLastName(const std::string ln);
		void	setNickname(const std::string nn);
		void	setPhoneNum(const std::string pn);
		void	setDarkestSecret(const std::string ds);

		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getPhoneNum() const;
		std::string	getDarkestSecret() const;
};
