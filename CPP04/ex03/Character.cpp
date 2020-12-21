/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:22:04 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 22:59:03 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string& name) :
	ICharacter(), _name(name), _maxNbOfMaterias(4)
{
	for (int i = 0; i < _maxNbOfMaterias; i++)
		_arrayOfMaterias[i] = 0;
}

Character::~Character()
{
	for (int i = 0; i < _maxNbOfMaterias; i++)
		delete _arrayOfMaterias[i];
}

Character::Character(const Character& copyObj) :
	ICharacter(copyObj), _name(copyObj._name), _maxNbOfMaterias(copyObj._maxNbOfMaterias)
{
	for (int i = 0; i < _maxNbOfMaterias; i++)
	{
		if (copyObj._arrayOfMaterias[i])
			_arrayOfMaterias[i] = copyObj._arrayOfMaterias[i]->clone();
		else
			_arrayOfMaterias[i] = 0;
	}
}

Character& Character::operator=(Character assignObj)
{
	swap(*this, assignObj);
	return (*this);
}

void swap(Character& a, Character& b)
{
	std::swap(a._name, b._name);
	std::swap(a._maxNbOfMaterias, a._maxNbOfMaterias);
	std::swap(a._arrayOfMaterias, b._arrayOfMaterias);
}

const std::string& Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	int i = 0;
	
	while (i < _maxNbOfMaterias && _arrayOfMaterias[i])
		i++;
	if (i == _maxNbOfMaterias)
		return ;
	_arrayOfMaterias[i] = m;
}

void Character::unequip(int idx)
{
	if (idx >= _maxNbOfMaterias || !_arrayOfMaterias[idx])
		return ;
	_arrayOfMaterias[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= _maxNbOfMaterias || !_arrayOfMaterias[idx])
		return ;
	_arrayOfMaterias[idx]->use(target);
}