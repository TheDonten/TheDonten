// MOlablyat(2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
class main_criteri {
private:
	std::vector<std::vector<double>> matrix;
	std::vector<double> krit;
public:
	void parse(std::string& str) {

		//char op;

		char abc[4] = { 'A','B','C','D' };
		std::ifstream stream;
		stream.open(str.c_str());
		if (stream.is_open()) {
			matrix.resize(4);
			for (int i = 0; i < 4; ++i) {
				matrix[i].resize(4);
				for (int j = 0; j < 4; ++j) {
					double k = 0;
					stream >> k;
					matrix[i][j] = k;
				}
			}
			write(std::cout, matrix);
			std::vector<double> y1;
			for (int i = 0; i < 4; ++i) {
				double k = 0;
				stream >> k;
				y1.push_back(k);
		  }
			double l = 0;
			for (int i = 0; i < 4; ++i) {
				l += y1[i];
			}
			for (int i = 0; i < 4; ++i) {
				y1[i] /= l;
			}
			for (int i = 0; i < 4; ++i) {
				double l = 0;
				for (int j = 0; j < 4; ++j) {
					l += matrix[j][i];
				}
				for (int j = 0; j < 4; ++j) {
					matrix[j][i] /= l;
				}

			}
			/*for (int i = 0; i < 4; ++i) {
				for (int j = 0; j < 4; ++j) {
					matrix[j][i] = matrix[i][j];
				}
			}**/
			std::vector<std::vector<double>> result_matrix;
			result_matrix.resize(4);
			for (int i = 0; i < 4; ++i) {
				result_matrix[i].resize(4);
				for (int j = 0; j < 4; ++j) {
					
					for (int k = 0; k < 4; ++k) {
						
						result_matrix[i][j] += matrix[i][k]*y1[k];
					}
				}
			}
			std::vector<double> any;
			
			int p = 0;
			for (int i = 0; i < 3; ++i) {
				if (result_matrix[p][0] < result_matrix[i + 1][0])
					++p;
			}
			for (int i = 0; i < 4; ++i) {
				std::cout << std::setw(10) << abc[i] << "  " << std::setw(10) << result_matrix[i][0] << std::endl;
			}
			std::cout << std::endl;
			std::cout << abc[p] << "-> "<<result_matrix[p][0];
		}
		
		
	

	}
	std::ostream& write(std::ostream& stream, std::vector<std::vector<double>> &si) {
		int a[4] = { 1,2,3,4 };
		char b[4] = { 'A','B','C','D' };
		std::cout << "     ";
		for (int i = 0; i < 4; ++i) {
			stream << std::setw(10) << a[i];

		}
		stream << std::endl;
		stream << std::endl;
		for (int i = 0; i < 4; ++i) {
			stream << std::setw(3) << b[i];
			for (int j = 0; j < 4; ++j) {
				if (si[i][j] == int(si[i][j])) {

					stream << std::setw(10) << si[i][j];

				}
				else {
					stream << std::setw(10) << std::setprecision(3) << si[i][j];
				}

			}
			stream << std::endl << std::endl;
		}
		return stream;

	}
};
int main()
{
	std::string str;
	std::cin >> str;
	main_criteri A;
	A.parse(str);

}

