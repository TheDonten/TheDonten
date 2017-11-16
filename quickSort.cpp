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
  int pivot;// разрешающий элемент
  int l_hold = left;//левая граница
  int r_hold = right;// правая граница
  pivot = array[left];
  while (left < right) // пока границы не сомкнутся {
    while ((array[right] >= pivot) && (left < right)) {
      right--;// сдвигаем правую границу пока элемент [right] больше [pivot]
    }
    if (left != right) если границы не сомкнулись {
      array[left] = array[right]; // перемещаем элемент [right] на место разрешающего
      left++;// сдвигаем левую границу вправо 
    }

    while ((array[left] <= pivot) && (left < right)) left++;// сдвигаем левую границу пока элемент [left] меньше [pivot]
    if (left != right)// если границы не сомкнулись {
      array[right] = array[left]; // перемещаем элемент [left] на место [right]
      right--;// сдвигаем правую границу вправо 
    }
  }
  array[left] = pivot;// ставим разрешающий элемент на место
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot) quickSort(array, left, pivot - 1);// Рекурсивно вызываем сортировку для левой и правой части массива
  if (right > pivot) quickSort(array, pivot + 1, right);
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
    quickSort(array, 0, size - 1);// вызов функции сортировки
    print_array(array, size);

  }

  else {
    cout << "An error has occured while reading numbers from line";
  }
  delete[] array;
}
