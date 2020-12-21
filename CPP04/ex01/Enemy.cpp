/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:58:24 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/11 14:55:57 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

// Default constructor
Enemy::Enemy(int hp, const std::string& type) :
	_hp(hp), _type(type) {}

// Destructor
Enemy::~Enemy() {}

// Copy constructor
Enemy::Enemy(const Enemy& copyObj) :
	_hp(copyObj._hp), _type(copyObj._type) {}

// Assignment operator= with copy and swap idiom
Enemy& Enemy::operator=(Enemy assignObj)
{
	swap(*this, assignObj);
	return (*this);
}

// Useful for assignment operator=
void swap(Enemy& a, Enemy& b)
{
	std::swap(a._hp, b._hp);
	std::swap(a._type, b._type);
}

const std::string& Enemy::getType() const
{
	return (_type);
}

int Enemy::getHP() const
{
	return (_hp);
}

void Enemy::takeDamage(int amount)
{
	if (amount < 0)
		return ;
	if (amount > _hp)
		amount = _hp;
	_hp -= amount;
}
