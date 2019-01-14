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
		
		
		std::ifstream stream;
		stream.open(str.c_str());
		if (stream.is_open()) {
			matrix.resize(4);
			for (int i = 0; i < 4; ++i) {
				matrix[i].resize(4);
				for (int j = 0; j < 4; ++j) {
					int k = 0;
					stream >> k;
					matrix[i][j] = k;
				}
			}
			//	int k = 0;
			int l = 0;
			for (int i = 1; i < 4; ++i) {
				for (int j = 0; j < 4; ++j) {
					l += matrix[j][i];

				}
				for (int j = 0; j < 4; ++j) {
					matrix[j][i] = matrix[j][i] / l;
				}
				l = 0;
			}


			double k = 0;
			while (stream) {
				stream >> k;
				krit.push_back(k);
			}
		}
		char b[4] = { 'A','B','C','D' };
		std::vector<char> dik;
		std::vector<int> nomer;
		bool flag = true;
		for (int i = 0; i < 4; ++i) {
			for (int j = 1; j < 4; ++j) {
				if (matrix[i][j] >= krit[j - 1]) {
					flag = true;
				}
				else {
					flag = false;
					break;
				}
			}
			if (flag) { 
				dik.push_back(b[i]); 
				nomer.push_back(i);
			    
			}
		}
		write(std::cout, matrix);
		int k = 2;
		for (int i = 0; i < 3; ++i) {
			std::cout << k << "-> " << krit[i] <<"   ";
			++k;
		}
		char diki = dik.front();
		int p = nomer[0];
		
		for (int i = 0; i < nomer.size() - 1; ++i) {
			
			if (matrix[p][0] < matrix[nomer[i + 1]][0]) {
				diki = dik[i + 1];
				p = nomer[i + 1];
			}
		}
		std::cout << std::endl << diki;

	}
	std::ostream& write(std::ostream& stream,  std::vector<std::vector<double>> &si) {
		int a[4] = { 1,2,3,4 };
		char b[4] = { 'A','B','C','D' };
		std::cout << "   ";
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


