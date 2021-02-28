#include "./span.hpp"

Span::Span(unsigned int N):
	N(N) {}

Span::Span(Span const &copy)
{
	*this = copy;
}

Span::~Span()
{
	this->v.clear();
}

Span &Span::operator=(Span const &op)
{
	if (this != &op)
	{
		this->N = op.N;
		this->v = op.v;
	}
	return (*this);
}

void Span::addNumber(int num)
{
	if (this->v.size() >= this->N)
		throw ContainerFullException();
	this->v.push_back(num);
}

// unsigned int Span::shortestSpan(void)
// {
// 	if (this->v.size() <= 1)
// 		throw Span::NoSpanException();

// }

// unsigned int Span::longestSpan(void)
// {

// }

std::vector<int> &Span::getVector(void)
{
	return (this->v);
}

const char *Span::NoSpanException::what() const throw()
{
	return ("Error: No Span");
}

const char *Span::ContainerFullException::what() const throw()
{
	return ("Error: Container is full");
}
