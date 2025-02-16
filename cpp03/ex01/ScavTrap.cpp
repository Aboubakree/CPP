/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:39:12 by akrid             #+#    #+#             */
/*   Updated: 2025/02/15 14:57:15 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	hit_point = 100;
	energy_point = 50;
	attack_damage = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj): ClapTrap(obj)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& _name): ClapTrap(_name)
{
	hit_point = 100;
	energy_point = 50;
	attack_damage = 20;
	std::cout << "ScavTrap parametrized constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	ClapTrap::operator=(obj);
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		name = obj.name;
		hit_point = obj.hit_point;
		energy_point = obj.energy_point;
		attack_damage = obj.attack_damage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (hit_point <= 0)
	{
		std::cout << "ScavTrap "<< name<< " is Already dead." << std::endl;
		return;
	}
	if (energy_point > 0)
	{
		std::cout << "ScavTrap "<< name<< " attacks "<< target<< ", causing "<< attack_damage<<" points of damage!" << std::endl;
		energy_point --;
	}
	else
		std::cout << "ScavTrap "<< name << "Not enought energy points.";
}