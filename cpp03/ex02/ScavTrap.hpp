/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:39:19 by akrid             #+#    #+#             */
/*   Updated: 2025/02/26 12:12:46 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const ScavTrap& obj);
	ScavTrap(const std::string& _name);
	ScavTrap& operator=(const ScavTrap& obj);
	~ScavTrap();
	void 	attack(const std::string& target);
	void 	guardGate();
};