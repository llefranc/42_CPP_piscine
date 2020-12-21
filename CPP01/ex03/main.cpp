/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:42:21 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/02 15:13:12 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

int main()
{
	std::cout << "Creating a horde of 4 zombies :\n";
	ZombieHorde zombieHorde(4);
	zombieHorde.announce();
	
	std::cout << "\n\nCreating a horde of 6 zombies :\n";
	ZombieHorde zombieHorde2(6);
	zombieHorde2.announce();
	return (0);
}