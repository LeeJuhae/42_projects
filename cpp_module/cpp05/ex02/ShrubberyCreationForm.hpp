/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:19:42 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/25 14:45:20 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "./Form.hpp"
# include <fstream>

class ShrubberyCreationForm: public Form
{
	private:
		ShrubberyCreationForm();
		const std::string &target;

	public:
		static const std::string &form_name;
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		virtual ~ShrubberyCreationForm();

		class FileException: public std::exception {
			virtual const char* what() const throw();
		};

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &op);

		void execute(Bureaucrat const & executor) const;
};

#endif
