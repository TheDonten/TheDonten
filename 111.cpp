
#include "pch.h"
#include <iostream>
#include<vector>
#include<sstream>
#include<cstdlib>
#include <iomanip>
#include <fstream>

class Saate {
private:
	std::vector<double> first;

	std::vector<double> criterii;
	std::vector<std::string> str;
public:
	void algorithm() {


		first_t(first);
		first_t(first);
		first_t(first);
		first_t(first);
		std::cout << std::endl << "Sravnenie Kriterieev" << std::endl;
		first_t(criterii);
		std::cout << std::endl << " Otvet" << std::endl;
		mult_matrix();
	
	}
	void mult_matrix() {
		std::vector<std::vector<double>> matrix;
		char abc[4] = { 'A', 'B', 'C', 'D' };
	
		int k = 0;
		matrix.resize(4);
		for (int i = 0; i < 4; ++i) {
			matrix[i].resize(4);
		}
		for (int i = 0; i < 4 && k < 16; ++i) {

			for (int j = 0; j < 4 && k < 16; ++j) {
				matrix[j][i] = first[k];
				++k;
			}
		}

		std::vector<std::vector<double>> result_matrix;
		result_matrix.resize(4);
		for (int i = 0; i < 4; ++i) {
			result_matrix[i].resize(4);
			for (int j = 0; j < 4; ++j) {
				for (int k = 0; k < 4; ++k) {
					result_matrix[i][j] += matrix[i][k] * criterii[k];
				}
			}
		}


		int p = 0;
		int o = 0;
		for (int i = 0; i < 4; ++i) {
			std::cout << std::setw(10) << abc[i] << "  " << std::setw(10) << result_matrix[i][0] << std::endl;
		}
		for (int i = 0; i < 3; ++i) {
			if (result_matrix[p][0] < result_matrix[i + 1][0]) {
				p = i + 1;
				o = i + 1;
			}
		}
		std::cout << std::endl << std::endl;
		std::cout << abc[o] << "->" << "    " << result_matrix[p][0] << "   " << "optimal";
	}
	void first_t(std::vector<double>& any) {
		std::cout << std::endl << "Press Enter" << std::endl;
		std::cin.get();
		std::string string;
		std::ifstream stream;
		std::cout << "Cin name kriterei" << std::endl;
		std::cin >> string;
		stream.open(string.c_str());
		//std::getline(std::cin, str);
		//std::istringstream stream(str);
		double k;
		std::vector < std::vector<double> > matrix;
		matrix.resize(4);
		bool flag = true;
		for (int i = 0; i < 4; ++i) {
			matrix[i].resize(4);
			for (int j = 0; j < 4; ++j) {
				stream >> k;
				matrix[i][j] = k;



			}
		}

		for (int i = 0; i < 4; ++i) {
			matrix[i].resize(5);
			double k = 0;
			for (int j = 0; j < 5; ++j) {
				k += matrix[i][j];
			}
			matrix[i][4] = k;
		}
		double l = 0;
		for (int i = 0; i < 4; ++i) {
			l += matrix[i][4];
		}

		//str.push_back(string);
		std::cout << string << std::endl;
		for (int i = 0; i < 4; ++i) {
			matrix[i].resize(6);
			matrix[i][5] = matrix[i][4] / l;
			any.push_back(matrix[i][5]);
		}
		char abc[4] = { 'A', 'B', 'C', 'D' };
		char abc1[6] = { 'A', 'B', 'C', 'D', 'S', 'n' };
		std::cout << "          ";
		for (int i = 0; i < 6; ++i) {
			std::cout << abc1[i] << "         ";
		}

	
		for (int i = 0; i < 4; ++i) {
			std::cout << std::endl;
			std::cout << abc[i];
			for (int j = 0; j < 6; ++j) {
				if (matrix[i][j] == int(matrix[i][j])) {

					std::cout << std::setw(10) << matrix[i][j];

				}
				else {
					std::cout << std::setw(10) << std::setprecision(3) << matrix[i][j];
				}

			}
			//std::cout << std::endl << std::endl;
		}


	}

};

int main() {
	Saate  meh;
	meh.algorithm();
}
