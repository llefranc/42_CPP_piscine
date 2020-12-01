/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:19:18 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/01 12:48:04 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
#define PONY_HPP

#include <string>
#include <iostream>

#define FEMALE 0
#define MALE 1

class Pony
{
	private:
	
		std::string m_color;
		bool		m_sex;
		int			m_weight;
		
	public:
		
		Pony(std::string color = "black", bool sex = MALE, int weight = 400);
		bool get_sex();
		int get_weight();
		// Pony(std::string m_color, bool m_sexe, int m_weight);
		// Pony(std::string m_color, bool m_sexe, int m_weight);
		// Pony(std::string m_color, bool m_sexe, int m_weight);
};

#endif