/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:55:31 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/28 16:19:01 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Span.hpp"
#include "FillMultiSet.hpp"

int main()
{
	{
		std::cout << "--------- Test with a small array of ints ---------\n";
		Span span(10);
	
		span.addNumber(1);
		span.addNumber(2);
		span.addNumber(1);
		span.addNumber(3);
		span.addNumber(1);
		
		std::cout << "Printing array of int: ";
		for (std::multiset<int>::iterator it = span.getMultisetInt().begin();
				it != span.getMultisetInt().end(); it++)
			std::cout << *it << " ";

		std::cout << "\nLongest: " << span.longestSpan() << ", shortest: " << span.shortestSpan() << "\n";
	}

	{
		std::cout << "\n--------- Throwing an exception ---------\n";
		
		// Default constructor, multiset with 0 elements
		Span span;

		try
		{
			span.addNumber(1);
			std::cout << "Number succesfully added!\n";
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << "\n";
		}
	}

	{
		std::cout << "\n--------- Array of 100000 ints ---------\n";
		Span span(100000);
		
		// Functor
		FillMultiSet func(0);
		
		// Inserting in the multiset x numbers using a functor
		std::generate_n(std::inserter(span.getMultisetInt(), span.getMultisetInt().begin()), span.getSize(), func);

		std::cout << "Printing first 10 numbers: ";
		
		// Using a pair so we can check if we don't go futher than the end of the set when printing first 10 elements
		for (std::pair<int, std::multiset<int>::iterator> i(0, span.getMultisetInt().begin());
				i.first < 10 && i.second != span.getMultisetInt().end(); i.first++, i.second++)
			std::cout << *i.second << " ";
			
		std::cout << "\nLongest: " << span.longestSpan() << ", shortest: " << span.shortestSpan() << "\n";
	}

	{
		std::cout << "\n--------- Tests from subject ---------\n";
		Span sp = Span(5);
		
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	
	return (0);
}