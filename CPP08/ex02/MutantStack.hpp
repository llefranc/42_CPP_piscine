/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:28:03 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/29 17:58:30 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
	
		// Coplien form using constructors from std::stack
		MutantStack() : std::stack<T>() {};
		~MutantStack() {};
		
		// Using copy constructor and assignment operator= from std::stack
		MutantStack(const MutantStack& copy) : std::stack<T>(copy) {};
		MutantStack<T>& operator=(const MutantStack<T>& assign)
				{std::stack<T>::operator=(assign);return (*this);};
				
		// For creating in the main an iterator object and for the return value of begin / end methods
		typedef typename std::stack<T>::container_type::iterator iterator;
		
		// Begin and end methods that returns an iterator of the underlying container object
		// that stack is using (could be deque, vector or list. Is a deque by default).
		// Std::stack<T>::c is a member object of stack container that is the the underlying container.
		iterator begin() { return std::begin(std::stack<T>::c); }
		iterator end() { return std::end(std::stack<T>::c); }
};

#endif