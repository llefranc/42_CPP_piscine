/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:16:01 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/02 13:02:24 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

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