#include <iostream>
#include <sstream>
using namespace std;

void print_pole(char array[3][3]) {
  cout << "    1   2   3" << endl;
  cout << "  +---+---+---+" << endl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == 0 && j == 0) {
        cout << "a | " << array[0][0] << " | ";
      }
      if (i == 0 && j == 1) {
        cout << array[0][1] << " | ";
      }
      if (i == 0 && j == 2) {
        cout << array[0][2] << " |" << endl;
        cout << "  +---+---+---+" << endl;
      }
      if (i == 1 && j == 0) {
        cout << "b | " << array[1][0] << " | ";
      }
      if (i == 1 && j == 1) {
        cout << array[1][1] << " | ";
      }
      if (i == 1 && j == 2) {
        cout << array[1][2] << " |" << endl;
        cout << "  +---+---+---+" << endl;
      }
      if (i == 2 && j == 0) {
        cout << "c | " << array[2][0] << " | ";
      }
      if (i == 2 && j == 1) {
        cout << array[2][1] << " | ";
      }
      if (i == 2 && j == 2) {
        cout << array[2][2] << " |" << endl;
      }
    }
  }
  cout << "  +---+---+---+" << endl;
}
void show_move(char array[3][3], char op) {
  int k = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
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
      }
    }
  }
  cout << ++k << ". quit" << endl;
}
bool win_game(char array[3][3]) {
  if ((array[0][0] == 'X' || array[0][0] == 'O') &&
      array[0][0] == array[1][0] && array[0][0] == array[2][0])
    return true;
  if ((array[0][2] == 'X' || array[0][2] == 'O') &&
      array[0][2] == array[1][2] && array[0][2] == array[2][2])
    return true;
  if ((array[0][0] == 'X' || array[0][0] == 'O') &&
      array[0][0] == array[0][1] && array[0][0] == array[0][2])
    return true;
  if ((array[1][0] == 'X' || array[1][0] == 'O') &&
      array[1][0] == array[1][1] && array[1][0] == array[1][2])
    return true;
  if ((array[2][0] == 'X' || array[2][0] == 'O') &&
      array[2][0] == array[2][1] && array[2][0] == array[2][2])
    return true;
  if ((array[0][0] == 'X' || array[0][0] == 'O') &&
      array[0][0] == array[1][1] && array[0][0] == array[2][2])
    return true;
  if ((array[0][2] == 'X' || array[0][2] == 'O') &&
      array[0][2] == array[1][1] && array[0][2] == array[2][0])
    return true;
  return false;
}
bool proverka(char array[3][3]) {
  unsigned int l = 0;
  for (unsigned int i = 0; i < 3; i++) {
    for (unsigned int j = 0; j < 3; j++) {
      if (!(array[i][j] == 'X' || array[i][j] == 'O')) {
        l++;
      }
      if (l > 0) return true;
    }
  }
  cout << " No more motion" << endl;
  return false;
}
void move_move(char array[3][3], unsigned int move, char op) {
  bool found = false;
  int k = 0, result_i = 0, result_j = 0;
  for (unsigned int i = 0; i < 3 && !found; i++) {
    for (unsigned int j = 0; j < 3; j++) {
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
  char array[3][3] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
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
    if (move == 10 - i) {
      cout << "Game Over" << endl;
      return -1;
    }
    while (move < 1 || move > (10 - i)) {
      cout << endl << "You can`t use this number, please, try again: ";

      getline(cin, string);
      istringstream stream(string);
      stream >> move;
      if (move == 10 - i) {
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
