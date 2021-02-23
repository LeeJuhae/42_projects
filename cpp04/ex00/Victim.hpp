/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:20:13 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/22 23:49:27 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>

class Victim
{
	public:
		Victim(std::string name);
		Victim(const Victim &copy);
		Victim &operator=(const Victim &op);
		~Victim();

		const std::string &getName() const;
		void setName(std::string);

		virtual void getPolymorphed() const;

	protected:
		std::string name;
};

std::ostream &operator<<(std::ostream &out, const Victim &victim);

#endif
