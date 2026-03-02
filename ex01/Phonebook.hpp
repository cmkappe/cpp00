#pragma once

#include "./Contact.hpp"

class Phonebook
{
	private:
		Contact	_arr_contacts[8];
		int	contactCount;

	public:
		Phonebook();
		~Phonebook();

		void	addNewContact();
		void	searchForContact();
};

