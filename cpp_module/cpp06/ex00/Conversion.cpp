/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:03:46 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/26 16:20:37 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Conversion.hpp"

Conversion::Conversion(std::string input):
	input(input) {}

Conversion::Conversion(const Conversion &copy):
	input(copy.input) {}

Conversion::~Conversion() {}

Conversion &Conversion::operator=(const Conversion &op)
{
	this->input = op.input;
	return (*this);
}

void Conversion::printChar()
{
	std::cout << "char: ";
	if (this->int_input - this->double_input != 0)
		throw ImpossibleException();
	if (!std::isprint(int_input))
		throw NonDisplayableException();
	std::cout << "'" << this->char_input << "'" << std::endl;
}

void Conversion::printInt(void)
{
	std::cout << "int: ";
	if (std::isnan(this->int_input) ||
		std::isinf(this->int_input) ||
		(this->long_input > INT_MAX) ||
		(this->long_input < INT_MIN))
		throw ImpossibleException();
	std::cout << this->int_input << std::endl;
}

void Conversion::printFloat(void)
{
	std::cout << "float: " << this->float_input;
	if ((this->int_input - this->float_input) == 0)
		std::cout << ".0f";
	else
		std::cout << "f";
	std::cout << std::endl;
}

void Conversion::printDouble(void)
{
	std::cout << "double: " << this->double_input;
	if ((this->int_input - this->double_input) == 0)
		std::cout << ".0";
	std::cout << std::endl;
}

void Conversion::castType()
{
	try {
		this->double_input = std::stod(this->input);
	} catch (std::exception &e) {
		std::cerr << "Error: Invalid arguments" << std::endl;
		return ;
	}
	this->char_input = static_cast<char>(this->double_input);
	this->int_input = static_cast<int>(this->double_input);
	this->long_input = static_cast<long>(this->double_input);
	this->float_input = static_cast<float>(this->double_input);

	try {
		this->printChar();
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	try {
		this->printInt();
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	try {
		this->printFloat();
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	try {
		this->printDouble();
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}

const char* Conversion::ImpossibleException::what() const throw()
{
	return("impossible");
}

const char* Conversion::NonDisplayableException::what() const throw()
{
	return("Non displayable");
}
