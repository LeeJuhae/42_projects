/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:20:13 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/24 15:37:47 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>

class Victim
{
	protected:
		std::string name;

	public:
		Victim(std::string name);
		Victim(const Victim &copy);
		Victim &operator=(const Victim &op);
		virtual ~Victim();

		const std::string &getName() const;
		void setName(std::string);

		virtual void getPolymorphed() const;
};

std::ostream &operator<<(std::ostream &out, const Victim &victim);

#endif
