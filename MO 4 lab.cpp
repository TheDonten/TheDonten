// MOlablyat4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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
	//std::vector<double> second;
	//std::vector<double> third;
	//std::vector<double> four;
	std::vector<double> criterii;
	std::vector<std::string> str;
public:
	void algorithm(){
		//std::string str;
		
		first_t(first);
		first_t( first);
		first_t( first);
		first_t( first);
		std::cout << std::endl << "Sravnenie Kriterieev" << std::endl;
		first_t(criterii);
		std::cout << std::endl << " Otvet" << std::endl;
		mult_matrix();
		//third_t()
		//four_t();
		//end();
	}
	void mult_matrix() {
		std::vector<std::vector<double>> matrix;
		char abc[4] = { 'A', 'B', 'C', 'D' };
		/*std::cout << "             ";
		/*for (int i = 0; i < 4; ++i) {
			std::cout << std::setw(8) << abc[i] << "     ";
		}*/
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

	/*	for (int i = 0; i < 4; ++i) {
			std::cout << std::endl;
			std::cout << str[i] << "   ";
			for (int j = 0; j < 4; ++j) {
				std::cout << matrix[i][j] << "   ";
			}
		}*/
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
		std::cout << abc[o] <<"->"<< "    " << result_matrix[p][0] << "   " << "optimal";
	}
	void first_t(std::vector<double>& any) {
		std::cout <<std::endl << "Press Enter" << std::endl;
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
			double k= 0;
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
		std::cout << "    ";
		for (int i = 0; i < 6; ++i) {
			std::cout << abc1[i] << "         ";
		}

		/*for (int i = 0; i < 4; ++i) {
			std::cout << std::endl;
			std::cout << abc[i] << "     ";
			
			for (int j = 0; j < 6; ++j) {
				stream << std::setw(10) << matrix[i][j];
			}
		}*/
		for (int i = 0; i < 4; ++i) {
			std::cout << std::endl;
			std::cout  << abc[i];
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
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
