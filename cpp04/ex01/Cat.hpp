/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:02:16 by akrid             #+#    #+#             */
/*   Updated: 2025/03/01 18:22:14 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
private :
	Brain*	brain;
public:
	Cat();
	Cat(const Cat& obj);
	Cat& operator=(const Cat& obj);
	~Cat();
	void		makeSound() const;
	Brain*		getBrain();
};
