/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 11:23:04 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/11/28 12:30:01 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>

#define WELCOMING_MSG "Welcome to the phonebook !\n-------------------\n\n"

class contact {
	private:
	
		std::string info[11];
		std::string field_name[11];
		
	public:
	
		contact();
		void	add_contact();
		void	print_contact();
		void	print_search(int index);
};

#endif