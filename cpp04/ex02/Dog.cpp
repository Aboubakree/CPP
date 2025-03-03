/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:02:11 by akrid             #+#    #+#             */
/*   Updated: 2025/03/02 20:56:09 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
    brain = new Brain();
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

Dog::Dog(const Dog& obj) : Animal(obj)
{
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*(obj.brain));  
}

Dog& Dog::operator=(const Dog& obj)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this == &obj)
        return *this;
    
    Animal::operator=(obj);
    
    delete brain;
    brain = new Brain(*(obj.brain));
    
    return *this;
}


void	Dog::makeSound() const
{
	std::cout << "Dog Sound is on !" << std::endl;
}

Brain*	Dog::getBrain()
{
	return brain;
}