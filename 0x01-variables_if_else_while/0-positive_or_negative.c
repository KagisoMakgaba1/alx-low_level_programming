#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/*
* Main - Determine if a random number is positive, negative or zero.
* Return: always 0 (success)
*/
int main(void)
{
int n;

srand(time(0));
n = rand() - RAND_MAX / 2;
if (n > 0)
printf("%i is positive\n", n);
else if (n < 0)
printf("%i is negative\n", n);
else
printf("%i is zero\n", n);
return (0);
}
