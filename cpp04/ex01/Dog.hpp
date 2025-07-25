/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:02:19 by akrid             #+#    #+#             */
/*   Updated: 2025/03/01 18:20:22 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once
#include "Animal.hpp" 

class Dog : public Animal
{
private :
	Brain*	brain;
public:
	Dog();
	Dog(const Dog& obj);
	Dog& operator=(const Dog& obj);
	~Dog();
	void	makeSound() const;
	Brain*	getBrain();
};
