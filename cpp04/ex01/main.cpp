/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:53:07 by akrid             #+#    #+#             */
/*   Updated: 2025/03/02 14:13:55 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();
	Animal			*animals[10];
	Dog				dog1;
	Dog				dog2;

	for (int k = 0; k < 10; k ++)
		(dog1.getBrain())->set_idea(std::string("eating ..."), k);
	dog2 = dog1;
	Dog 			dog3(dog2);
	std::cout << dog3.getType() << std::endl;
	for (int k = 0; k < 10; k ++)
		std::cout << "idea[" << k << "] : " << (dog3.getBrain())->get_idea(k) << std::endl;

	for (int k = 0,l = 9; (k < 10/2) && (l >= 10/2); k++, l-- )
	{
		animals[k] = new Dog();
		animals[l] = new Cat();
	}
	for (int k = 0; k < 10; k++ )
	{
		std::cout << "animals["<< k << "] : " << animals[k]->getType() << std::endl;
		delete animals[k];
	}

	delete j;//should not create a leak
	delete i;

	return 0;
}