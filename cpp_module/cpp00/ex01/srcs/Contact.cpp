/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:45:18 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/01 18:45:18 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact() {
	clear_contact();
}

void Contact::add_contact()
{
	std::string input;
	std::cout << "🎀 Add Contact." << std::endl;
	std::cout << "🎀 From now on, Input contact's infos." << std::endl;

	std::cout << "	✶ First Name >> ";
	std::getline(std::cin, input);
	Contact::setFirstName(input );

	std::cout << "	✶ Last Name >> ";
	std::getline(std::cin, input);
	Contact::setLastName(input);

	std::cout << "	✶ Nickname >> ";
	std::getline(std::cin, input);
	Contact::setNickname(input);

	std::cout << "	✶ Login >> ";
	std::getline(std::cin, input);
	Contact::setLogin(input);

	std::cout << "	✶ Postal Address >> ";
	std::getline(std::cin, input);
	Contact::setPostalAddress(input);

	std::cout << "	✶ Email Address >> ";
	std::getline(std::cin, input);
	Contact::setEmailAddress(input);

	std::cout << "	✶ Phone Number >> ";
	std::getline(std::cin, input);
	Contact::setPhoneNumber(input);

	std::cout << "	✶ Birthday Date >> ";
	std::getline(std::cin, input);
	Contact::setBirthdayDate(input);

	std::cout << "	✶ Favorite Meal >> ";
	std::getline(std::cin, input);
	Contact::setFavoriteMeal(input);

	std::cout << "	✶ Underwear Color >> ";
	std::getline(std::cin, input);
	Contact::setUnderwearColor(input);

	std::cout << "	✶ Darkest Secret >> ";
	std::getline(std::cin, input);
	Contact::setDarkestSecret(input);

	this->empty = false;
}

void Contact::search_contact()
{
	if (Contact::getFirstName().length() >= 10)
		std::cout << Contact::getFirstName().substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << Contact::getFirstName();
	std::cout << "|";
	if (Contact::getLastName().length() >= 10)
		std::cout << Contact::getLastName().substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << Contact::getLastName();
	std::cout << "|";
	if (Contact::getNickname().length() >= 10)
		std::cout << Contact::getNickname().substr(0, 9) << ".|" << std::endl;
	else
		std::cout << std::setw(10) << Contact::getNickname() << "|" << std::endl;
}

bool Contact::is_empty()
{
	return (this->empty);
}

void Contact::clear_contact()
{
	this->first_name.clear();
	this->last_name.clear();
	this->nickname.clear();
	this->login.clear();
	this->postal_address.clear();
	this->email_address.clear();
	this->phone_number.clear();
	this->birthday_date.clear();
	this->favorite_meal.clear();
	this->underwear_color.clear();
	this->darkest_secret.clear();
	this->empty = true;
}

// Getter
const std::string Contact::getFirstName()
{
	return (this->first_name);
};

const std::string Contact::getLastName()
{
	return (this->last_name);
};

const std::string Contact::getNickname()
{
	return (this->nickname);
};

const std::string Contact::getLogin()
{
	return (this->login);
};

const std::string Contact::getPostalAddress()
{
	return (this->postal_address);
};

const std::string Contact::getEmailAddress()
{
	return (this->email_address);
};

const std::string Contact::getPhoneNumber()
{
	return (this->phone_number);
};

const std::string Contact::getBirthdayDate()
{
	return (this->birthday_date);
};

const std::string Contact::getFavoriteMeal()
{
	return (this->favorite_meal);
};

const std::string Contact::getUnderwearColor()
{
	return (this->underwear_color);
};

const std::string Contact::getDarkestSecret()
{
	return (this->darkest_secret);
};

// Setter
void Contact::setFirstName(const std::string first_name)
{
	this->first_name = first_name;
};

void Contact::setLastName(std::string last_name)
{
	this->last_name = last_name;
};

void Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
};

void Contact::setLogin(std::string login)
{
	this->login = login;
};

void Contact::setPostalAddress(std::string postal_address)
{
	this->postal_address = postal_address;
};

void Contact::setEmailAddress(std::string email_address)
{
	this->email_address = email_address;
};

void Contact::setPhoneNumber(std::string phone_number)
{
	this->phone_number = phone_number;
};

void Contact::setBirthdayDate(std::string birthday_date)
{
	this->birthday_date = birthday_date;
};

void Contact::setFavoriteMeal(std::string favorite_meal)
{
	this->favorite_meal = favorite_meal;
};

void Contact::setUnderwearColor(std::string underwear_color)
{
	this->underwear_color = underwear_color;
};

void Contact::setDarkestSecret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
};
