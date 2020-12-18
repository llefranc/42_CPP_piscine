/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 15:32:47 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/18 10:57:51 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	Form("ShrubberyCreationForm", 145, 137), _target(target) {}
	
ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copyObj) :
	Form(copyObj) {}
	
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm assignObj)
{
	swap(*this, assignObj);
	return (*this);
}

void swap(ShrubberyCreationForm& a, ShrubberyCreationForm& b)
{
	swap(dynamic_cast<Form&>(a), dynamic_cast<Form&>(b));
	std::swap(a._target, b._target);
}

const std::string& ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void ShrubberyCreationForm::shrubberyCreation() const
{
	std::string fileName = _target + "_shrubbery";
	std::ofstream myFile(fileName);

	if (!myFile)
	{
		std::cerr << "Error creating file\n";
		return ;
	}

	// Writing the ASCII tree in the file
	myFile << "      /\\\n"
    		<< "     /\\*\\\n"
    		<< "    /\\O\\*\\\n"
    		<< "   /*/\\/\\/\\\n"
  			<< "  /\\O\\/\\*\\/\\\n" 
 			<< " /\\*\\/\\*\\/\\/\\\n" 
			<< "/\\O\\/\\/*/\\/O/\\\n"
    		<< "      ||\n"
    		<< "      ||\n"
    		<< "      ||\n\n\n";

	myFile << "      /\\\n"
    		<< "     /\\*\\\n"
    		<< "    /\\O\\*\\\n"
    		<< "   /*/\\/\\/\\\n"
  			<< "  /\\O\\/\\*\\/\\\n" 
 			<< " /\\*\\/\\*\\/\\/\\\n" 
			<< "/\\O\\/\\/*/\\/O/\\\n"
    		<< "      ||\n"
    		<< "      ||\n"
    		<< "      ||\n";
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	Form::checkAuthorizations(executor);
	shrubberyCreation();
}