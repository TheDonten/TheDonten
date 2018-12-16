#include "pch.h"

#include <iostream>

#include <cmath>

#include <time.h>

#include <iomanip>

#include <iterator>

#include <random>

#include <vector>

#include <fstream>

#include <unordered_map>
#include <utility>



double fun(double x)

{

	return (sin(x) + 0.5);

}



std::vector<double> generate_alpha(int r, int M)

{

	

	double A = 0, B;
	std::random_device rd{};
	std::default_random_engine gen{ rd() };

	std::uniform_real_distribution<> dist_1(0, 1);

	double alpha_M_1 = dist_1(gen);

	int r_range = int((r - 1) / 2);

	std::vector<double> alpha;

	alpha.push_back(alpha_M_1);

	for (auto i = 0; i < r_range; ++i)

	{

		B = 0;

		for (auto j = 0; j < alpha.size(); ++j)

		{

			B += alpha[j];

		}

		if (i == r_range - 1)

		{

			double element = 0.5 *(1 - B);

			alpha.push_back(element);

			alpha.insert(alpha.begin(), element);

		}

		else

		{

			B = 1 - B;

			std::uniform_real_distribution<> dist_2(0, B);

			double Rand_el = 0.5 * dist_2(gen);

			alpha.push_back(Rand_el);

			alpha.insert(alpha.begin(), Rand_el);

		}



	}

	return alpha;

}



std::vector<double> noise(std::vector<double> alpha, int K[101])

{

	double x_min = 0;

	double x_max = 3.1415926;

	std::vector<double> noise_fun;
	double a = 0.25;
	for (auto i = 0; i < 101; ++i)

	{

		double x_k = x_min + K[i] * (x_max - x_min) / 100;

		std::random_device rd{};
		std::default_random_engine gen{ rd() };



		std::uniform_real_distribution<> dist(-a, a);

		double el = fun(x_k) + dist(gen);

		noise_fun.push_back(el);

	}

	return noise_fun;

}



std::vector<double> filr_fun(std::vector<double> noise_fun, std::vector<double> alpha, int K[101], int M)

{

	std::vector<double> filter_fun;

	for (auto i = 0; i < 101; ++i)

	{

		double J_begin = K[i] - M, J_end = K[i] + M + 1;

		if (J_begin < 0 || J_end > 101) continue;

		double sum = 0;

		double x_k = 0 + K[i] * (3.1415926 - 0) / 100;

		for (auto j = J_begin; j < J_end; ++j)

		{

			double noise_el = noise_fun[j];

			double alpha_el = alpha[j + M + 1 - K[i] - 1];

			double el = noise_el * alpha_el;

			sum += el;
		  



		}

		filter_fun.push_back(sum);

	}

	return filter_fun;

}




double Cheb_dis_w(std::vector<double> filter_fun) {
	double max_m = 0;
	for (int i = 1; i < filter_fun.size(); ++i) {
		double element = abs(filter_fun[i] - filter_fun[i - 1]);
			//max_m = max(element, max_m);
	
			if (element > max_m) max_m = element;
	}
	return max_m;
}
double Cheb_dis_d(std::vector<double> filter_fun, std::vector<double> noise_fun) {
	noise_fun.pop_back();
	noise_fun.erase(noise_fun.begin());
	double max_m = 0;
	for (int i = 1; i < filter_fun.size(); ++i) {
		double element = abs(filter_fun[i] - noise_fun[i]);
		//max_m = max(element, max_m);

		if (element > max_m) max_m = element;
	}
	return max_m;
}
double Cheb_dis_w_d(double w, double d) {
	if (w > d) return w;
	else return d;
}

double fun_J(double h, double w, double d)

{

	return h * w + (1 - h) * d;

}



struct mas {
public:
	double min_dis_J;
	std::vector<double> min_alpha;
	double min_w;
	double min_d;
    std::vector<double> min_filt_func;
	double min_j;
};

int main()

