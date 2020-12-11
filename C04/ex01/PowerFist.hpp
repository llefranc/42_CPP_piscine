/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:30:16 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 12:18:53 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
#define POWERFIST_HPP

#include <iostream>

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
	public:

		PowerFist(const std::string& name = "Power Fist", int damage = 50, int apCost = 8);
		virtual ~PowerFist();
		
		PowerFist(const PowerFist& copyObj);
		PowerFist& operator=(PowerFist assignObj);
		friend void swap(PowerFist& a, PowerFist& b);

		virtual void attack() const;
};

#endif