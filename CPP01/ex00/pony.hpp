/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:19:18 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/01 18:38:14 by lucaslefran      ###   ########.fr       */
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
		int			m_weight;
		bool		m_gender;
		
	public:
		
		Pony();
		Pony(std::string color, int weight, bool gender);
		~Pony();
		
		std::string get_gender() const;
		int get_weight() const;
		void jump();
		void run();
};

#endif