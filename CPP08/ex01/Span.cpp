/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:56:04 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/28 12:56:38 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int size) :
	_size(size), _multisetInts() {}

Span::~Span() {}

Span::Span(const Span& copy) :
	_size(copy._size), _multisetInts(copy._multisetInts) {}

Span& Span::operator=(Span assign)
{
	swap(*this, assign);
	return (*this);
}

void Span::swap(Span& a, Span& b)
{
	std::swap(a._size, b._size);
	std::swap(a._multisetInts, b._multisetInts);
}

/*
* Adds the number to the settor and inc the iterator
*/
void Span::addNumber(int nb)
{
	if (_multisetInts.size() == _size)
		throw std::exception();
	_multisetInts.insert(nb);
}

int Span::shortestSpan() const
{
	if (_multisetInts.size() <= 1)
		throw std::exception();
		
	return (*(++_multisetInts.begin()) - *_multisetInts.begin());
}

int Span::longestSpan() const
{
	if (_multisetInts.size() <= 1)
		throw std::exception();
		
	return (*(--_multisetInts.end()) - *_multisetInts.begin());
}