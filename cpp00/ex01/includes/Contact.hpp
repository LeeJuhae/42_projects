/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:45:11 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/01 18:45:45 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

# ifndef MAX_CNT
#  define MAX_CNT 8
# endif

class Contact {
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string login;
		std::string postal_address;
		std::string email_address;
		std::string phone_number;
		std::string birthday_date;
		std::string favorite_meal;
		std::string underwear_color;
		std::string darkest_secret;
		bool empty;

	public:
		Contact();

		// Getter
		const std::string getFirstName();
		const std::string getLastName();
		const std::string getNickname();
		const std::string getLogin();
		const std::string getPostalAddress();
		const std::string getEmailAddress();
		const std::string getPhoneNumber();
		const std::string getBirthdayDate();
		const std::string getFavoriteMeal();
		const std::string getUnderwearColor();
		const std::string getDarkestSecret();

		// Setter
		void setFirstName(std::string first_name);
		void setLastName(std::string last_name);
		void setNickname(std::string nickname);
		void setLogin(std::string login);
		void setPostalAddress(std::string postal_address);
		void setEmailAddress(std::string email_address);
		void setPhoneNumber(std::string phone_number);
		void setBirthdayDate(std::string birthday_date);
		void setFavoriteMeal(std::string favorite_meal);
		void setUnderwearColor(std::string underwear_color);
		void setDarkestSecret(std::string darkest_secret);

		void add_contact();
		void search_contact();
		bool is_empty();
		void clear_contact();
};

#endif
