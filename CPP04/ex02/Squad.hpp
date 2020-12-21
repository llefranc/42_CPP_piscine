/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:27:06 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 16:58:46 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
#define SQUAD_HPP

#include <iostream>
#include <string>

#include "ISquad.hpp"

class Squad : public ISquad
{
	private:

		int				_nbUnits;
		ISpaceMarine**	_squad;
	
	public:
	
		Squad();
		virtual ~Squad();
		
		Squad(const Squad& copyObj);
		Squad& operator=(Squad assignObj);
		friend void swap(Squad& a, Squad& b);
		
		virtual int getCount() const;
		virtual ISpaceMarine* getUnit(int index) const;
		virtual int push(ISpaceMarine* newUnit);
};

#endif