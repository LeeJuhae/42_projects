/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:03:44 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/26 16:17:53 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <cmath>

class Conversion
{
	private:
		std::string input;
		char char_input;
		int int_input;
		long long_input;
		float float_input;
		double double_input;

	public:
		Conversion(std::string input);
		Conversion(const Conversion &copy);
		~Conversion();

		Conversion &operator=(const Conversion &op);

		void castType(void);
		void printChar(void);
		void printInt(void);
		void printFloat(void);
		void printDouble(void);

		class ImpossibleException: public std::exception
		{
			virtual const char* what() const throw();
		};
		class NonDisplayableException: public std::exception
		{
			virtual const char* what() const throw();
		};
};

#endif
