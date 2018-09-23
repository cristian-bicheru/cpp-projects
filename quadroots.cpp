/*
* quadroots.cpp
*
*  Created on: Sep 23, 2018
*      Author: biche
*/

#include <iostream>
#include <string>
#include <cmath>

long double *qroots(std::string quadratic) {
	long double a, b, c;
	long double *roots = new long double [2];
	std::string term;
	int pos;
	while ((pos = quadratic.find("+")) != std::string::npos) {
		term = quadratic.substr(0, pos);
		if (term.find("x^2") != std::string::npos) {
			a = std::stold(term.substr(0, term.find("x^2")));
		}
		else if (term.find("x") != std::string::npos) {
			b = std::stold(term.substr(0, term.find("x")));
		}
		quadratic.erase(0, pos + 1);
	}
	c = std::stold(quadratic);
	roots[0] = (pow(pow(b, 2.0) - 4 * a*c, 0.5) - b) / (2 * a);
	roots[1] = (-b-pow(pow(b, 2.0) - 4 * a*c, 0.5)) / (2 * a);
	return roots;
}

int main() {
	std::string quadratic;
	long double *roots;
	std::cout << "input quadratic: "; //of the form ax^2+bx+c, for negative values do +-. I.e -2x^2+-5x+4
	std::cin >> quadratic;
	roots = qroots(quadratic);
	std::cout << roots[0] << "\n";
	std::cout << roots[1];
	return 0;
}

