/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 01:00:38 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/03 13:35:34 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Sed.hpp"

Sed::Sed(char *filename, char *s1, char *s2):
	filename(filename),
	s1(std::string(s1)),
	s2(std::string(s2))
{}

int Sed::check_validity()
{
	struct stat buf;

	if (!this->s1.compare("") || !this->s2.compare(""))
	{
		std::cout << "❗️ String is empty." << std::endl;
		return (-1);
	}
	if (stat(this->filename, &buf) == -1)
	{
		std::cout << "❗️ File not exist." << std::endl;
		return (-1);
	}
	return (0);
}

void Sed::replace()
{
	std::ostringstream contents;
	std::ifstream input_file(this->filename);
	std::string new_contents;
	size_t pos;

	contents << input_file.rdbuf();
	new_contents = contents.str();

	while ((pos = new_contents.find(this->s1)) != std::string::npos)
		new_contents.replace(pos, this->s1.length(), this->s2);

	input_file.close();
	std::ofstream output_file(std::string(this->filename) + ".replace");
	output_file << new_contents;
}
