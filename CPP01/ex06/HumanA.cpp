/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:54:32 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/02 17:28:15 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, const Weapon& weapon) : m_name(name), m_weapon(weapon) {}

//Prints on cout a message of this human attacking with his weapon
void HumanA::attack() const
{
	std::cout << m_name << " attacks with this " << m_weapon.getType() << std::endl;
}