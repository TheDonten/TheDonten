// MOlablyat4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<sstream>
#include<cstdlib>
#include <iomanip>
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
		
		first_t(str,first);
		first_t(str, first);
		first_t(str, first);
		first_t(str, first);
		std::cout << std::endl << "Sravnenie Kriterieev" << std::endl;
		first_t(str, criterii);
		std::cout << std::endl << " Otvet" << std::endl;
		mult_matrix();
		//third_t();
		//four_t();
		//end();
	}
	void mult_matrix() {
		std::vector<std::vector<double>> matrix;
		char abc[4] = { 'A', 'B', 'C', 'D' };
		std::cout << "             ";
		for (int i = 0; i < 4; ++i) {
			std::cout << std::setw(8) << abc[i] << "   ";
		}
		matrix.resize(4);
		for (int i = 0; i < 4; ++i) {
			matrix[i].resize(4);
			for (int j = 0; j < 4; ++j) {
				matrix[i][j] = first[j];
				
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
				result_matrix[i][j] += matrix[i][j] * criterii[j];
			}
		}

		for (int i = 0; i < 4; ++i) {
			std::cout << std::endl;
			std::cout << std::setw(14) << str[i];
			for (int j = 0; j < 4; ++j) {
				if (result_matrix[i][j] == int(result_matrix[i][j])) {

					std::cout << std::setw(10) << result_matrix[i][j];

				}
				else {
					std::cout << std::setw(10) << std::setprecision(3) << result_matrix[i][j];
				}

			}
			//std::cout << std::endl << std::endl;
		}
	}
	void first_t(std::vector<std::string> &str, std::vector<double>& any) {
		
		std::cin.get();
		std::string string;
		std::getline(std::cin, string);
	
		//std::getline(std::cin, str);
		//std::istringstream stream(str);
		double k;
		std::vector < std::vector<double> > matrix;
		matrix.resize(4);
		bool flag = true;
		for (int i = 0; i < 4; ++i) {
			std::string str;
			std::getline(std::cin, str);
			std::istringstream stream(str);
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
		
		str.push_back(string);
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
			std::cout << abc1[i] << "   ";
		}

		for (int i = 0; i < 4; ++i) {
			std::cout << std::endl;
			std::cout << abc[i] << "   ";
			
			for (int j = 0; j < 6; ++j) {
				std::cout << matrix[i][j] << "   ";
			}
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
