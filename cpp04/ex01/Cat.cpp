/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:02:07 by akrid             #+#    #+#             */
/*   Updated: 2025/03/03 13:56:27 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
    brain = new Brain();
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

Cat::Cat(const Cat& obj) : Animal(obj)
{
    std::cout << "Cat copy constructor called" << std::endl;
    brain = new Brain(*(obj.brain));  
}

Cat& Cat::operator=(const Cat& obj)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this == &obj)
        return *this;
    
    Animal::operator=(obj);  
    
    delete brain;  
    brain = new Brain(*(obj.brain)); 
    return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Cat sound is on !" << std::endl;
}

Brain*	Cat::getBrain()
{
	return brain;
}