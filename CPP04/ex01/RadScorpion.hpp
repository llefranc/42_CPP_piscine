/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:28:32 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 12:33:41 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
#define RADSCORPION_HPP

#include "Enemy.hpp"

class RadScorpion : public Enemy
{
	public:

		RadScorpion();
		virtual ~RadScorpion();

		RadScorpion(const RadScorpion& copyObj);
		RadScorpion& operator=(RadScorpion assignObj);
		friend void swap(RadScorpion& a, RadScorpion& b);
};

#endif