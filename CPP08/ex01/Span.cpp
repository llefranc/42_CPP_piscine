/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:56:04 by lucaslefran       #+#    #+#             */
/*   Updated: 2021/01/03 16:24:05 by lucaslefran      ###   ########.fr       */
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
* Adds the number to the multiset
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
		
	int minSpan = *++_multisetInts.begin() - *_multisetInts.begin();

	for (std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator> i(_multisetInts.begin(), ++_multisetInts.begin());
			i.second != _multisetInts.end(); i.first++, i.second++)	
		if (minSpan > *i.second - *i.first)
			minSpan = *i.second - *i.first;
		
	return (minSpan);
}

int Span::longestSpan() const
{
	if (_multisetInts.size() <= 1)
		throw std::exception();
		
	return (*(--_multisetInts.end()) - *_multisetInts.begin());
}