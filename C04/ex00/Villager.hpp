/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Villager.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:13:44 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/15 12:39:55 by heleneherin      ###   ########.fr       */
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