/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:39:26 by akrid             #+#    #+#             */
/*   Updated: 2025/02/26 13:28:16 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <iostream>
#include <cmath>

class ClapTrap
{
protected:
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
	void			set_att_damage(unsigned int att_dmg);
	void			info() const;
	void			set_name(const std::string& _name);
	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
};
