/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:13:44 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/10 17:46:48 by lucaslefran      ###   ########.fr       */
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
		~Peon();
		Peon& operator=(Peon assignObj);

		void getPolymorphed() const;

		friend void swap(Peon& a, Peon& b);
};

#endif