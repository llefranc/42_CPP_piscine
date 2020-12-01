/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:24:52 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/01 18:50:04 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pony.hpp"

//Default constructor
Pony::Pony() : m_color("black"), m_weight(400), m_gender(0)
{
	std::cout << "In default constructor : pony created\n";
}

//Constructor, gender value is optional
Pony::Pony(std::string color, int weight, bool gender = MALE) :
		m_color(color), m_weight(weight), m_gender(gender)
{
	std::cout << "In constructor : pony created\n";
}

//Destructor
Pony::~Pony()
{
	std::cout << "In destructor : pony destructed\n";
}

//Returns a string containing the gender of the pony
std::string Pony::get_gender() const
{
	if (m_gender == FEMALE)
		return ("female");
	return ("male");
}

//Returns the weight of the pony as an int
int Pony::get_weight() const
{
	return (m_weight);
}

//The pony jumps and loses weight (1kg)
void Pony::jump()
{
	std::cout << "The pony jumped ! It lost 1 kg\n";
	m_weight--;
}

//The pony runs and loses weight (3kg)
void Pony::run()
{
	std::cout << "The pony ran for 100 meters ! It lost 3 kg\n";
	m_weight -= 3;
}