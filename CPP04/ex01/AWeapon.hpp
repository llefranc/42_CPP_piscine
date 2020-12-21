/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:07:49 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 12:18:39 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <string>

class AWeapon
{
	protected:

		std::string		_name;
		unsigned int	_damage;
		unsigned int	_apCost;
		
	public:

		AWeapon(const std::string& name, int damage, int apCost);
		virtual ~AWeapon();
		
		AWeapon(const AWeapon& copyObj);
		AWeapon& operator=(const AWeapon& assignObj);
		friend void swap(AWeapon& a, AWeapon& b);

		const std::string& getName() const;
		int getAPCost() const;
		int getDamage() const;
		virtual void attack() const = 0;
};

#endif