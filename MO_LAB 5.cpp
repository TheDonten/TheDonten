#include "pch.h"

#include <iostream>

#include <cmath>

#include <time.h>

#include <iomanip>

#include <iterator>

#include <random>

#include <fstream>

double fun(double x)

{
	return (-0.5*cos(0.5*x)) + 1;
}


void print_2(double P, double q, double e, double N, double x_min, double y_min)

{
	std::cout << "+------+-------+------+-----+-----------+---------+\n";

	std::cout << "|" << std::setw(5) << P << std::setw(2) << "|" << std::setw(6)
		<< q << std::setw(2) << "|" << std::setw(5) << e << std::setw(2)
		<< "|" << std::setw(4) << N << std::setw(2) << "|" << std::setw(10)
		<< x_min << std::setw(2) << "|" << std::setw(8) << y_min
		<< std::setw(2) << "|" << std::endl;
}

int main()

{
	double x_min, y_min, x, y;

	double A = -2.5, B = 1.5;  // границы поиска



	std::cout << "+------+-------+------+-----+-----------+---------+\n";

	std::cout << "|   P  |   q   |   e  |  N  |     x     |    y    |\n";

	srand((unsigned)time(NULL));

	std::ofstream fout("Test.txt");

	for (double P = 0.9; P < 1; P += 0.01)  // заданная точность

	{
		for (double q = 0.005; q < 0.105;
			q += 0.005)  // вероятность попадания в окрестность

		{
			double e = (B - A) * q;

			double N = ceil(log(1 - P) / log(1 - q));  // оценка необходимого числа
													   // испытаний N для определения
													   // минимума с требуемой
													   // точностью

			x_min = A;

			y_min = fun(A);

			for (auto i = 0; i < N; ++i)

			{
				std::default_random_engine e{ std::random_device()() };

				std::uniform_real_distribution<> dist(A, B);

				x = dist(e);

				y = fun(x);

				if (y < y_min)

				{
					x_min = x;

					y_min = y;
				}
			}

			print_2(P, q, e, N, x_min, y_min);

			fout << q << "    " << N << "\n";
		}
	}

	std::cout << "+------+-------+------+-----+-----------+---------+\n";
}
