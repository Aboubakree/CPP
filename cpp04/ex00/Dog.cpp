/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:02:11 by akrid             #+#    #+#             */
/*   Updated: 2025/02/28 16:14:39 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog():Animal()
{
	type = "Dog";
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& obj): Animal(obj)
{
	std::cout << "Dog Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& obj)
{
	Animal::operator=(obj);
	std::cout << "Dog copy assingnement called" << std::endl;
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Dog Sound is on !" << std::endl;
}