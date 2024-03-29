#include "./span.hpp"

int		main(void)
{
	std::cout << "\n\t\t\033[1;31m SPAN TEST\033[0m" << std::endl;

	Span span1 = Span(7);
	Span span2 = Span(100);
	Span span3 = Span(10);

	std::cout << ">>> TEST_1: span1 = Span(7) <<<" << std::endl;
	span1.addNumber(1);
	span1.addNumber(3);
	span1.addNumber(20);
	span1.addNumber(9);
	span1.addNumber(11);
	span1.addNumber(21);
	span1.addNumber(6);
	std::cout << "span1 : 1, 3, 20, 9, 11, 21, 6" << std::endl;
	std::cout << "span1.shortestSpan(): " << span1.shortestSpan() << std::endl;
	std::cout << "span1.longestSpan(): " << span1.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << ">>> TEST_2: span2 = Span(100) <<<" << std::endl;
	for (int i = 0 ; i < 100 ; i++)
		span2.addNumber(i + 1);
	std::cout << "span2 : 1, 2, 3, ..., 98, 99, 100" << std::endl;
	std::cout << "span2.shortestSpan(): " << span2.shortestSpan() << std::endl;
	std::cout << "span2.longestSpan(): " << span2.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << ">>> TEST_3: addNumber function overloading <<<" << std::endl;
	std::cout << "span3.addNumber(0, 9, 1)" << std::endl;
	span3.addNumber(0, 9, 1);

	std::cout << "span3.shortestSpan(): " << span3.shortestSpan() << std::endl;
	std::cout << "span3.longestSpan(): " << span3.longestSpan() << std::endl;

	for (std::vector<int>::iterator it = span3.getVector().begin() ; it != span3.getVector().end() ; it++)
		std::cout << *it << std::endl;
	return (EXIT_SUCCESS);
}

void testSpan()
{

}
