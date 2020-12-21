/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:20:46 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/09 19:33:31 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main()
{
	// For generating random numbers in vaulthunterDotExe and challengeNewcomer
	srand(time(0));
	
	// NinjaTrap object needed for special attack of SuperTrap
	NinjaTrap idiot("idiot");
	
	// Building SuperTrap using virtual classes (diamond problem)
	// >> each constructor is only called once : ClapTrap, FragTrap, NinjaTrap, SuperTrap
	SuperTrap retard("retard");
	std::cout << "\n\n";

	// Demonstrating Supertrap attributes are correctly initialized
	retard.printattr();
	std::cout << "\n\n";

	// Demonstrating Supertrap inherited methods from both classes
	retard.rangedAttack("Handsome Jack");                   // FragTrap ranged attack
	retard.meleeAttack("Handsome Jack");                    // NinjaTrap melee attack
	retard.ninjaShoebox(idiot);                             // NinjaTrap special attack
	retard.vaulthunterDotExe("Handsome Jack");              // FragTrap special attack
	std::cout << std::endl;
	
	return (0);
}