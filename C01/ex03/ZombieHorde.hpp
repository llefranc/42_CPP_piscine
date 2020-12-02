/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:52:20 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/02 13:23:43 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde
{
	private:

		int m_nbZombie;           //nb of zombie if zombieArray
		Zombie *m_zombieArray;    //will contain n Zombie object
		std::string m_names[5];   //pool of names for giving random names

	public:	

		ZombieHorde(unsigned int const);
		~ZombieHorde();
		
		void announce () const;
};

#endif