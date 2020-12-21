/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 14:45:31 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/10 17:12:31 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <iostream>
#include <string>

#include "Victim.hpp"

class Sorcerer
{
	private:

		std::string _name;
		std::string _title;

	public:
	
		Sorcerer(const std::string& name = "Bob", const std::string& title = "Poor wizard");
		Sorcerer(const Sorcerer& copyObj);
		~Sorcerer();
		Sorcerer& operator=(Sorcerer copyObj);
		
		const std::string& getName() const;
		const std::string& getTitle() const;
		void polymorph(const Victim& victim) const;
		
		friend void swap(Sorcerer& a, Sorcerer& b);
};

std::ostream& operator<<(std::ostream &output, const Sorcerer &sorcerer);

#endif