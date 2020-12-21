/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:13:44 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/12 10:47:57 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
#define PEON_HPP

#include <iostream>
#include <string>

#include "Victim.hpp"

class Peon : public Victim
{
	public:

		Peon(const std::string& = "Jimmy");
		Peon(const Peon& copyObj);
		virtual ~Peon();
		Peon& operator=(Peon assignObj);

		virtual void getPolymorphed() const;

		friend void swap(Peon& a, Peon& b);
};

#endif