/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:35:14 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/24 15:37:30 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

# include "./Victim.hpp"

class Peon: public Victim
{
	public:
		Peon(std::string name);
		Peon(const Peon &copy);
		Peon &operator=(const Peon &op);
		virtual ~Peon();
		void getPolymorphed() const;

};

std::ostream &operator<<(std::ostream &out, const Peon &peon);

#endif
