/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:10:31 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/25 16:48:39 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "./Form.hpp"
# include "./ShrubberyCreationForm.hpp"
# include "./RobotomyRequestForm.hpp"
# include "./PresidentialPardonForm.hpp"

typedef Form *(*form_func) (std::string const &target);

typedef struct s_form_types
{
	std::string form_name;
	form_func func;
}				t_form_types;

class Intern
{
	public:
		Intern();
		Intern(const Intern &copy);
		virtual ~Intern();
		Intern &operator=(const Intern &op);

		Form *makeForm(const std::string &name, const std::string &target);
};

#endif
