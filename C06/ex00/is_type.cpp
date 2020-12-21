/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_type.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:28:09 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/18 17:27:11 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "static_cast.hpp"

bool isDigits(const std::string& str)
{
    return (str.find_first_not_of("0123456789") == std::string::npos);
}

bool noIntOverflow(const std::string& line, char sign)
{
	int size = line.size();
	if (line[0] == '-')
		size--;
		
	if (size > 10 || (atoi(line.c_str()) > 0 && sign == '-') ||
			(atoi(line.c_str()) < 0 && sign != '-'))
		return (0);
	return (1);
}

/*
* Returns 1 if the string is an int (and between INT_MAX / INT_MIN).
*/
bool isInt(const std::string& str)
{
	std::string digitsPart(str);
	
	if (str[0] == '-' && str[1] != '\0')
		digitsPart = str.substr(1, std::string::npos);
		
	if (isDigits(digitsPart) && noIntOverflow(str, str[0]))
		return (1);
	return (0);
}

/*
* Returns 1 if the string contains only one char displayable on the screen.
*/
bool isChar(const std::string& line)
{
	if (line[1] == '\0' && (line[0] >= 32 && line[0] <= 126))
		return (1);
	return (0);
}

/*
* Returns 1 if the string is a float with a format like : 42.0f.
*/
bool isFloat(const std::string& line)
{
	if (line == "nanf" || line == "+inff" || line == "-inff")
		return (1);
	
	// First charac must be '-' followed by a number or a digit
	if ((line[0] == '-' && !isdigit(line[1])) || (line[0] != '-' && !isdigit(line[0])))
		return (0);
	
	// Str without '-' sign if it was present
	std::string digitsPart(line);
	if (line[0] == '-')
		digitsPart = line.substr(1, std::string::npos);

	// First charac (or first after '-') must be a digit
	if (!isdigit(digitsPart[0]))
		return (0);

	int i = 0;
	bool dot = 0;
	while (digitsPart[++i])
	{
		// If we meet a dot for the first time and it's surrounded by digits
		if (digitsPart[i] == '.' && !dot && isdigit(digitsPart[i - 1]) && isdigit(digitsPart[i + 1]))
			dot = 1;
			
		// If we meet a 'f' at the end and the number is correct >> it's a float
		else if (digitsPart[i] == 'f' && isdigit(digitsPart[i - 1]) && digitsPart[i + 1] == '\0')
			return (1);
			
		// If we already met a dot : not a float
		else if (digitsPart[i] == '.' || !isdigit(digitsPart[i]))
			return (0);
	}
	// No 'f' at the end of the string
	return (0);
}

/*
* Returns 1 if the string is a float with a format like : 42.0.
*/
bool isDouble(const std::string& line)
{
	if (line == "nan" || line == "+inf" || line == "-inf")
		return (1);
	
	// First charac must be '-' followed by a number or a digit
	if ((line[0] == '-' && !isdigit(line[1])) || (line[0] != '-' && !isdigit(line[0])))
		return (0);
	
	// Str without '-' sign if it was present
	std::string digitsPart(line);
	if (line[0] == '-')
		digitsPart = line.substr(1, std::string::npos);

	// First charac (or first after '-') must be a digit
	if (!isdigit(digitsPart[0]))
		return (0);

	int i = 0;
	bool dot = 0;
	while (digitsPart[++i])
	{
		// If we meet a dot for the first time and it's surrounded by digits
		if (digitsPart[i] == '.' && !dot && isdigit(digitsPart[i - 1]) && isdigit(digitsPart[i + 1]))
			dot = 1;
			
		// If we already met a dot : not a float
		else if (digitsPart[i] == '.' || !isdigit(digitsPart[i]))
			return (0);
	}
	if (!dot)
		return (0);
	return (1);
}