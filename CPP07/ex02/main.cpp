/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:39:32 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/24 12:13:17 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>

#include "Array.hpp"

int main()
{
	// Array of ints
	{
		std::cout << "------ TEST WITH AN ARRAY OF 5 INTS ------\n";
		Array<int> array(static_cast<unsigned int>(5));
		
		try
		{
			for (unsigned int i = 0; i < array.getSizeArray(); i++)
				std::cout << array[i] << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	
	// Array of floats with copy constructor
	{
		std::cout << "\n------ TEST WITH AN ARRAY OF 3 FLOATS + COPY CONSTRUCTOR ------\n";
		Array<float> array(static_cast<unsigned int>(3));
		Array<float> copyArray(array);
		
		std::cout << std::fixed << std::setprecision(1);
		try
		{
			for (unsigned int i = 0; i < copyArray.getSizeArray(); i++)
				std::cout << copyArray[i] << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	// Array of longs with default constructor and assign operator
	{
		std::cout << "\n------ TEST WITH AN ARRAY OF 4 LONGS + DEFAULT CONSTRUCTOR + ASSIGN OPERATOR ------\n";
		Array<long> array(static_cast<unsigned int>(4));
		Array<long> assignArray;
		
		std::cout << "Printing assignArray initialized with default constructor: size = " << assignArray.getSizeArray()
			<< "\nPrinting assignArray:\n";
		try
		{
			for (unsigned int i = 0; i < assignArray.getSizeArray(); i++)
				std::cout << assignArray[i] << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		
		assignArray = array;
		std::cout << "\nPrinting assignArray after assignment with an array of 4 longs: size = "
			<< assignArray.getSizeArray() << "\nPrinting assignArray:\n";
		try
		{
			for (unsigned int i = 0; i < assignArray.getSizeArray(); i++)
				std::cout << assignArray[i] << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	// Producing an exception with overloaded operator[]
	{

		std::cout << "\n------ TEST WITH DEFAULT CONSTRUCTOR + EXCEPTION THROWN BY OVERLOADED OPERATOR[] ------\n";
		Array<double> array;
		try
		{
			std::cout << array[1] << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}	
	}

	return (0);
}