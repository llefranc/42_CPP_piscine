/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:30:31 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/25 18:12:34 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>

template<typename T>
class Array;

template<typename T>
void swap(Array<T>& a, Array<T>& b);

template<typename T>
class Array
{
	public:

		Array(const unsigned int size = 0);
		~Array();

		Array(const Array<T>& copy);
		Array<T>& operator=(Array<T> assign);
		friend void swap<T>(Array& a, Array& b);

		T* getArray() const;
		unsigned int getSizeArray() const;

		T& operator[](unsigned int i);
		const T& operator[](unsigned int i) const;
		
	private:

		unsigned int	_size;
		T*				_tArray;
};


/* ------ CLASS METHODS ------ */

/* Constructor */
template<typename T>
Array<T>::Array(const unsigned int size) :
	_size(size)
{
	// Array of T value all value-initialized
	_tArray = new T[_size]();
}

/* Destructor */
template<typename T>
Array<T>::~Array()
{
	delete[] _tArray;
}

/* Copy constructor */
template<typename T>
Array<T>::Array(const Array<T>& copy) :
	_size(copy._size)
{
	_tArray = new T[_size];

	for (unsigned int i = 0; i < _size; i++)
		_tArray[i] = copy._tArray[i];
}

/* Assign operator */
template<typename T>
Array<T>& Array<T>::operator=(Array<T> assign)
{
	swap(*this, assign);
	return (*this);
}

template<typename T>
void swap(Array<T>& a, Array<T>& b)
{
	std::swap(a._size, b._size);
	std::swap(a._tArray, b._tArray);
}

/* Getters */

template<typename T>
unsigned int Array<T>::getSizeArray() const
{
	return (_size);
}

template<typename T>
T* Array<T>::getArray() const
{
	return (_tArray);
}

/* Operator overloaded */
template<typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw std::exception();
	return (_tArray[i]);
}

template<typename T>
const T& Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw std::exception();
	return (_tArray[i]);
}

#endif