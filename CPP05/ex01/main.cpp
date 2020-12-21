/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:15:27 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/17 15:23:49 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "----------------------------------------------\n";
	std::cout << "-------------- BUREAUCRAT TESTS --------------\n";
	std::cout << "----------------------------------------------\n";
	
	Bureaucrat henri("Henri", 1);

	std::cout << henri;
	
	// GradeTooHigh exception test
	try
	{
		std::cout << "Let's try to increase " << henri.getName() << "'s grade!\n";
		henri.incrementGrade();
		std::cout << "Result: " << henri;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	// GradeTooLow exception test
	try
	{
		std::cout << "Let's try to lower " << henri.getName() << " at 200\n";
		for (int i = 0; henri.getGrade() < 200; i++)
			henri.decrementGrade();
		std::cout << "Result: " << henri;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	// Constructor GradeTooLow exception test
	try
	{
		std::cout << "Let's create a bureaucrat with a grade of 180\n";
		Bureaucrat jim("Jim", 180);
		std::cout << jim;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	std::cout << "----------------------------------------------\n";
	std::cout << "----------------- FORM TESTS -----------------\n";
	std::cout << "----------------------------------------------\n";

	// Succesfull creation
	try
	{
		std::cout << "Creating a form with default parameters\n";
		Form f1;
		std::cout << "Form succesfully created\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// Succesfull creation
	try
	{
		std::cout << "Creating a form with given parameters\n";
		Form f3("F3", 30, 20);
		std::cout << "Form succesfully created\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	// Creation failed : exception GradeTooLow
	try
	{
		std::cout << "Creating a form with wrong parameters\n";
		Form f3("F3", 30, 180);
		std::cout << "Form succesfully created\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	Form f1;
	Form f2(f1);
	Form f3("F3", 30, 20);
	
	// Testing getters
	std::cout << "Name:" << f3.getName() << "\n";
	std::cout << "Is signed value:" << f3.getIsSigned() << "\n";
	std::cout << "Grade to sign:" << f3.getGradeToSign() << "\n";
	std::cout << "Grade to execute:" << f3.getGradeToExecute() << "\n\n";

	// Testing overload operator<<
	std::cout << f1 << f2 << f3 << "\n";


	// beSigned fails : exception GradeTooLow
	try
	{
		f3.beSigned(henri);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	// beSigned works
	Bureaucrat jimmy("Jimmy", 1);
	try
	{
		f3.beSigned(jimmy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}