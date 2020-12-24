/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:12:26 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/21 23:57:10 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template<typename T, typename F>
void iter(T t[], int size, F func)
{
	for (int i = 0; i < size; i++)
		func(t[i]);
}

template<typename T>
void inc(T &t)
{
	t++;
}

#endif