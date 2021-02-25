/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:41:17 by juhlee            #+#    #+#             */
/*   Updated: 2021/02/25 14:25:05 by juhlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "./Form.hpp"
# include <time.h>

class RobotomyRequestForm: public Form
{
	private:
		const std::string &target;

	public:
		static const std::string &form_name;
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &op);

		void execute(Bureaucrat const & executor) const;

};

# endif
