# pragma once

#include <iostream>
#include <cmath>

class ClapTrap
{
private:
	std::string		name;
	unsigned int	hit_point;
	unsigned int	energy_point;
	unsigned int	attack_damage;
public:
	ClapTrap();
	ClapTrap(const std::string& _name);
	ClapTrap(const ClapTrap& obj);
	ClapTrap& operator=(const ClapTrap& obj);
	~ClapTrap();
	std::string		get_name();
	unsigned int	get_att_damage();
	void 			info() const;
	void 			set_name(const std::string& _name);
	void 			attack(const std::string& target);
	void 			takeDamage(unsigned int amount);
	void 			beRepaired(unsigned int amount);
};
