/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:15:27 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/18 11:01:48 by lucaslefran      ###   ########.fr       */
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

int main()
{
	// For random messages in RobotomyRequestForm.cpp
	srand(time(0));
	
	std::cout << "----------------------------------------------\n";
	std::cout << "----------------- FORM TESTS -----------------\n";
	std::cout << "----------------------------------------------\n";
	
	Form *formArray[3];
	formArray[0] = new PresidentialPardonForm;
	formArray[1] = new ShrubberyCreationForm;
	formArray[2] = new RobotomyRequestForm;
	
	Bureaucrat boss("Boss", 1);
	Bureaucrat loser("Loser", 150);

	
	// Form not signed test
	try
	{
		formArray[0]->execute(boss);
		formArray[0]->execute(loser);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	// PresidentialPardon test
	try
	{
		formArray[0]->beSigned(boss);
		formArray[0]->execute(boss);
		formArray[0]->execute(loser);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	// ShrubberyCreation test
	try
	{
		formArray[1]->beSigned(boss);
		formArray[1]->execute(boss);
		formArray[1]->execute(loser);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	// RobotomyRequest test
	try
	{
		formArray[2]->beSigned(boss);
		formArray[2]->execute(boss);
		formArray[2]->execute(loser);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "----------------------------------------------\n";
	std::cout << "-------------- BUREAUCRAT TESTS --------------\n";
	std::cout << "----------------------------------------------\n";

	// PresidentialPardon test
	try
	{
		boss.executeForm(*formArray[0]);
		loser.executeForm(*formArray[0]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	// ShrubberyCreation test
	try
	{
		boss.executeForm(*formArray[1]);
		loser.executeForm(*formArray[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	// RobotomyRequest test
	try
	{
		boss.executeForm(*formArray[2]);
		loser.executeForm(*formArray[2]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < 3; i++)
		delete formArray[i];

	return (0);
}