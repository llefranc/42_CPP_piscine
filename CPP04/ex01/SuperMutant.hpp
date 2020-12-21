/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:14:00 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 12:32:32 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
#define SUPERMUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy
{
	public:

		SuperMutant();
		virtual ~SuperMutant();
		
		SuperMutant(const SuperMutant& copyObj);
		SuperMutant& operator=(SuperMutant AssignObj);
		friend void swap(SuperMutant& a, SuperMutant& b);
	
		virtual void takeDamage(int amount);
};

#endif