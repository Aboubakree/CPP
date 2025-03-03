/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:10:15 by akrid             #+#    #+#             */
/*   Updated: 2025/03/01 17:17:39 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Brain
{
private:
	std::string	ideas[100];
public:
	Brain();
	Brain(const Brain& obj);
	Brain& operator=(const Brain& obj);
	~Brain();
	std::string		get_idea(int index) const;
	void			set_idea(const std::string& _idea, int index);
};
