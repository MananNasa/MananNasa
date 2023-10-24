#include <stdio.h>

int reverse(int n) 
{
  int reversed_number = 0;
  while (n > 0) {
    reversed_number = reversed_number * 10 + n % 10;
    n /= 10;
  }
  return reversed_number;
}

void coprime(int n) 
{
  int reversed_number = reverse(n);
  int gcd = 1;
  for (int i = 1; i <= n && i <= reversed_number; i++)
  {
    if (n % i == 0 && reversed_number % i == 0) 
    {
      gcd = i;
    }
  }

  if (gcd == 1) 
  {
    printf("%d and %d are co-prime\n", n, reversed_number);
  }
  else 
  {
    printf("%d and %d are not co-prime\n", n, reversed_number);
  }
}

int main() 
{
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  coprime(n);

  return 0;
}
