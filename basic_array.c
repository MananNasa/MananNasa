#include <stdio.h>
int *display();

int main() {
  int *p;
  p = display();
  printf("%d\n", *p);
}

int *display() {
  int a = 20;
  // return &a;      // Not correct

  int *p;
  p = &a;
  return p;
}
