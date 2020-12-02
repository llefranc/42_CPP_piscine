/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:16:01 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/02 12:27:43 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		
		std::string m_name;   //name of the zombie
		std::string m_type;   //type of the zombie

	public:
		
		Zombie();
		Zombie(std::string name, std::string type);
		
		void announce() const;
		std::string getName() const;
};

#endif