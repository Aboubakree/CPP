/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:11:32 by akrid             #+#    #+#             */
/*   Updated: 2025/02/15 15:26:48 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
public:
	FragTrap();
	FragTrap(const FragTrap& obj);
	FragTrap(const std::string& _name);
	FragTrap& operator=(const FragTrap& obj);
	~FragTrap();
	void attack(const std::string& target);
	void highFivesGuys(void);
};