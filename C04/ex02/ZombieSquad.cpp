/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieSquad.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 15:09:44 by heleneherin       #+#    #+#             */
/*   Updated: 2020/12/15 15:11:07 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieSquad.hpp"

ZombieSquad::ZombieSquad() :
	_nbUnits(0), _squad(0) {}

ZombieSquad::~ZombieSquad()
{
	for (int i = 0; i < _nbUnits; i++)
		delete _squad[i];
	delete[] _squad;
}

ZombieSquad::ZombieSquad(const ZombieSquad& copyObj) : _nbUnits(copyObj._nbUnits)
{
	_squad = new ISpaceMarine* [copyObj._nbUnits];
	for (int i = 0; i < copyObj._nbUnits; i++)
		_squad[i] = copyObj._squad[i]->clone();
}

ZombieSquad& ZombieSquad::operator=(ZombieSquad assignObj)
{
	swap(*this, assignObj);
	return (*this);
}

void swap(ZombieSquad& a, ZombieSquad& b)
{
	std::swap(a._nbUnits, b._nbUnits);
	std::swap(a._squad, b._squad);
}

int ZombieSquad::getCount() const
{
	return (_nbUnits);
}

ISpaceMarine* ZombieSquad::getUnit(int index) const
{
	if (index > _nbUnits)
		return (0);
	return (_squad[index]);
}

int ZombieSquad::push(ISpaceMarine* newUnit)
{
	ISpaceMarine** tmp = _squad;

	_squad = new ISpaceMarine* [_nbUnits + 1];

	// Copying previous array of ISpaceMarine + new ISpaceMarine
	for (int i = 0; i < _nbUnits; i++)
		_squad[i] = tmp[i];
	_squad[_nbUnits] = newUnit;

	_nbUnits++;
	delete[] tmp;
	return (_nbUnits);
}