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
void quickSort(double *array, int left, int right) {
  int l = left;
  int r = right;
  int main_el = l;
  while (l <= r) {
    while (array[l] < array[main_el] && l <= right) l++;
    while (array[r] > array[main_el] && r >= left) r--;
    if (l <= r) {
      swap(array[l], array[r]);
      l++;
      r--;
    }
  }

  if (l < right) quickSort(array, l, right);
  if (r > left) quickSort(array, left, r);
}
void print_array(double *array, unsigned int size) {
  for (unsigned int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
}
int main() {
  int size;
  string string;
  getline(cin, string);
  istringstream stream(string);
  if (!(stream >> size && (size > 0))) {
    cout << "An error has occured while reading numbers from line";
    return -1;
  }
  double *array = new double[size];
  if (read(array, size)) {
    quickSort(array, 0, size - 1);
    print_array(array, size);

  }

  else {
    cout << "An error has occured while reading numbers from line";
  }
  delete[] array;
}
