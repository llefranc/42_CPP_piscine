/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:53:23 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/02 17:27:00 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
	
		std::string m_name;   //name of the human
		Weapon* m_weapon;     //storing weapon as ptr so we can have a default constructor
                              //which doesn't need a weapon as arg (and ptr is set to 0)
	public:

		HumanB(std::string name);
		HumanB(std::string name, Weapon *weapon);

		void attack() const;
		void setWeapon(Weapon &newWeapon);
};

#endif