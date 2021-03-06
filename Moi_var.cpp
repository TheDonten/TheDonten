// GeneticCode.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <random>
/*Пусть будет ограничекние а=3 b=6*/
 struct Gen {
 public:
	float x;
	float y;
	float func;
	Gen* next;
	Gen* parent;
};
 float rnd() {
	        
	 std::random_device rd{};
	 std::default_random_engine e{ rd() };
	 std::uniform_real_distribution<> dis(-1, 1);
			 return dis(e); 
 }
 float rnd_delta() {
	
	 std::random_device rd{};
	 std::default_random_engine e{ rd() };
	 std::uniform_real_distribution<> dis(0, 1);
	 return dis(e);
 }
 float find_func(float x,float y) {
	 float a = 0;
	// a = ((exp(x*x))*exp(y*y)) / (1 + pow(x, 2) + pow(y, 2));
	/* a = (exp(-(x*x))*
		 exp(-(y*y))) /
		 (1 + x*x + y*y);*/
	 a = sqrt(log(1 + pow(x, 2) + pow(y, 2)))*(-1);
	
	 return a;
 }

 unsigned int find_min(Gen *&head) {
	 unsigned int k = 0;
	 Gen* last = head;
	 std::vector<float> min;
	 while (last) {
		 min.push_back(last->func);
		 last = last->next;
	 }
	 for (int i = 0; i < min.size() -1; ++i) {
		 if (min[k] > min[i + 1]) {
			 k = i + 1;
		 }
	 }
	 return k;
 }
 unsigned int find_max(Gen*&head) {
	 std::size_t k = 0;
	 Gen* last = head;
	 std::vector<float> min;
	 while (last) {
		 min.push_back(last->func);
		 last = last->next;
	 }
	 for (int i = 0; i < min.size() - 1; ++i) {
		 if (min[k] < min[i + 1]) {
			 k = i + 1;
		 }
	 }
	 return k;
 }
 void delete_dudes(Gen*& head) {
	 int k = find_min(head);
	 Gen* last = head;
	 int i = 0;
	 while (last) {
		 if (i == k) {
			 if (last == head) {
				 std::cout << " Killing dude:  " << last->func << std::endl;
				 Gen* next = last->next;
				 next->parent = nullptr;
				 delete head;
				 head = next;
				 break;
			 }
			 else if(last->next == nullptr) {
				 std::cout << " Killing dude:  " << last->func << std::endl;
				 last->parent->next = nullptr;
				 delete last;
				 break;
			 }
			 else {
				 std::cout <<" Killing dude:  " <<last->func << std::endl;
				 last->next->parent = last->parent;
				 last->parent->next = last->next;
				 delete last;
				 break;
			 }
		 }
		 last = last->next;
		 ++i;
	 }
 }
 void add(Gen*&head) {
	 Gen* node = new Gen;
	 std::srand(std::time(nullptr));
	 node->x = rnd();
	 node->y = rnd();
	 node->func = find_func(node->x, node->y);
	 node->next = nullptr;
	 node->parent = nullptr;
	 if (head == nullptr) {
		 head = node;
		 return;
	 }
	 Gen* last = head;
	 while (last->next) {
		 last = last->next;
	 }
	 
	 last->next = node;
	 last->next->parent = last;
	 
 }
 void add_population(Gen*&head,float x, float y) {
	 Gen* node = new Gen;
	 node->x = x;
	 node->y = y;
	 node->func = find_func(node->x, node->y);
	 node->next = nullptr;
	 node->parent = nullptr;
	 if (head == nullptr) {
		 head = node;
		 return;
	 }
	 Gen* last = head;
	 while (last->next) {
		 last = last->next;
	 }

	 last->next = node;
	 last->next->parent = last;

 }
 Gen* crossover(Gen*& head) {
	 unsigned int k = find_max(head);
	 std::pair<float, float> elem;
	 Gen* last = head;
	 unsigned int j = 0;
	 while (last) {
		 if (k == j) {
			 elem.first = last->x;
			 elem.second = last->y;
		 }
		 last = last->next;
		 ++j;
	 }
	 Gen* child = nullptr;
	 last = head;
	 unsigned int i = 0;
	 while (last) {
		 if (k != i) {
			 add_population(child, elem.first, last->y);
			 add_population(child, last->x, elem.second);
		 }
		 ++i;
		 last = last->next;
	 }
	 Gen* node = nullptr;
	 while (head) {
		 node = head->next;
		 delete head;
		 head = node;

	 }
	
	 return child;
 }
 Gen* mutation(Gen*& head) {
	 Gen* last = head;
	 Gen* child = nullptr;
	 int size = 0;
	 while (last) {
		 last = last->next;
		 ++size;
	 }
	 last = head;
	 std::srand(std::time(nullptr));
	 while(last) {
		
		 float deltaX = rnd_delta();
		 float deltaY = rnd_delta();
		 if (last->x > 0 && last->y > 0) {
			 deltaX = last->x - deltaX;
			 deltaY = last->y - deltaY;
			 if (deltaX <= -2) {
				 deltaX = -2 + (deltaX*(-1));
				 deltaX = last->x + deltaX;
				 deltaY = -2 + (deltaY*(-1));
				 deltaY = last->y + deltaY;
				// continue;
			 }
			 else if (deltaY <= -2) {
				 deltaY = -2 + (deltaY*(-1));
				 deltaY = last->y + deltaY;
				 deltaX = -2 + (deltaX*(-1));
				 deltaX = last->x + deltaX;
				 //continue;
			 }
			 add_population(child, deltaX, deltaY);
		 }
		 else {
			 deltaX = last->x + deltaX;
			 deltaY = last->y + deltaY;
			 if(deltaX >= 2){
				 deltaX = deltaX - 2;
				 deltaX = last->x - deltaX;
				 deltaY = deltaY - 2;
				 deltaY = last->y - deltaY;
			
			 }
			 else if(deltaY >= 2) {
				 deltaY = deltaY - 2;
				 deltaY = last->y - deltaY;
				 deltaX = deltaX - 2;
				 deltaX = last->x - deltaX;
			
			 }
			 add_population(child, deltaX, deltaY);
		 }
		 last = last->next;
	 }
	 Gen* node = nullptr;
	 while (head) {
		 node = head->next;
		 delete head;
		 head = node;

	 }
	 return child;
 }
 float Max(Gen*&head) {
	 unsigned int k = find_max(head);
	 int i = 0;
	 Gen* last = head;
	 while (last) {
		 if (i == k) {
			 return last->func;
		 }
		 last = last->next;
		 ++i;
	 }
 }
 void GA() {
	 //иницилизируем
	 float maxik = NULL;
	 Gen* head = nullptr;
	 //std::vector<float> maximum;
	 add(head);
	 for (int i = 0; i < 3; ++i) {
		 add(head);
	 }
	Gen* p = head;
	while (p) {
		std::cout << "x=" << p->x << std::endl;
		std::cout << "y=" << p->y << std::endl;
		std::cout << "F=" << p->func << std::endl;
		std::cout << std::endl << std::endl;
		p = p->next;
	}
	 std::cout << " VAUUU" << std::endl;
	
	 delete_dudes(head);
	 for (int i = 0; i < 100; ++i) {
		 std::cout << "Numer generations:  " << i + 1 << std::endl;
		 head = crossover(head);
		 head = mutation(head);
		 
		 p = head;
		 while (p) {
			 std::cout << "x=" << p->x << std::endl;
			 std::cout << "y=" << p->y << std::endl;
			 std::cout << "F=" << p->func << std::endl;
			 std::cout << std::endl << std::endl;
			 p = p->next;
		 }
		 delete_dudes(head);
		 //maximum.push_back(Max(head));
		 if (maxik == NULL) {
			 maxik = Max(head);
		 }
		 else {
			 if (maxik <= Max(head)) {
				 maxik = Max(head);
			 }
		 }
		 std::cout << "MAX:  " << Max(head) << std::endl;
	 }
	// auto it = std::max_element(maximum.begin(), maximum.end());
	 std::cout << std::endl <<"Max = " << maxik << std::endl;
	
	 Gen* node = nullptr;
	 while (head) {
		 node = head->next;
		 delete head;
		 head = node;

	 }
 }

int main()
{   
	GA();
	//std::cout << pow(, 2);
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
