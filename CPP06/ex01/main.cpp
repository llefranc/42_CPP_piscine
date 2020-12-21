/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:31:19 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/21 18:38:07 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reinterpret_cast.hpp"

void	gen8RandAlphaNum(char* addr)
{
	const std::string alphaNum = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

	for (int i = 0; i < 8; i++)
	{
		*addr = alphaNum[rand() % (alphaNum.size() - 1)];
		std::cout << *addr++;
	}
	std::cout << std::endl;
}

void	genRandInt(char* addr)
{
	*(reinterpret_cast<int*>(addr)) = rand();
	std::cout << *(reinterpret_cast<int*>(addr)) << std::endl;
}

void*	serialize(void)
{
	void* raw = new char[20];
	
	std::cout << "First alphanum series: ";
	gen8RandAlphaNum(reinterpret_cast<char*>(raw));
	std::cout << "Random int: ";
	genRandInt(reinterpret_cast<char*>(raw) + 8);
	std::cout << "Second alphanum series: ";
	gen8RandAlphaNum(reinterpret_cast<char*>(raw) + 12);
	
	return (raw);
}

t_data*	deserialize(void* raw)
{
	char* rawPtr = reinterpret_cast<char*>(raw);
	t_data* ptr = new t_data;
	
	ptr->s1.resize(9);
	ptr->s2.resize(9);
	
	for (int i = 0; i < 8; i++)
		ptr->s1[i] = *rawPtr++;
	ptr->s1[8] = '\0';
	
	ptr->n = *(reinterpret_cast<int*>(rawPtr));
	rawPtr += 4;
	
	for (int i = 0; i < 8; i++)
		ptr->s2[i] = *rawPtr++;
	ptr->s2[8] = '\0';
	
	return (ptr);
}

int main()
{
	srand(time(0));
	
	std::cout << "----- Serializing -----\n";
	void *raw = serialize();

	std::cout << "\n----- Deserializing -----\n";
	t_data *dataPtr = deserialize(raw);
	
	std::cout << "First alphanum series: " << dataPtr->s1 << "\n";
	std::cout << "Random int: " << dataPtr->n << "\n";
	std::cout << "Second alphanum series: " << dataPtr->s2 << "\n";
	
	delete[] reinterpret_cast<char*>(raw);
	
	return (0);
}