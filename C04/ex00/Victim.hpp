/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VIctim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:56:50 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/12 10:47:51 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <string>
#include <iostream>

class Victim
{
	protected:
	
		std::string _name;
	
	public:	

		Victim(const std::string& name = "Bobby");
		Victim(const Victim& copyObj);
		virtual ~Victim();
		Victim& operator=(Victim assignObj);

		const std::string& getName() const;
		virtual void getPolymorphed() const;

		friend void swap(Victim& a, Victim& b);
};

std::ostream& operator<<(std::ostream& output, const Victim& victim);

#endif