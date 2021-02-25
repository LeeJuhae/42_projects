/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 21:05:37 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/25 14:24:51 by juhlee           ###   ########.fr       */
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
		const std::string &name;
		bool isSigned;
		const int signGrade;
		const int executeGrade;

	public:
		Form(const std::string &name, const int signGrade, const int executeGrade);
		Form(const Form &copy);
		virtual ~Form();
		Form &operator=(const Form &op);

		class GradeTooHighException: public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			virtual const char* what() const throw();
		};
		class UnsignedFormException: public std::exception {
			virtual const char* what() const throw();
		};

		void beSigned(const Bureaucrat &bureaucrat);

		const std::string &getName(void) const;
		bool getIsSigned(void) const;
		int getSignGrade(void) const;
		int getExecuteGrade(void) const;

		virtual void execute(Bureaucrat const &bureaucrat) const = 0;
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
