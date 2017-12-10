#include <iostream>
#include <string>
#include <sstream>
#include <valarray>
#include <cstring>
using namespace std;

void check(string word) {
  int len = word.length();
  for (int i = 0; i < len; ++i) {
    if (word[i] != '\n') {
      cout << word[i] << " ";
      if (word[i] == ' ') {
        cout << "   ";
      }
    }
  }
}
int main() {
  string stroka;
  getline(cin, stroka);
  istringstream stream(stroka);
  check(stroka);
}
