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

void Span::addNumber(unsigned int start, unsigned int end, int num)
{
	if ((start >= end) || (end >= this->N))
		throw RangeException();
	if (end > this->v.size())
		this->v.resize(end);
	std::vector<int>::iterator it = this->v.begin() + start;
	std::fill(it, it + (end - start) + 1, num);
}

unsigned int Span::shortestSpan(void)
{
	if (this->v.size() <= 1)
		throw Span::NoSpanException();
	unsigned int ret;
	std::vector<int> temp = this->getVector();
	std::sort(temp.begin(), temp.end());
	ret = temp.back();
	for (std::vector<int>::iterator it=temp.begin() + 1; it != temp.end() ; it++)
	{
		if (ret > static_cast<unsigned int>(*it - *(it - 1)))
			ret = *it - *(it - 1);
	}
	return (ret);
}

unsigned int Span::longestSpan(void)
{
	if (this->v.size() <= 1)
		throw Span::NoSpanException();

	unsigned int ret;
	std::vector<int> temp = this->getVector();
	std::sort(temp.begin(), temp.end());
	ret = temp.back() - temp.front();
	temp.clear();
	return (ret);
}

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

const char *Span::RangeException::what() const throw()
{
	return ("Error: Range is not valid");
}
