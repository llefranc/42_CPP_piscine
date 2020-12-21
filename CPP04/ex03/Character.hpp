/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:17:41 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 22:50:35 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <iostream>

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:

		std::string	_name;
		int			_maxNbOfMaterias;
		AMateria*	_arrayOfMaterias[4];
	
	public:

		Character(const std::string& name = "Bob");
		~Character();

		Character(const Character& copyObj);
		Character& operator=(Character assignObj);
		friend void swap(Character& a, Character& b);

		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
	
};

#endif