{



	double x_min = 0;

	double x_max = 3.1415926;

	int r = 3;  // r = 5

	int	M = int((r - 1) / 2);

	int K[101];

	for (auto i = 0; i <= 100; ++i)

	{

		K[i] = i;

	}

	double a = 0.5 / 2; // амплитуда равномерного шума

	double H[11];

	for (auto i = 0; i < 11; ++i)

	{

		H[i] = i / 10;

	}

	double P = 0.95;

	double e = 0.01;

	int N = log(1 - P) / (log(1 - (e / (x_max - x_min))));

	std::vector<double> alpha = generate_alpha(r, M);

	std::vector<double> noise_fun = noise(alpha, K);



	double min_J = 100;

	double min_dis_J = 100;

	std::vector<double> min_alpha = { 0, 0, 0 };

	double min_w = 0;

	double min_d = 0;

	std::vector<double> min_fun;
	std::vector<mas> is_struct;
	
	for (auto h : H)

	{



		for (auto j = 0; j < N; ++j)

		{

			alpha = generate_alpha(r, M);

			std::vector<double>filtr_fun = filr_fun(noise_fun, alpha, K, M);

			double	w = Cheb_dis_w(filtr_fun);

			double	d = Cheb_dis_d(filtr_fun, noise_fun);

			double	J = fun_J(h, w, d);

			double	dis_J = Cheb_dis_w_d(w, d);

			if (dis_J < min_dis_J)

			{

				min_alpha = alpha;

				min_dis_J = dis_J;

				min_J = J;

				min_w = w;

				min_d = d;

				min_fun = filtr_fun;
				
				
			}



		}
		mas my;
		my.min_dis_J = min_dis_J;
		my.min_alpha = min_alpha;
		my.min_w = min_w;
		my.min_d = min_d;
		my.min_filt_func = min_fun;
		my.min_j = min_J;
		is_struct.push_back(my);
	}
	double min_dis = 100;
	int count = 0;
	for (int h = 0; h < is_struct.size(); ++h) {
		 
		if (is_struct[h].min_dis_J < min_dis) {
			min_dis = is_struct[h].min_dis_J;
			count = h;
		}
	}
	std::vector<double> f_f_f = is_struct[count].min_filt_func;
	std::cout << "filter func" << std::endl;
	for (int i = 0; i < f_f_f.size(); ++i) {
		std::cout << "(" << (K[i] * 3.1415926) / 100 << ";" << f_f_f[i] << ")" << std::endl;
	}

	std::cout << "Shuum" << std::endl;

	for (auto i = 0; i < noise_fun.size(); ++i)

	{

		std::cout << "(" << (K[i] * 3.1415926) / 100 << ";" << noise_fun[i] << ")" << std::endl;

	}
	for (auto i = 0; i < is_struct.size(); ++i) {
		if (count == i) std::cout << "Optimal" << std::endl;
		std::cout << "n=  " << i << "   alphs:(" << is_struct[i].min_alpha[0] << " , " << is_struct[i].min_alpha[1] << " , " << is_struct[i].min_alpha[2] << ")" << std::endl;
	}
	std::cout << "Optimal" << "  w= " << is_struct[count].min_w << "  d=" << is_struct[count].min_d << "  J=" << is_struct[count].min_j << std::endl;
	/*std::cout << "\n Filter Func f(xk)" << std::endl;

	for (auto i = 0; i < min_fun.size(); ++i)

	{

		std::cout << "(" << (K[i] * 3.1415926) / 100 << ";" << min_fun[i] << ")" << std::endl;

	}



	std::cout << "\n Noise Func f(xk)" << std::endl;

	for (auto i = 0; i < noise_fun.size(); ++i)

	{

		std::cout << noise_fun[i] << std::endl;

	}

	std::cout << "\n Alphs" << std::endl;

	for (auto i = 0; i < min_alpha.size(); ++i)

	{

		std::cout << min_alpha[i] << std::endl;

	}

	std::cout << "\n Alphs" << std::endl;

	for (auto i = 0; i < min_alpha.size(); ++i)

	{

		std::cout << min_alpha[i] << std::endl;

	}*/

}
