/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:48:59 by akrid             #+#    #+#             */
/*   Updated: 2025/02/28 17:23:16 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("animal")
{
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const std::string& _type): type(_type)
{
	std::cout << "Animal parametrized constructor called" << std::endl;
}

Animal::Animal(const Animal& obj) : type(obj.type)
{
	std::cout << "Animal Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& obj)
{
	std::cout << "Animal copy assingment called" << std::endl;
	if (this != &obj)
		type = obj.type;	
	return *this;
}

std::string	Animal::getType() const
{
	return type;
}

void	Animal::makeSound() const
{
	std::cout<< "cats don’t bark" << std::endl;
}
