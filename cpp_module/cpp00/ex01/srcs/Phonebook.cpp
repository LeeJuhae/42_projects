/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:14:27 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/01 18:45:16 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

void print_banner()
{
	std::cout << "        __                       __                 __" << std::endl;
	std::cout << ".-----.|  |--.-----.-----.-----.|  |--.-----.-----.|  |--." << std::endl;
	std::cout << "|  _  ||     |  _  |     |  -__||  _  |  _  |  _  ||    <" << std::endl;
	std::cout << "|   __||__|__|_____|__|__|_____||_____|_____|_____||__|__|" << std::endl;
	std::cout << "|__|" << std::endl;
	std::cout << std::endl;
}

int get_cmd()
{
	std::string cmd;
	while (1)
	{
		std::cout << "☻ Select Commands [ ADD / SEARCH / EXIT ] >> ";
		std::getline(std::cin, cmd);
		if (cmd == "EXIT")
			return (0);
		else if (cmd == "ADD")
			return (1);
		else if (cmd == "SEARCH")
			return (2);
	}
}

void add(Contact contacts[MAX_CNT])
{
	int i;

	i = 0;
	while (!contacts[i].is_empty() && i < MAX_CNT)
		i++;
	if (i != MAX_CNT)
		contacts[i].add_contact();
	else
	{
		while (1)
		{
			std::string answer;
			std::cout << "❗️ Contacts are full. Do you want to remove first contact? [y/n] >> ";
			std::getline(std::cin, answer);
			if (!answer.compare("y"))
			{
				for(int j = 1 ; j < MAX_CNT ; j++)
					contacts[j-1] = contacts[j];
				contacts[MAX_CNT-1].clear_contact();
				std::cout << "👌 Complete remove first contact." << std::endl;
				contacts[MAX_CNT-1].add_contact();
				break;
			}
			else if (!answer.compare("n"))
			{
				std::cout << "🌻 Nothing Changed." << std::endl;
				break;
			}
		}
	}
}

void search(Contact contacts[MAX_CNT])
{
	int i;

	i = 0;
	std::cout << "🎀 Display Contacts." << std::endl;
    std::cout << "	|     index|first name| last name|  nickname|" << std::endl;
    std::cout << "	|----------|----------|----------|----------|" << std::endl;
	while (!contacts[i].is_empty() && i < MAX_CNT)
	{
		std::cout << "	|";
		std::cout << std::setw(10) << i << "|";
		contacts[i].search_contact();
		i++;
	}
}

int main()
{
	int cmd;
	Contact contacts[MAX_CNT];

	print_banner();
	while ((cmd = get_cmd()))
	{
		if (cmd == 0)
			break;
		else if(cmd == 1)
			add(contacts);
		else
			search(contacts);
	}
	return (0);
}
