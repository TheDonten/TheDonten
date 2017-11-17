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
void mergeSort(double *array, int l, int r) {
  if(l==r) return;//границы сомкнулись
  int mid=(l+r)/2;
  mergeSort(array,l,mid);
  mergeSort(array,mid+1,r);
  int i=l;
  int j=mid+1;
  int *tmp=new int[r];//доп. массив
  for(int step=0;step<r-l+1;step++){//для всех элементов доп.массива
  	if((j>r) || ((i<=mid) && (array[i]<array[j]))){ // j>r для того чтобы последний элемент доп.массива 
  		tmp[step]=array[i];
  		i++;
	  }
    else{
    	tmp[step]=array[j];
    	j++;
	}
  }
  for (int step = 0; step < r - l + 1; step++)//копируем в исходный массив
    array[l + step] = tmp[step];

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
  if (!(stream >> size && (size>0))) {
    cout << "An error has occured while reading numbers from line";
    return -1;
  }
  double *array = new double[size];
  if (read(array, size)) {
    mergeSort(array, 0,size-1);
    print_array(array, size);
    
  }
 delete[] array;
  else {
    cout << "An error has occured while reading numbers from line";
   
  }
  
  
}
