/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 20:02:23 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/02 12:50:02 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include "Zombie.hpp"

class ZombieEvent
{
	private:
	
		std::string m_type;
		std::string m_names[5];   //pool of names for giving random names

	public:	

		ZombieEvent();
		ZombieEvent(std::string type);

		void setZombieType(std::string const &type);
		Zombie* newZombie(std::string const &name);
		Zombie* randomChump() const;
};

#endif