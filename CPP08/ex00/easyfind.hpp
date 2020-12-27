/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 17:52:27 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/27 18:43:58 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template<typename T>
typename T::iterator easyfind(T& cont, int n)
{
	typename T::iterator it = std::find(cont.begin(), cont.end(), n);
	if (it == cont.end())
		throw std::exception();
	return (it);
}

#endif