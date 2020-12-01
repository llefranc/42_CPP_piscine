/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:24:52 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/01 12:47:09 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pony.hpp"

Pony::Pony(std::string color, bool sex, int weight) : m_color(color), m_sex(sex), m_weight(weight) {}

bool Pony::get_sex()
{
	return (m_sex);
}

int Pony::get_weight()
{
	return (m_weight);
}