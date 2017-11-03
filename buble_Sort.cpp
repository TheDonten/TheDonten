#include<iostream>
#include <utility>
#include <sstream>
using namespace std;

bool read(double *array, unsigned int size) {
  bool k = true;
  string mas;
  getline(cin, mas);
  istringstream stream(mas);
  for (int i = 0; i < size; i++) {
    if (!(stream >> array[i])) {
      k = false;
      return false;
    }
  }
  return true;
}
void bubble_sort(double *array, unsigned int size) {
  bool sorted = false;
  while (!sorted) {
    sorted = true;
    for (unsigned int i = 0; i < size - 1; i++) {
      if (array[i] > array[i + 1]) {
        std::swap(array[i], array[i + 1]);
        sorted = false;
      }
    }
  }
}
void print_array(double *array, unsigned int size) {
  for (unsigned int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
}
int main() {
  unsigned int size;
  string string;
  getline(cin, string);
  istringstream stream(string);
  if (!(stream >> size)) {
    cout << "An error has occured while reading numbers from line";
    return -1;
  }
  double *array = new double[size];
  if (read(array, size)) {
    bubble_sort(array, size);
    print_array(array, size);
    cin.get();
  } else {
    cout << "An error has occured while reading numbers from line";
    cin.get();
  }
  delete[] array;
  return 0;
}
