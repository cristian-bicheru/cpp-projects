/*
 * matrix multiplication.cpp
 *
 *  Created on: Sep 8, 2018
 *      Author: biche
 */

#include <iostream>
#include <string>

long double ** convert(std::string input, int x, int y) {
	int pos = 0, pos2 = 0, cx = 0, cy = 0;
	long double actVal, **matrix = new long double * [x];
	std::string dimension, arraySplitter, valueSplitter, value;
	std::string::size_type sz;
	arraySplitter = "], ";
	valueSplitter = ", ";
	for (int o = 0; o <= x-1; o++)
		matrix[o] = new long double [y];
	while ((pos = input.find(arraySplitter)) != std::string::npos) {
		dimension = input.substr(0, pos).erase(0, 1);
		while ((pos2 = dimension.find(valueSplitter)) != std::string::npos) {
			value = dimension.substr(0, pos2);
			actVal = std::stold(value,&sz);
			matrix[cx][cy] = actVal;
			dimension.erase(0, pos2+valueSplitter.length());
			cx += 1;

		}
		matrix[cx][cy] = std::stold(dimension,&sz);
		input.erase(0, pos+arraySplitter.length());
		cy += 1;
		cx = 0;
	}
	input.erase(0, 1);
	input.erase(input.size()-1);
	while ((pos2 = input.find(valueSplitter)) != std::string::npos) {
		value = input.substr(0, pos2);
		actVal = std::stold(value,&sz);
		matrix[cx][cy] = actVal;
		input.erase(0, pos2+valueSplitter.length());
		cx += 1;

	}
	matrix[cx][cy] = std::stold(input,&sz);
	return matrix;
}

long double ** matrixMultiply2d(long double **matrix1, long double **matrix2, int sx1, int sy1, int sx2, int sy2) {
	long double **result = new long double * [sx2];
	for (int i = 0; i <= sx2-1; i++)
		result[i] = new long double [sy1];

	for (int cy = 0; cy <= sy1-1; cy++) {
		for (int cc = 0; cc <= sx2-1; cc++){
			for (int cx = 0; cx <= sx1-1; cx++) {
				if (cx == 0)
					result[cc][cy] = (matrix1[cx][cy])*(matrix2[cc][cx]);
				else
					result[cc][cy] += (matrix1[cx][cy])*(matrix2[cc][cx]);
			}
		}
	}

	return result;

}

int main() {
	int sx1, sy1, sx2, sy2;
    std::string matrix1raw;
    std::string matrix2raw;
    long double **matrix1, **matrix2, **result;
    std::cout << "x size: ";
    std::cin >> sx1;
    std::cout << "y size: ";
    std::cin >> sy1;
    std::cout << "matrix: "; // of the format [x0y0, x1y0, x2y0, ...], [x0y1, x1y1, x2y1, ...], ...
    std::cin.ignore();
    std::getline(std::cin, matrix1raw);
    std::cout << "x size 2: ";
    std::cin >> sx2;
    std::cout << "y size 2: ";
    std::cin >> sy2;
    std::cout << "matrix2: ";
    std::cin.ignore();
    std::getline(std::cin, matrix2raw);
    matrix1 = convert(matrix1raw, sx1, sy1);
    matrix2 = convert(matrix2raw, sx2, sy2);

    result = matrixMultiply2d(matrix1, matrix2, sx1, sy1, sx2, sy2);

    std::cout << std::endl;
    for (int i2 = 0; i2 <= sy1-1; i2++){
		for (int i = 0; i <= sx2-1; i++){
			std::cout << result[i][i2] << " ";
		}
    	std::cout << std::endl;
    }
    return 0;
}

