/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 12:23:19 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/24 14:01:19 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

class Awesome {

public:

Awesome( int n ) : _n( n ) {}

bool operator==( Awesome const & rhs ) { return (this->_n == rhs._n); }
bool operator!=( Awesome const & rhs ) { return (this->_n != rhs._n); }
bool operator>( Awesome const & rhs ) { return (this->_n > rhs._n); }
bool operator<( Awesome const & rhs ) { return (this->_n < rhs._n); }
bool operator>=( Awesome const & rhs ) { return (this->_n >= rhs._n); }
bool operator<=( Awesome const & rhs ) { return (this->_n <= rhs._n); }

int getN() const {return (_n);}

private:

int _n;
};

std::ostream& operator<<(std::ostream& flux, Awesome& obj)
{
	std::cout << obj.getN();
	return (flux);
}