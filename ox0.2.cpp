#include <iostream>
#include <sstream>
using namespace std;

void print_pole(char array[5][5]) {
  cout << "    1   2   3   4   5" << endl;
  cout << "  +---+---+---+---+---+" << endl;

  cout << "a | " << array[0][0] << " | " << array[0][1] << " | " << array[0][2]
       << " | " << array[0][3] << " | " << array[0][4] << " | " << endl;
  cout << "  +---+---+---+---+---+" << endl;
  cout << "b | " << array[1][0] << " | " << array[1][1] << " | " << array[1][2]
       << " | " << array[1][3] << " | " << array[1][4] << " | " << endl;
  cout << "  +---+---+---+---+---+" << endl;
  cout << "c | " << array[2][0] << " | " << array[2][1] << " | " << array[2][2]
       << " | " << array[2][3] << " | " << array[2][4] << " | " << endl;
  cout << "  +---+---+---+---+---+" << endl;
  cout << "d | " << array[3][0] << " | " << array[3][1] << " | " << array[3][2]
       << " | " << array[3][3] << " | " << array[3][4] << " | " << endl;
  cout << "  +---+---+---+---+---+" << endl;
  cout << "e | " << array[4][0] << " | " << array[4][1] << " | " << array[4][2]
       << " | " << array[4][3] << " | " << array[4][4] << " | " << endl;
  cout << "  +---+---+---+---+---+" << endl;
}
void show_move(char array[5][5], char op) {
  int k = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (!(array[i][j] == 'X' || array[i][j] == 'O')) {
        if (i == 0) {
          cout << ++k << ".mark cell a" << j + 1 << " as " << op << endl;
        }
        if (i == 1) {
          cout << ++k << ".mark cell b" << j + 1 << " as " << op << endl;
        }
        if (i == 2) {
          cout << ++k << ".mark cell c" << j + 1 << " as " << op << endl;
        }
        if (i == 3) {
          cout << ++k << ".mark cell d" << j + 1 << " as " << op << endl;
        }
        if (i == 4) {
          cout << ++k << ".mark cell e" << j + 1 << " as " << op << endl;
        }
      }
    }
  }
  cout << ++k << ". quit" << endl;
}
bool win_game(char array[5][5]) {
  for (unsigned int i = 0; i < 5; i++) {
    int j = 0;
    if (array[i][j] == 'X' || array[i][j] == 'O') {
      if (array[i][j] == array[i][j + 1] && array[i][j] == array[i][j + 2] &&
          array[i][j] == array[i][j + 3] && array[i][j] == array[i][j + 4]) {
        return true;
        break;
      }
    }
  }
  for (unsigned int j = 0; j < 5; j++) {
    int i = 0;
    if (array[i][j] == 'X' || array[i][j] == 'O') {
      if (array[i][j] == array[i + 1][j] && array[i][j] == array[i + 2][j] &&
          array[i][j] == array[i + 3][j] && array[i][j] == array[i + 4][j]) {
        return true;
        break;
      }
    }
  }

  if (array[0][0] == 'X' || array[0][0] == 'O') {
    if (array[0][0] == array[1][1] && array[0][0] == array[2][2] &&
        array[0][0] == array[3][3] && array[0][0] == array[4][4]) {
      return true;
    }
  }
  if (array[0][4] == 'X' || array[0][4] == 'O') {
    if (array[0][4] == array[1][3] && array[0][4] == array[2][2] &&
        array[0][0] == array[3][1] && array[0][0] == array[4][0]) {
      return true;
    }
  }

  return false;
}

bool proverka(char array[5][5]) {
  unsigned int l = 0;
  for (unsigned int i = 0; i < 5; i++) {
    for (unsigned int j = 0; j < 5; j++) {
      if (!(array[i][j] == 'X' || array[i][j] == 'O')) {
        l++;
      }
      if (l > 0) return true;
    }
  }
  cout << " No more motion" << endl;
  return false;
}
void move_move(char array[5][5], unsigned int move, char op) {
  bool found = false;
  int k = 0, result_i = 0, result_j = 0;
  for (unsigned int i = 0; i < 5 && !found; i++) {
    for (unsigned int j = 0; j < 5; j++) {
      if (array[i][j] == 0) {
        k++;
      }
      if (k == move) {
        found = true;
        result_i = i;
        result_j = j;
        break;
      }
    }
  }
  array[result_i][result_j] = op;
}
int main() {
  unsigned int i = 0;
  char array[5][5] = {};
  char op;
  unsigned int k = 0;
  unsigned int move;
  bool found = false, ok = true, choose = true;
  print_pole(array);
  while (proverka(array)) {
    if (choose == true)
      op = 'X';
    else
      op = 'O';
    show_move(array, op);
    string string;
    getline(cin, string);
    istringstream stream(string);
    stream >> move;
    if (move == 26 - i) {
      cout << "Game Over" << endl;
      return -1;
    }
    while (move < 1 || move > (26 - i)) {
      cout << endl << "You can`t use this number, please, try again: ";

      getline(cin, string);
      istringstream stream(string);
      stream >> move;
      if (move == 26 - i) {
        cout << "Game Over" << endl;
        return -1;
      }
    }
    move_move(array, move, op);

    if (ok == found) break;
    print_pole(array);
    if (win_game(array)) {
      cout << endl << "Player " << op << " is winner!";
      cin.get();
      return 0;
    }
    choose = !choose;
    i++;
  }
}
