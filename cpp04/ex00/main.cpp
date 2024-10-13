/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:30:46 by aagouzou          #+#    #+#             */
/*   Updated: 2023/11/19 14:03:25 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete i;
		delete j;
		delete meta;
	}
	// std::cout << "\n ********* WrongAnimal ************* \n" << std::endl;

	// {
	// 	const WrongAnimal* meta = new WrongAnimal();
	// 	const WrongAnimal* i = new WrongCat();
	// 	std::cout << i->getType() << " " << std::endl;
	// 	i->makeSound();
	// 	meta->makeSound();
	// 	delete i;
	// 	delete meta;
	// }
	return 0;
}