/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 13:33:52 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/11/30 14:57:29 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

//initialize field_name array
contact::contact()
{
	field_name[0] = "first name";
	field_name[1] = "last name";
	field_name[2] = "nickname";
	field_name[3] = "login";
	field_name[4] = "postal address";
	field_name[5] = "email address";
	field_name[6] = "phone number";
	field_name[7] = "birthday date";
	field_name[8] = "favorite meal";
	field_name[9] = "underwear color";
	field_name[10] = "darkest secret";
}

//Waits for user input (11 times) to fill each field of contact information array.
void	contact::add_contact()
{
	for (int i = 0; i < 11; i++)
	{
		do
		{
			std::cout << "Please type your " << field_name[i] << ": ";
			getline(std::cin, info[i]);
		} while(info[i].empty());
	}
	std::cout << "Contact succesfully added!\n\n";
}

//Prints the 11 fields of contact information.
void	contact::print_contact()
{
	for (int i = 0; i < 11; i++)
		std::cout << field_name[i] << " : " << info[i] << std::endl;
}

//Prints the index of the contact and the 3 first fields of contact information.
void	contact::print_search(int index)
{
	std::string tmp;
	
	std::cout << "|        " << index << "|";
	for (int i = 0; i < 3; i++)
	{
		tmp = info[i];
		if (tmp.length() <= 10)
		{
			std::cout.width(10);
			std::cout << tmp;
		}
		else
		{
			//if lengh > 10, prints only the first nine characters and a dot
			tmp.resize(9);
			std::cout << tmp << ".";
		}
		std::cout << '|';
	}
	std::cout << std::endl;
}
