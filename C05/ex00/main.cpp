/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:15:27 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/17 12:26:08 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

int main()
{
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
	
	return (0);
}