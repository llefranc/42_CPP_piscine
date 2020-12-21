/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Villager.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:13:44 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/16 16:16:57 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VILLAGER_HPP
#define VILLAGER_HPP

#include <iostream>
#include <string>

#include "Victim.hpp"

class Villager : public Victim
{
	public:

		Villager(const std::string& = "Kyle");
		Villager(const Villager& copyObj);
		virtual ~Villager();
		Villager& operator=(Villager assignObj);

		virtual void getPolymorphed() const;

		friend void swap(Villager& a, Villager& b);
};

#endif