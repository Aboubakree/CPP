/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:02:07 by akrid             #+#    #+#             */
/*   Updated: 2025/03/03 13:54:31 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(const Cat& obj) : Animal(obj)
{
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& obj)
{
	Animal::operator=(obj);
	std::cout << "cat Copy assingment called" << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Cat sound is on !" << std::endl;
}