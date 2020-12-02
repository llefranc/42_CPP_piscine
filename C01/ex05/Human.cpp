/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:40:25 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/02 16:15:06 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

//Returns the adress of Brain object inside Human class
std::string Human::identify() const
{
	return (m_brain.identify());
}

//Returns a ref to Brain object inside Human class
const Brain& Human::getBrain() const
{
	return (m_brain);
}