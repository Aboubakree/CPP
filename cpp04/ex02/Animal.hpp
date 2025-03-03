/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:47:53 by akrid             #+#    #+#             */
/*   Updated: 2025/03/02 20:33:42 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Brain.hpp"

class Animal
{
protected:
    std::string type;
public:
    Animal();
	Animal(const Animal& obj);
	Animal(const std::string& _type);
	Animal& operator=(const Animal& obj);
    virtual ~Animal();
	virtual	std::string		getType() const;
	virtual void	makeSound() const = 0;
};
