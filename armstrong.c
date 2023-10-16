#include <stdio.h>
#include <math.h>

int main() 
{
    int n, num, sum, digit, temp;

    printf("Enter a positive integer n: ");
    scanf("%d", &n);

    printf("Armstrong numbers between 1 and %d are:\n", n);

    for (num = 1; num <= n; ++num) 
    {
        sum = 0;
        temp = num;

        while (temp != 0) 
        {
            digit = temp % 10;
            sum += digit * digit * digit;
            temp /= 10;
        }

        if (num == sum) 
        {
            printf("%d\n", num);
        }
    }

    return 0;
}
