/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:06:34 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 21:11:32 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
	
		std::string		_type;
		unsigned int	_xp;
	
	public:
	
		AMateria(const std::string& type);
		virtual ~AMateria();
		
		AMateria(const AMateria& copyObj);
		AMateria& operator=(const AMateria& assignObj);
		friend void swap(AMateria& a, AMateria& b);
		
		std::string const & getType() const; //Returns the materia type
		unsigned int getXP() const; //Returns the Materia's XP
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif