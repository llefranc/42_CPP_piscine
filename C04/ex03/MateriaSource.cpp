/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 22:00:53 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 22:15:03 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() :
	IMateriaSource(), _maxNbOfSources(4)
{
	for (int i = 0; i < _maxNbOfSources; i++)
		_sources[i] = 0;
}
	
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < _maxNbOfSources; i++)
		delete _sources[i];
}

MateriaSource::MateriaSource (const MateriaSource& copyObj) :
	IMateriaSource(copyObj)
{
	for (int i = 0; i < _maxNbOfSources; i++)
		_sources[i] = copyObj._sources[i]->clone();
}
MateriaSource& MateriaSource::operator=(MateriaSource assignObj)
{
	swap(*this, assignObj);
	return (*this);
}

void swap(MateriaSource& a, MateriaSource& b)
{
	std::swap(a._maxNbOfSources, b._maxNbOfSources);
	std::swap(a._sources, b._sources);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	int i = 0;
	while (i < _maxNbOfSources && _sources[i])
		i++;
	
	if (i == _maxNbOfSources)
		return ;
	_sources[i] = materia->clone();
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	int i = 0;
	while (i < _maxNbOfSources && (_sources[i]->getType() != type))
		i++;
	
	if (i == _maxNbOfSources)
		return (0);
	return (_sources[i]->clone());
}
