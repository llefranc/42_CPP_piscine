/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:56:15 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/28 12:57:13 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>
#include <algorithm>

class Span
{
	public:

		Span(unsigned int size = 0);
		~Span();
		
		Span(const Span& copy);
		Span& operator=(Span assign);
		void swap(Span& a, Span& b);
		
		unsigned int getSize() const {return (_size);};
		std::multiset<int>& getMultisetInt() {return (_multisetInts);};
		
		void addNumber(int nb);
		int shortestSpan() const;
		int longestSpan() const;
		
	private:

		unsigned int					_size;
		std::multiset<int>				_multisetInts;
};

#endif