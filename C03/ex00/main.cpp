/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:20:46 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/08 21:07:29 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "FragTrap.hpp"

int main()
{
	FragTrap idiot;
	
	// For generating random numbers in vaulthunterDotExe 
	srand(time(NULL));
	
	idiot.meleeAttack("Handsome Jack");
	idiot.rangedAttack("Handsome Jack");
	std::cout << std::endl;

	idiot.takeDamage(1);
	idiot.takeDamage(40);
	idiot.beRepaired(30);
	idiot.beRepaired(100);
	
	std::cout << std::endl;
	idiot.vaulthunterDotExe("Handsome Jack");
	idiot.vaulthunterDotExe("Baron Flynt");
	idiot.vaulthunterDotExe("Roid Rage Psycho");
	idiot.vaulthunterDotExe("Pinky");
	idiot.vaulthunterDotExe("Mad Mel");
	
	std::cout << std::endl;
	idiot.beRecharged(50);
	idiot.beRecharged(100);
	
	return (0);
}