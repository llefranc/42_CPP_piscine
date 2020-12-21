/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:20:24 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/02 16:16:35 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : m_nbOfNeurons(200000), m_weight(5) {}

//Returns the address of this Brain object in uppercase
std::string Brain::identify() const
{
	std::string address;
	std::stringstream ss;

	ss << this;
	address = ss.str();
	for (int i = 2; address[i]; i++)
		if (address[i] >= 'a' && address[i] <= 'z')
			address[i] -= 32;
	return (address);
}

//Returns the brain's neurons number
int Brain::getNbOfNeurons() const
{
	return (m_nbOfNeurons);
}

//Returns the brain's weight
int Brain::getWeight() const
{
	return (m_weight);
}