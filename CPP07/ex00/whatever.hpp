/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:44:37 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/24 14:02:59 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T& max(T& a, T& b)
// T max(const T& a, const T& b)
{
	if (a < b)
		return (b);
	else if (b < a)
		return (a);
	return (b);
}

template<typename T>
T& min(T& a, T& b)
{
	if (a < b)
		return (a);
	else if (b < a)
		return (b);
	return (b);
}

#endif