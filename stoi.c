#include "rsa_factoring.h"

// unsigned long max = 100;

int stoi(char *str, unsigned long *array)
{
  int i, j, k, len;
  int digit = 1, count = 0;
  unsigned long n = 0, temp_max = max;

  len = strlen(str);
  while (temp_max > 1)
  {
    count++;
    temp_max /= 10;
  }
  for (i = len - 1, j = 0, k = 0; i >= 0;)
  {
    if (k == count)
    {
      array[j++] = n;
      n = 0;
      digit = 1;
      k = 0;
    }
    else
    {
      n += (str[i--] - '0') * digit;
      digit *= 10;
      k++;
    }
  }
  if (n > 0)
    array[j] = n;
  return (j + 1);
}
//
// int main()
// {
//   // 10 00 00
//   char *str = "171894490616466197776";
//   char *re_str;
//   unsigned long squareroot;
//   int len = strlen(str), i = 0;
//   unsigned long array[1024] = {0};
//   for (i = stoi(str, &array[0]) - 1; i >= 0; i--)
//     printf("%lu ", array[i]);
//   printf("\0");
//   return (0);
// }
