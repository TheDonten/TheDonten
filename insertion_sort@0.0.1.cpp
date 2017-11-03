#include <iostream>
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
void insertion_sort(double *array, unsigned int size) {
  for (unsigned int i = 1; i < size; i++) {
    for (unsigned j = i; j > 0 && array[j - 1] > array[j]; j--) {
      swap(array[j - 1], array[j]);
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
    insertion_sort(array, size);
    print_array(array, size);
    cin.get();
  }

  else {
    cout << "An error has occured while reading numbers from line";
    cin.get();
  }
  delete[] array;
  return 0;
}
