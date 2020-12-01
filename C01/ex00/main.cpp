/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:02:15 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/01 18:42:55 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pony.hpp"

//Creates a pony object on the stack, then deletes it
void	create_pony_stack()
{
	std::cout << "Pony created on stack : ";
	Pony Ponystack;
	Ponystack.jump();
	std::cout << "Pony deleted from stack : ";
}

//Creates a pony object on the heap, then deletes it
void	create_pony_heap()
{
	std::cout << "\nPony created on heap : ";
	Pony *Ponystack = new Pony;
	Ponystack->run();
	std::cout << "Pony deleted from heap : ";
	delete Ponystack;
}

int main()
{
	create_pony_stack();
	std::cout << "We exited pony_stack function\n";
	create_pony_heap();
	std::cout << "We exited pony_stack function\n";
	return (0);
}
