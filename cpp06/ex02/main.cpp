/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:12:09 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/25 22:32:41 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	std::srand(std::time(0));
	int num = std::rand() % 3;

	switch(num)
	{
		case 0:
			return new A();
		case 1:
			return new C();
		case 2:
			return new B();
		default:
			return NULL;
	}
}
void identify(Base* p)
{
	A *A_ptr;
	B *B_ptr;
	C *C_ptr;

	A_ptr = dynamic_cast<A*>(p);
	B_ptr = dynamic_cast<B*>(p);
	C_ptr = dynamic_cast<C*>(p);
	if(A_ptr)
		std::cout << "the actual type of object pointed by p is A" << std::endl;
	else if(B_ptr)
		std::cout << "the actual type of object pointed by p is B" << std::endl;
	else if(C_ptr)
		std::cout << "the actual type of object pointed by p is C" << std::endl;
	else
		std::cout << "unknown pointer" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &A_ref = dynamic_cast<A&>(p);
		(void)A_ref;
		std::cout << "the actual type of object pointed by p is A" << std::endl;
		return ;	
	}
	catch(const std::bad_cast& e)
	{
		
	}
	try
	{
		B &B_ref = dynamic_cast<B&>(p);
		(void)B_ref;
		std::cout << "the actual type of object pointed by p is B" << std::endl;
		return ;	
	}
	catch(const std::bad_cast& e)
	{
		
	}
	try
	{
		C &C_ref = dynamic_cast<C&>(p);
		(void)C_ref;
		std::cout << "the actual type of object pointed by p is C" << std::endl;		
	}
	catch(const std::bad_cast& e)
	{
		std::cout << "unknown reference" << std::endl;
	}
}

int main()
{
	Base *ptr = generate();
	identify(ptr);
	identify(*ptr);
}