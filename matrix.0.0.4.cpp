#include <iostream>
#include <sstream>
#include <string>
#include <valarray>
#include <fstream>
using namespace std;
class matrix_t {
 private:
  int** data;
  unsigned int rows;
  unsigned int collumns;

 public:
  matrix_t() {
    data = nullptr;
    rows = 0;
    collumns = 0;
  }
  matrix_t add(matrix_t& other) const {
    matrix_t result;
    if (this->rows == other.rows && this->collumns == other.collumns) {
      result.rows = this->rows;
      result.collumns = this->collumns;
      result.data = new int*[rows];
      for (unsigned int i = 0; i < rows; i++) {
        result.data[i] = new int[collumns];
        for (unsigned int j = 0; j < collumns; j++) {
          result.data[i][j] = this->data[i][j] + other.data[i][j];
        }
      }
    } else
      cout << " An error has occured while reading input data";
    return result;
  }
  matrix_t sub(matrix_t& other) const {
    matrix_t result;
    if (this->rows == other.rows && this->collumns == other.collumns) {
      result.rows = this->rows;
      result.collumns = this->collumns;
      result.data = new int*[rows];
      for (unsigned int i = 0; i < rows; i++) {
        result.data[i] = new int[collumns];
        for (unsigned int j = 0; j < collumns; j++) {
          result.data[i][j] = this->data[i][j] - other.data[i][j];
        }
      }
    } else
      cout << " An error has occured while reading input data";
    return result;
  }
  matrix_t mult(matrix_t& other) const {
    matrix_t result;
    if (this->collumns == other.rows) {
      result.rows = this->rows;
      result.collumns = this->collumns;
      result.data = new int*[rows];
      for (unsigned int i = 0; i < rows; i++) {
        result.data[i] = new int[collumns];
        for (unsigned int j = 0; j < collumns; j++) {
          result.data[i][j] += this->data[i][j] * other.data[i][j];
        }
      }
    } else
      cout << " An error has occured while reading input data";
    return result;
  }

  matrix_t trans() const {
    matrix_t result;
    result.rows = this->rows;
    result.collumns = this->collumns;
    result.data = new int*[rows];
    for (unsigned int i = 0; i < rows; i++) {
      result.data[i] = new int[collumns];
      for (unsigned int j = 0; j < collumns; j++) {
        result.data[i][j] = this->data[j][i];
      }
    }
  }
  ifstream& read(std::ifstream& stream, string Anyfile) {
    stream.open(Anyfile);
    char op;
    if (stream.is_open()) {
      if (stream >> rows && stream >> op && op == ',' && stream >> collumns) {
        data = new int*[rows];
        for (unsigned int i = 0; i < rows; i++) {
          data[i] = new int[collumns];
          for (unsigned int j = 0; j < collumns; j++) {
            stream >> data[i][j];
          }
        }
      }
    }
    stream.close();
    return stream;
  }

  ostream& write(std::ostream& stream) {
    for (unsigned int i = 0; i < rows; i++) {
      cout << endl;
      for (unsigned int j = 0; j < collumns; j++) {
        stream << data[i][j] << " ";
      }
    }
    cout << endl;
  }
  ~matrix_t() {}
};
int main() {
  matrix_t matrix1, matrix2, result;
  char op;
  string Anyfile1, Anyfile2, string;
  ifstream fin1, fin2;
  getline(cin, string);
  istringstream stream(string);
  if (stream >> Anyfile1 && stream >> op) {
    if (matrix1.read(fin1, Anyfile1)) {
      if (op == 'T') {
        matrix1.trans();
        matrix1.write(cout);
      } else if (stream >> Anyfile2 && (op == '+' || op == '*' || op == '-')) {
        if (matrix2.read(fin2, Anyfile2)) {
          switch (op) {
            case '+': {
              result = matrix1.add(matrix2);
              result.write(cout);
              break;
            }
            case '*': {
              result = matrix1.mult(matrix2);
              result.write(cout);
              break;
            }
            case '-': {
              result = matrix1.sub(matrix2);
              result.write(cout);
              break;
            }
          }
        } else
          cout << "An error has occured while reading input data";
      } else
        cout << " An error has occured while reading input data";
    } else
      cout << "An error has occured while reading input data";
  } else
    cout << "An error has occured while reading input data";

  return 0;
}
