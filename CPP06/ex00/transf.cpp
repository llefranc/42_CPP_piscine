/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transf.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 10:56:12 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/22 11:26:07 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "static_cast.hpp"

/*
* Prints the 4 differents types and conversions. If a conversion overflowed,
* prints a specific message to indicate it.
*/
void printNb(const t_nb& allNb)
{
	// Printing char and taking care of overflows during cast
	if ((allNb.nbChar >= 32 && allNb.nbChar <= 126) &&
			(allNb.nbDouble > 0.0 && allNb.nbDouble < static_cast<double>(std::numeric_limits<char>::max())))
		std::cout << "Char: \"" << allNb.nbChar << "\"\n";
	else if (!isnan(allNb.nbDouble) && (allNb.nbDouble >= 0.0 && allNb.nbDouble < 128.0))
		std::cout << "Char: non displayable\n";
	else
		std::cout << "Char: impossible\n";
	
	// Printing int and taking care of overflows during cast
	if ((allNb.nbDouble < 0.0 && allNb.nbDouble < static_cast<double>(std::numeric_limits<int>::min())) ||
			(allNb.nbDouble > 0.0 && allNb.nbDouble > static_cast<double>(std::numeric_limits<int>::max()))
			|| isnan(allNb.nbDouble))
		std::cout << "Int: impossible\n";
	else
		std::cout << "Int: " << allNb.nbInt << "\n";
	
	// Printing float and double
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Float: " << allNb.nbFloat << "f\nDouble: " << allNb.nbDouble << "\n";
}

/*
* Cast nb (a double) into : a char, an int, a float and a double. Then calls
* printNb function for printing the 4 differents types.
*/
void transfInt(int nb)
{
	t_nb	allNb;

	allNb.nbChar = static_cast<char>(nb);
	allNb.nbInt = static_cast<int>(nb);
	allNb.nbFloat = static_cast<float>(nb);
	allNb.nbDouble = static_cast<double>(nb);
	
	printNb(allNb);
}

/*
* Cast nb (a double) into : a char, an int, a float and a double. Then calls
* printNb function for printing the 4 differents types. Prints an error and
* then return if strtod previously overflowed when the function was call.
*/
void transfDouble(double nb)
{
	t_nb	allNb;

	// If function strtod produced an overflow
	if (errno == ERANGE)
	{
		std::cerr << "Error: the number is incorrect, or his type is not supported\n";
		return ;
	}

	allNb.nbInt = static_cast<int>(nb);
	allNb.nbChar = static_cast<char>(nb);
	allNb.nbFloat = static_cast<float>(nb);
	allNb.nbDouble = static_cast<double>(nb);

	printNb(allNb);
}
