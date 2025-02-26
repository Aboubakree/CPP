/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:39:29 by akrid             #+#    #+#             */
/*   Updated: 2025/02/26 11:58:30 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("robot1");
	ScavTrap b("robot2");
	ScavTrap c(a);
	ScavTrap d;
	d = b;
	c.info();
	d.info();
	c.attack(d.get_name());
	d.takeDamage(c.get_att_damage());
	d.beRepaired(c.get_att_damage());
	c.info();
	d.info();
	d.guardGate();
}