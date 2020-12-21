/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:33:03 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/15 15:02:12 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad() :
	_nbUnits(0), _squad(0) {}

Squad::~Squad()
{
	for (int i = 0; i < _nbUnits; i++)
		delete _squad[i];
	delete[] _squad;
}

Squad::Squad(const Squad& copyObj) : _nbUnits(copyObj._nbUnits)
{
	_squad = new ISpaceMarine* [copyObj._nbUnits];
	for (int i = 0; i < copyObj._nbUnits; i++)
		_squad[i] = copyObj._squad[i]->clone();
}

Squad& Squad::operator=(Squad assignObj)
{
	swap(*this, assignObj);
	return (*this);
}

void swap(Squad& a, Squad& b)
{
	std::swap(a._nbUnits, b._nbUnits);
	std::swap(a._squad, b._squad);
}

int Squad::getCount() const
{
	return (_nbUnits);
}

ISpaceMarine* Squad::getUnit(int index) const
{
	if (index > _nbUnits)
		return (0);
	return (_squad[index]);
}

int Squad::push(ISpaceMarine* newUnit)
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