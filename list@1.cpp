#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct node_t {
  int value;
  node_t *next;
};
void add(node_t *&head, int value) {
  node_t *node = new node_t;
  node->value = value;
  node->next = NULL;
  if (head == NULL) {
    head = node;
    return;
  }
  node_t *last = head;
  while (last->next) {
    last = last->next;
  }
  last->next = node;
}
void write(node_t *&head) {
  node_t *p;
  p = head;
  while (p != NULL) {
    cout << "+---+"
         << "    ";
    p = p->next;
  }
  p = head;
  cout << endl;
  while (p != NULL) {
    cout << "| " << p->value << " |";
    p = p->next;
    if (p != NULL) {
      cout << "--->";
    }
  }
  p = head;
  cout << endl;
  while (p != NULL) {
    cout << "+---+"
         << "    ";
    p = p->next;
  }
  cout << endl;
}
void destroy(node_t *&head) {
  if (head) {
    node_t *next = head->next;
    delete head;
    head = next;
  }
}
void reverse(node_t *&head, int size) {
  node_t *l = head;
  for (int i = 0; i < size / 2; i++) {
    node_t *r = head;
    for (int j = 0; j < size - 1 - i; j++) {
      r = r->next;
    }
    swap(l->value, r->value);
    l = l->next;
  }
}
int main() {
  node_t *head = NULL;
  int size = 0;
  int a = 0;
  char op;
  while (cin >> op && op != 'q') {
    if (op == '=') {
      write(head);
    }
    if (op == '+') {
      cin >> a;
      add(head, a);
      size++;
      write(head);
    }
    if (op == '-') {
      destroy(head);
      size--;
      write(head);
    }
    if (op == '/') {
      reverse(head, size);
      write(head);
    }
  }
}
