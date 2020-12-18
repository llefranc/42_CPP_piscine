/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:15:27 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/18 11:06:05 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "time.h"
#include "math.h"

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	// For random messages in RobotomyRequestForm.cpp
	srand(time(0));
	
	std::cout << "----------------------------------------------\n";
	std::cout << "---------------- INTERN TESTS ----------------\n";
	std::cout << "----------------------------------------------\n";
	
	Form *ptr;
	Intern intern;


	std::cout << "\nTEST: robotomy request:\n";
	try
	{
		ptr = intern.makeForm("robotomy request", "Billy");
		std::cout << *ptr;
		delete ptr;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "\nTEST: shrubbery creation:\n";
	try
	{
		ptr = intern.makeForm("shrubbery creation", "Bob");
		std::cout << *ptr;
		delete ptr;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "\nTEST: presidential pardon:\n";
	try
	{
		ptr = intern.makeForm("presidential pardon", "Jack");
		std::cout << *ptr;
		delete ptr;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\nTEST: random string, will produce an exception:\n";
	try
	{
		ptr = intern.makeForm("random form", "Peter");
		std::cout << *ptr;
		delete ptr;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}