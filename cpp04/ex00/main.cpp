/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:53:07 by akrid             #+#    #+#             */
/*   Updated: 2025/03/01 11:44:19 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	const Animal*	meta = new Animal();
	const Animal*	i = new Cat();
	const Animal*	j = new Dog();
	WrongAnimal*	test = new WrongCat();
	const Animal*	k = new Cat();

	delete k;
	k = i;
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	meta->makeSound();
	i->makeSound();
	j->makeSound();
	test->makeSound(); 

	delete meta;
	delete i;
	delete j;
	delete test;

	return 0;
}