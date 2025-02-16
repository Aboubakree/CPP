#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
	name("Default"),
	hit_point(10),
	energy_point(10),
	attack_damage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& _name): 
	name(_name),
	hit_point(10),
	energy_point(10),
	attack_damage(0)
{
	std::cout << "Parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj):
	name(obj.name),
	hit_point(obj.hit_point),
	energy_point(obj.energy_point),
	attack_damage(obj.attack_damage)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (&obj != this)
	{
		name = obj.name;
		hit_point = obj.hit_point;
		energy_point = obj.energy_point;
		attack_damage = obj.attack_damage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

std::string ClapTrap::get_name()
{
	return name;
}

unsigned int ClapTrap::get_att_damage()
{
	return attack_damage;
}

void ClapTrap::set_name(const std::string& _name)
{
	name = _name;
}

void ClapTrap::info() const
{
	std::cout << "\n--------------------------------------------" << std::endl;
	std::cout << "ClapTrap      : "<< name  << std::endl;
	std::cout << "hit points    : "<< hit_point << std::endl;
	std::cout << "energy point  : "<< energy_point << std::endl;
	std::cout << "attack damage : "<< attack_damage << std::endl;
	std::cout << "\n--------------------------------------------" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (hit_point <= 0)
	{
		std::cout << "ClapTrap "<< name<< " is Already dead." << std::endl;
		return;
	}
	if (energy_point > 0)
	{
		std::cout << "ClapTrap "<< name<< " attacks "<< target<< ", causing "<< attack_damage<<" points of damage!" << std::endl;
		energy_point --;
	}
	else
		std::cout << "ClapTrap "<< name << "Not enought energy points.";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_point <= 0)
	{
		std::cout << "ClapTrap "<< name<< " is Already dead." << std::endl;
		return;
	}
	std::cout << "ClapTrap "<< name<< " takes" << amount << " of damage." << std::endl;
	if (hit_point > amount)
		hit_point -= amount;
	else
		hit_point = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_point <= 0)
	{
		std::cout << "ClapTrap "<< name<< " is Already dead." << std::endl;
		return;
	}
	if (energy_point > 0)
	{
		std::cout << "ClapTrap "<< name << " has repaired " << amount << " of points." << std::endl;
		hit_point = (hit_point + amount > 10) ? 10 : hit_point + amount;
		energy_point --;
	}
	else
		std::cout << "ClapTrap "<< name << "Not enought energy points.";
}