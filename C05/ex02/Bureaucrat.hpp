/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 11:21:01 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/17 17:39:36 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Form.hpp"

class Form;

class Bureaucrat
{
	public:

		class GradeTooHighException : public std::exception
		{
			public:

				GradeTooHighException() throw();
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:

				GradeTooLowException() throw();
				virtual const char* what() const throw();
		};
		
		class IsntSigned : public std::exception
		{
			public:

				IsntSigned() throw();
				virtual const char* what() const throw();
		};

		
		Bureaucrat(const std::string& name = "Bob", int grade = 50);
		~Bureaucrat();

		Bureaucrat(const Bureaucrat& copyObj);
		Bureaucrat& operator=(Bureaucrat assignObj);
		friend void swap(Bureaucrat& a, Bureaucrat& b);

		const std::string& getName() const;
		int getGrade() const;
		
		void incrementGrade();
		void decrementGrade();
		void signForm(int gradeToSign, const std::string formName) const;
		void executeForm(Form const & form) const;
		
	private:

		const std::string	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream& output, Bureaucrat& brct);

#endif