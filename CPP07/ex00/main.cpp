/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:44:13 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/24 14:04:04 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "whatever.hpp"
#include "test.hpp"

int main()
{
	std::cout << "----- INT -----\n";
	int a = 5;
	int b = 6;
	
	std::cout << "a = " << a << ", b = " << b << "\n";
	swap<int>(a, b);
	std::cout << "a = " << a << ", b = " << b << "\n";
	std::cout << "Min: " << min<int>(a, b) << ", max: " << max<int>(a, b) << "\n";
	
	
	std::cout << "\n----- EQUAL INT VALUES -----\n";
	
	b = 6;
	std::cout << "a = " << a << ", b = " << b << "\n";
	swap<int>(a, b);
	std::cout << "a = " << a << ", b = " << b << "\n";
	std::cout << "Min: " << min<int>(a, b) << ", max: " << max<int>(a, b) << "\n";
	
	
	std::cout << "\n----- DOUBLE -----\n";
	double c = 4.5;
	double d = 6.7;
	
	std::cout << "c = " << c << ", d = " << d << "\n";
	swap<double>(c, d);
	std::cout << "c = " << c << ", d = " << d << "\n";
	std::cout << "Min: " << min<double>(c, d) << ", max: " << max<double>(c, d) << "\n";
	
	
	std::cout << "\n----- CHAR -----\n";
	char e = 'e';
	char f = 'f';
	
	std::cout << "e = " << e << ", f = " << f << "\n";
	swap<char>(e, f);
	std::cout << "e = " << e << ", f = " << f << "\n";
	std::cout << "Min: " << min<char>(e, f) << ", max: " << max<char>(e, f) << "\n";
	
	
	std::cout << "\n----- TESTS FROM SUBJECT -----\n";
	
	int g = 2;
	int i = 3;
	::swap(g, i);
	std::cout << "g = " << g << ", i = " << i << std::endl;
	std::cout << "min(g, i) = " << ::min(g, i) << std::endl;
	std::cout << "max(g, i) = " << ::max(g, i) << std::endl;
	
	std::string v = "chaine1";
	std::string m = "chaine2";
	::swap(v, m);
	std::cout << "v = " << v << ", m = " << m << std::endl;
	std::cout << "min(v, m) = " << ::min(v, m) << std::endl;
	std::cout << "max(v, m) = " << ::max(v, m) << std::endl;
	
	return (0);
}