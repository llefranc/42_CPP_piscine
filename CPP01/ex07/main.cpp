/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:59:24 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/03 18:09:11 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

// Returns false if number of arguments isn't three and if at least one of them
// is empty.
bool checkArgs(int ac, char** av)
{
	if (ac != 4)
	{
		std::cout << "Please enter 3 arguments : filename, string to be replaced and new string\n";
		return (false);
	}
	if (!av[1][0] || !av[2][0] || !av[3][0])
	{
		std::cout << "Arguments can't be empty\n";
		return (false);
	}
	return (true);
}

// Returns a string with the content of the file
std::string getStrFromBuffer(const std::ifstream& fInput)
{
	std::stringstream buffer;
	buffer << fInput.rdbuf();
	return (buffer.str());
}

int main(int ac, char** av)
{
	if (!checkArgs(ac, av))
		return (1);
		
	// Checking if file exist and opening file
	std::ifstream fInput(av[1]);
	if (!fInput)
	{
		std::cout << "Opening file failed\n";
		return (1);
	}
	
	// Putting all the file into a string str
	std::string str(getStrFromBuffer(fInput));
	fInput.close();

	std::string s1(av[2]);
	std::string s2(av[3]);
	
	// Replacing s1 with s2 until we can't find s1 anymore
	unsigned long found = str.find(s1);
	while (found != std::string::npos)
	{
		str = str.substr(0, str.find(s1)) + s2 + str.substr(0 + str.find(s1) + s1.size());
		found = str.find(s1, found + s2.size());   //for avoiding to loop if we replace a word with the same word
	}
		
	// Writing str modified into a new file
	std::string newFile(av[1]);
	newFile = newFile + ".replace";
	std::ofstream fOutput(newFile.c_str());
	fOutput << str;
	
	return (0);
}