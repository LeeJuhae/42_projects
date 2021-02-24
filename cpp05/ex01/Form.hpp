/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 21:05:37 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/24 21:48:46 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
class Form;
# include "./Bureaucrat.hpp"

class Form
{
	private:
		std::string const &name;
		bool isSigned;
		int const signGrade;
		int const executeGrade;

	public:
		Form(std::string &name, int const signGrade, int const executeGrade);
		From(Form const &copy);
		virtual ~Form();
		Form &operator=(Form const &op);

		class GradeTooHighException: public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			virtual const char* what() const throw();
		};

		void beSigned(Bureaucrat const &bureaucrat);

		std::string const &getName(void);
		bool &getIsSigned(void);
		int const &getSignGrade(void);
		int const &getExecuteGrade(void);
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif
