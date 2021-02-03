/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 01:00:50 by ijuhae            #+#    #+#             */
/*   Updated: 2021/02/03 13:32:14 by ijuhae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <sstream>
# include <fstream>
# include <sys/stat.h>

class Sed
{
	public:
		Sed(char *filename, char *s1, char *s2);
		int check_validity();
		void replace();

	private:
		char *filename;
		std::string s1;
		std::string s2;
};

#endif
