/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:20:40 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/02 15:39:54 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <sstream>
#include <iostream>

class Brain
{
	private:

		int	m_nbOfNeurons;
		int m_weight;

	public:
	
		Brain();
		std::string identify() const;
		int getNbOfNeurons() const;
		int getWeight() const;
};

#endif