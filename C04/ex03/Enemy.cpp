/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:38:45 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/16 11:41:37 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(const std::string& name) :
	ICharacter(), _name(name), _maxNbOfMaterias(4)
{
	for (int i = 0; i < _maxNbOfMaterias; i++)
		_arrayOfMaterias[i] = 0;
}

Enemy::~Enemy()
{
	for (int i = 0; i < _maxNbOfMaterias; i++)
		delete _arrayOfMaterias[i];
}

Enemy::Enemy(const Enemy& copyObj) :
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

Enemy& Enemy::operator=(Enemy assignObj)
{
	swap(*this, assignObj);
	return (*this);
}

void swap(Enemy& a, Enemy& b)
{
	std::swap(a._name, b._name);
	std::swap(a._maxNbOfMaterias, a._maxNbOfMaterias);
	std::swap(a._arrayOfMaterias, b._arrayOfMaterias);
}

const std::string& Enemy::getName() const
{
	return (_name);
}

void Enemy::equip(AMateria* m)
{
	int i = 0;
	
	while (i < _maxNbOfMaterias && _arrayOfMaterias[i])
		i++;
	if (i == _maxNbOfMaterias)
		return ;
	std::cout << "The bad guy is equipping " << m->getType() << "!\n";
	_arrayOfMaterias[i] = m;
}

void Enemy::unequip(int idx)
{
	if (idx >= _maxNbOfMaterias || !_arrayOfMaterias[idx])
		return ;
	_arrayOfMaterias[idx] = 0;
}

void Enemy::use(int idx, ICharacter& target)
{
	if (idx >= _maxNbOfMaterias || !_arrayOfMaterias[idx])
		return ;
	std::cout << "The bad guy is using " << _arrayOfMaterias[idx]->getType() << "!\n";
	_arrayOfMaterias[idx]->use(target);
}
