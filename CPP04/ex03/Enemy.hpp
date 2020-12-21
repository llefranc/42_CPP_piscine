/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:38:46 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/16 11:40:07 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>
#include <iostream>

#include "ICharacter.hpp"

class Enemy : public ICharacter
{
	private:

		std::string	_name;
		int			_maxNbOfMaterias;
		AMateria*	_arrayOfMaterias[4];
	
	public:

		Enemy(const std::string& name = "Pedro");
		~Enemy();

		Enemy(const Enemy& copyObj);
		Enemy& operator=(Enemy assignObj);
		friend void swap(Enemy& a, Enemy& b);

		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
	
};

#endif
