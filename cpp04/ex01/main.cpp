/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:30:46 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/19 12:29:02 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


// void lol()
// {
// 	system("leaks animal");
// }
int main()
{
//	atexit(lol);
	
	//subject main
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// delete j;//should not create a leak
	// delete i;

	int size = 4;
	Animal *animals[size];
	for(int i = 0; i < size/2 ; i++)
		animals[i] = new Dog();
	for(int i = size/2; i < size ; i++)
		animals[i] = new Cat();
	for(int i = 0; i < size ; i++)
		delete animals[i];


	// test for deep copy
	// Dog basic;
	// {
	// 	Dog tmp = basic;
	// }
	return 0;
}