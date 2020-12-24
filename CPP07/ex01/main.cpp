/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:12:13 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/24 10:13:05 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "iter.hpp"

void incInt(int &a)
{
	a++;
}

void decInt(int &a)
{
	a--;
}

void incFl(float &a)
{
	a += 1.0;
}

void decFl(float &a)
{
	a -= 1.0;
}

int main()
{
	int array[3] = {1, 2, 3};
	float arrayF[3] = {1.5, 2.5, 3.5};

	// Incrementing int with int function
	iter(array, 3, incInt);
	
	std::cout << "Int array after iter: ";
	for (int i = 0; i < 3; i++)
		std::cout << array[i] << " ";
	std::cout << "\n";
	
	
	// Incrementing float with float function
	iter(arrayF, 3, incFl);
	
	std::cout << "Float array after iter: ";
	for (int i = 0; i < 3; i++)
		std::cout << arrayF[i] << " ";
	std::cout << "\n";


	// Incrementing int with template function
	iter(array, 3, inc<int>);
	
	std::cout << "Int array after iter: ";
	for (int i = 0; i < 3; i++)
		std::cout << array[i] << " ";
	std::cout << "\n";
	
	
	// Incrementing float with template function
	iter<float, void(float &)>(arrayF, 3, inc);

	std::cout << "Float array after iter: ";
	for (int i = 0; i < 3; i++)
		std::cout << arrayF[i] << " ";
	std::cout << "\n";
	
	return (0);
}