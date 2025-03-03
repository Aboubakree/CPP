/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:11:12 by akrid             #+#    #+#             */
/*   Updated: 2025/03/01 18:23:50 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& obj)
{
	std::cout << "Brain copy contructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = obj.ideas[i];
}

Brain& Brain::operator=(const Brain& obj)
{
	std::cout << "Brain copy assingment contructor called" << std::endl;
	if (this == &obj)
		return *this;
	for (int i = 0; i < 100; i++)
		ideas[i] = obj.ideas[i];
	return *this;
}

std::string	Brain::get_idea(int index) const
{
	if (index < 100 && index >= 0)
		return ideas[index];
	return "there is No ideas !";
}

void			Brain::set_idea(const std::string& _idea, int index)
{
	if (index < 100 && index >= 0)
		ideas[index] = _idea;
}