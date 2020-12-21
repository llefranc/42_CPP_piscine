/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:47:17 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 14:51:03 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>

#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
	private:
	
		std::string		_name;
		int				_actionPoints;
		AWeapon*		_characWeapon;	
	
	public:
	
		Character(const std::string& name = "Doom Slayer", unsigned int actionPoints = 40,
			AWeapon* _characWeapon = 0);
		~Character();
		
		Character(const Character& copyObj);
		Character& operator=(Character assignObj);
		friend void swap(Character& a, Character& b);
		
		const std::string& getName() const;
		int getAp() const;
		AWeapon* getWeapon() const;
		
		void recoverAP();
		void equip(AWeapon* aWeapon);
		void attack(Enemy* enemy);
};

std::ostream& operator<<(std::ostream& output, Character& character);


#endif