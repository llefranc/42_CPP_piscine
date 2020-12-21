/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:58:43 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 12:18:13 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <string>

class Enemy
{
	protected:

		int				_hp;
		std::string		_type;

	public:
	
		Enemy(int hp = 100, const std::string& type = "guard");
		virtual ~Enemy();
		
		Enemy(const Enemy& copyObj);
		Enemy& operator=(Enemy assignObj);
		friend void swap(Enemy& a, Enemy& b);
		
		const std::string& getType() const;
		int getHP() const;
		virtual void takeDamage(int amount);	
		
};

#endif