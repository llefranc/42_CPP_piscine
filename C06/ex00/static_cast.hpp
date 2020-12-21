/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_cast.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:28:59 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/21 16:24:07 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATIC_CAST_HPP
#define STATIC_CAST_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <iomanip>

typedef struct	s_nb
{
		char	nbChar;
		int		nbInt;
		float	nbFloat;
		double	nbDouble;
}				t_nb;


// is_type.cpp

bool isChar(const std::string& line);
bool isInt(const std::string& str);
bool isFloat(const std::string& line);
bool isDouble(const std::string& line);


// transf.cpp

void printNb(const t_nb& allNb);
void transfInt(int nb);
void transfChar(char nb);
void transfFloat(float nb);
void transfDouble(double nb);


#endif