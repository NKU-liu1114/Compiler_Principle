#include<stdio.h>
int main()
{
  int a, b, i, t, n; 
  a = 0;
  b = 1;
  i = 1;
  printf("Please enter the number of items in the Fibonacci sequence:");
  scanf("%d",&n);
  printf("The result is:\n%d\n",b);
  while (i < n){
  t = b;
  b = a + b;
  printf("%d\n",b);
  a = t;
  i = i + 1;
  }
  return 0;
}