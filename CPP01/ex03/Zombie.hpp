/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:16:01 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/03 12:52:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Zombie
{
	private:
		
		std::string m_name;
		std::string m_type;

	public:
		
		Zombie();
		Zombie(std::string name, std::string type);
		
		void announce() const;
		std::string getName() const;
		void setName(std::string const &newName);
};

#endif