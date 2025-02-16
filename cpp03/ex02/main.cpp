/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:39:29 by akrid             #+#    #+#             */
/*   Updated: 2025/02/15 15:31:38 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap a("robot1");
	FragTrap b("robot2");
	FragTrap c(a);
	FragTrap d;
	d = b;
	c.info();
	d.info();
	c.attack(d.get_name());
	d.takeDamage(c.get_att_damage());
	d.beRepaired(c.get_att_damage());
	c.info();
	d.info();
	d.highFivesGuys();
	c.highFivesGuys();
}