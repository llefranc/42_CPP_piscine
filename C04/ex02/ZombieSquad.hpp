/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieSquad.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heleneherin <heleneherin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 15:09:29 by heleneherin       #+#    #+#             */
/*   Updated: 2020/12/15 15:10:30 by heleneherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIESQUAD_HPP
#define ZOMBIESQUAD_HPP

#include <iostream>
#include <string>

#include "ISquad.hpp"

class ZombieSquad : public ISquad
{
	private:

		int				_nbUnits;
		ISpaceMarine**	_squad;

	public:

		ZombieSquad();
		virtual ~ZombieSquad();

		ZombieSquad(const ZombieSquad& copyObj);
		ZombieSquad& operator=(ZombieSquad assignObj);
		friend void swap(ZombieSquad& a, ZombieSquad& b);

		virtual int getCount() const;
		virtual ISpaceMarine* getUnit(int index) const;
		virtual int push(ISpaceMarine* newUnit);
};

#endif