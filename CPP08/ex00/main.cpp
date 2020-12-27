/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 17:50:50 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/27 18:52:10 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <vector>
#include <queue>
#include <list>

#include <iostream>

int main()
{
	// Using template function and vector
	try
	{
		std::cout << "Template with vector container: ";
		
		std::vector<int> intVec(10, 1);
		
		intVec.push_back(3);
		intVec.push_back(2);
		intVec.push_back(4);
		
		std::vector<int>::iterator it = easyfind(intVec, 3);
		std::cout << *it << "\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}

	// Using template function and deque
	try
	{
		std::cout << "Template with deque container: ";
		
		std::deque<int> intDeque(10, 1);
		
		intDeque.push_back(3);
		intDeque.push_back(2);
		intDeque.push_back(2);
		intDeque.push_back(4);
		
		std::deque<int>::iterator it = easyfind(intDeque, 2);
		
		std::cout << *it << ", then incrementing the iterator returned and printing value: ";
		it++;
		std::cout << *it << ", and again: ";
		it++;
		std::cout << *it << "\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}

	// Using template function and list, then throwing an exception
	try
	{
		std::cout << "Template with stack container: ";

		std::list<int> intList;

		intList.push_back(1);
		intList.push_back(8);
		intList.pop_back();
		intList.push_back(3);
		
		std::list<int>::iterator it = easyfind(intList, 3);
		std::cout << *it << ", and then throwing an exception (trying to find the value = 8): ";
		it = easyfind(intList, 8);
		std::cout << *it << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	// Throwing an exception
	try
	{
		std::cout << "Throwing an exception (trying to find the value : 100000): ";
		
		std::vector<int> intVec(10, 1);
		
		intVec.push_back(3);
		intVec.push_back(2);
		intVec.push_back(4);
		
		std::vector<int>::iterator it = easyfind(intVec, 100000);
		std::cout << *it << "\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	
	return (0);
}