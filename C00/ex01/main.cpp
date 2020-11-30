/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 10:38:36 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/11/30 14:40:36 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

//Returns 1 if the string is only made of digit, 0 otherwise.
bool	str_is_digit(std::string &input)
{
	for (int i = 0; input[i]; i++)
		if (!isdigit(input[i]))
			return (0);
	return (1);
}

//Prints all the contacts added with an index and the first 3 fields of
//information, then wait for user input that must choose a contact, and prints
//all the information about this one.
void	do_research(contact *phonebook, int nb_ppl)
{
	std::cout << "--------------------------------------------\n";
	std::cout << "|    index|first name| last name|  nickname|\n";
	
	//printing first 3 information fields
	for (int i = 0; i < nb_ppl; i++)
		phonebook[i].print_search(i + 1);
	std::cout << "--------------------------------------------\n" << std::endl;
	std::cout << "Choose the contact number that you want to print the informations: ";
	
	//waiting for a correct input from the user (a nb between 1 and nb of contacts added)
	std::string	input;
	while (1)
	{
		getline(std::cin, input);
		if (input.empty())
			std::cout << "Choose the contact number that you want to print the informations: ";
		else if (!str_is_digit(input))
			std::cout << "Please enter only a number : ";
		else if (input.length() > 1 || input[0] == '0' || input[0] - 48 > nb_ppl)
			std::cout << "Number must be between 1 and number of existing contacts: ";
		else
		{
			std::cout << "\nInformation about contact " << input << std::endl;
			phonebook[input[0] - 48 - 1].print_contact();
			std::cout << std::endl;
			break;
		}
	}
}

int main()
{
	contact		phonebook[8];
	int			nb_ppl = 0;
	std::string	input;
	
	std::cout << WELCOMING_MSG;
	while (1)
	{
		do
		{
			std::cout << "Please type your request. 3 possible choices : ADD,"
					" SEARCH and EXIT\n";
			getline(std::cin, input);
		} while(input.empty());

		//Adds a contact
		if (!input.compare("ADD") && nb_ppl < 8)
			phonebook[nb_ppl++].add_contact();
		else if (!input.compare("ADD") && nb_ppl >= 8)
			std::cout << "You reach the maximum contact in this phonebook (8)\n\n";

		//Do the research
		else if (!input.compare("SEARCH") && !nb_ppl)
			std::cout << "Please add a contact before doing a research\n\n";
		else if (!input.compare("SEARCH"))
			do_research(phonebook, nb_ppl);

		//Exits
		else if (!input.compare("EXIT"))
		{
			std::cout << "Goodbye!\n";
			return (0);
		}

		//If wrong input, loops until correct one
		else
			std::cout << "\nWrong input! ";
	}
	return (0);
}
