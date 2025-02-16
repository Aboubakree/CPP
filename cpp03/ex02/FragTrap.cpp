/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:11:27 by akrid             #+#    #+#             */
/*   Updated: 2025/02/15 15:29:29 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	hit_point = 100;
	energy_point = 100;
	attack_damage = 30;
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj): ClapTrap(obj)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& _name): ClapTrap(_name)
{
	hit_point = 100;
	energy_point = 100;
	attack_damage = 30;
	std::cout << "FragTrap parametrized constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
	ClapTrap::operator=(obj);
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		name = obj.name;
		hit_point = obj.hit_point;
		energy_point = obj.energy_point;
		attack_damage = obj.attack_damage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (hit_point <= 0)
	{
		std::cout << "FragTrap "<< name<< " is Already dead." << std::endl;
		return;
	}
	if (energy_point > 0)
	{
		std::cout << "FragTrap "<< name<< " attacks "<< target<< ", causing "<< attack_damage<<" points of damage!" << std::endl;
		energy_point --;
	}
	else
		std::cout << "FragTrap "<< name << "Not enought energy points.";
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "High Five man !" << std::endl;
}