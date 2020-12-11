/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:54:31 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 22:15:56 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:

		int			_maxNbOfSources;
		AMateria*	_sources[4];
	
	public:
	
		MateriaSource();
		virtual ~MateriaSource();
		
		MateriaSource (const MateriaSource& copyObj);
		MateriaSource& operator=(MateriaSource assignObj);
		friend void swap(MateriaSource& a, MateriaSource& b);
		
		virtual void learnMateria(AMateria* materia);
		virtual AMateria* createMateria(const std::string& type);
};

#endif