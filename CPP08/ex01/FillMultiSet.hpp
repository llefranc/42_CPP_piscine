/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FillMultiSet.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:00:22 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/28 12:19:34 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLMULTISET_HPP
#define FILLMULTISET_HPP

#include <set>

class FillMultiSet
{
	public:

		FillMultiSet(int value = 0) : _value(value) {};
		~FillMultiSet() {};

		int operator()() {return (_value++);};

	private:

		int	_value;	
};

#endif