/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:54:32 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/02 17:27:58 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : m_name(name), m_weapon(0) {}

HumanB::HumanB(std::string name, Weapon *weapon) : m_name(name), m_weapon(weapon) {}

//Prints on cout a message of this human attacking with his weapon
void HumanB::attack() const
{
	std::cout << m_name << " attacks with this " << m_weapon->getType() << std::endl;
}

//Sets a new weapon (ptr pointing to newWeapon)
void HumanB::setWeapon(Weapon &newWeapon)
{
	m_weapon = &newWeapon;
}