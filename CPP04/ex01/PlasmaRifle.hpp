/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:07:49 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 12:19:31 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
#define PLASMARIFLE_HPP

#include <string>
#include <iostream>

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
	public:

		PlasmaRifle(const std::string& name = "Plasma Rifle", int damage = 21, int apCost = 5);
		virtual ~PlasmaRifle();

		PlasmaRifle(const PlasmaRifle& copyObj);
		PlasmaRifle& operator=(PlasmaRifle assignObj);
		friend void swap(PlasmaRifle& a, PlasmaRifle& b);

		virtual void attack() const;
};

#endif