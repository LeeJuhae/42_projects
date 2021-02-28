#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>

class Span
{
	private:
		unsigned int N;
		std::vector <int> v;

	public:
		Span(unsigned int N);
		Span(Span const &copy);
		virtual ~Span();
		Span &operator=(Span const &op);

		void addNumber(int num);
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);

		std::vector<int> &getVector(void);

		class NoSpanException: public std::exception
		{
			virtual const char *what() const throw();
		};

		class ContainerFullException: public std::exception
		{
			virtual const char *what() const throw();
		};
};

#endif
