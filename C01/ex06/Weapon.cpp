/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:46:35 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/02 17:24:58 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : m_type(type) {}

//Returns a const string containing the type of weapon
const std::string& Weapon::getType() const
{
	return (m_type);
}

//Sets a new type of weapon
void Weapon::setType(std::string newType)
{
	m_type = newType;
}