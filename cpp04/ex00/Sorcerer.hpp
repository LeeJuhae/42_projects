/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 22:23:31 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/24 15:39:12 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include "./Victim.hpp"

class Sorcerer
{
	private:
		std::string name;
		std::string title;
		Sorcerer();

	public:
		Sorcerer(std::string name, std::string title);
		Sorcerer(const Sorcerer &copy);
		Sorcerer &operator=(const Sorcerer &op);
		~Sorcerer();

		const std::string &getName() const;
		const std::string &getTitle() const;
		void setName(const std::string &name);
		void setTitle(const std::string &title);

		void polymorph(Victim const &) const;
};

std::ostream &operator<<(std::ostream &out, const Sorcerer &sorcerer);

#endif
