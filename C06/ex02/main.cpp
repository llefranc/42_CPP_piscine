/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:44:57 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/21 18:07:14 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <time.h>

#include "Base.hpp"

Base* generate(void)
{
	int	nb = rand() % 3;

	if (!nb)
	{
		std::cout << "Class A created\n";
		return new A;
	}
	else if (nb == 1)
	{
		std::cout << "Class B created\n";
		return new B;
	}
	std::cout << "Class C created\n";
	return new C;
}

void identify_from_pointer(Base* p)
{
	A* ptrA = dynamic_cast<A*>(p);
	if (ptrA)
	{
		std::cout << "Identify from pointer: this is class A\n";
		return ;
	}
	
	B* ptrB = dynamic_cast<B*>(p);
	if (ptrB)
	{
		std::cout << "Identify from pointer: this is class B\n";
		return ;
	}

	C* ptrC = dynamic_cast<C*>(p);
	if (ptrC)
		std::cout << "Identify from pointer: this is class C\n";
}

void identify_from_reference(Base& p)
{
	try
	{
		A& refA = dynamic_cast<A&>(p);
		(void)refA;
		std::cout << "Identify from reference: this is class A\n";
		return ;
	}
	catch (std::bad_cast) {}
	
	try
	{
		B& refB = dynamic_cast<B&>(p);
		(void)refB;
		std::cout << "Identify from reference: this is class B\n";
		return ;
	}
	catch (std::bad_cast) {}

	try
	{
		C& refC = dynamic_cast<C&>(p);
		(void)refC;
		std::cout << "Identify from reference: this is class C\n";
	}
	catch (std::bad_cast) {}
}

int main()
{	
	srand(time(0));
	
	Base *ptr = generate();
	
	identify_from_pointer(ptr);
	identify_from_reference(*ptr);
	
	return (0);
}
