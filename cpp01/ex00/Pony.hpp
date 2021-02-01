/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 23:51:50 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/02 01:20:00 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>

class Pony
{
	private:
		std::string name;
		std::string age;
		std::string place_of_birth;
		std::string fur_color;

	public:
		Pony();
		Pony(std::string name, std::string age, std::string place_of_birth, std::string fur_color);
		~Pony();

		std::string getName();
		std::string getAge();
		std::string getPlaceOfBirth();
		std::string getFurColor();

		void setName(std::string name);
		void setAge(std::string age);
		void setPalceOfBirth(std::string birth_of_birth);
		void setFurColor(std::string fur_color);

		void getPony();
};

#endif
