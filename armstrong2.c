#include <stdio.h>

int is_armstrong(int n) {
  int sum = 0;
  while (n > 0) {
    int digit = n % 10;
    sum += digit * digit * digit;
    n /= 10;
  }
  return sum == n;
}

int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  if (is_armstrong(n)) {
    printf("%d is an Armstrong number.\n", n);
  } else {
    printf("%d is not an Armstrong number.\n", n);
  }

  return 0;
}
