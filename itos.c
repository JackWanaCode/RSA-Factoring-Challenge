#include "rsa_factoring.h"

// unsigned long max = 100;


char *itos(unsigned long *array, int len)
{
  char *str;
  int i, j, count = 1, check = 0;
  unsigned long temp_max = max, temp;

  if (array[0] == 0 && len == 1)
  {
    return ("0");
  }
  while (temp_max > 1)
  {
    count++;
    temp_max /= 10;
  }

  str = malloc(sizeof(char) * (len * count + 1));
  for (i = len - 1, j = 0; i >= 0; i--)
  {
    for (temp = array[i], temp_max = max / 10; temp_max > 0; )
    {
      if (temp == max)
        temp_max *= 10;
      // printf("in function %lu, %i\n", array[i], i);
      if (check == 0 && temp >= temp_max)
      /* to NOT print 0 for the first number */
      {
        check = 1;
      }
      // printf("in function %lu, %lu\n", temp, temp_max);
      if (check == 1)
      {
        str[j++] = (temp / temp_max) + '0';
        temp = temp % temp_max;
      }
      temp_max /= 10;
    }
  }
  str[j] = '\0';
  // printf("in function %s, %i\n", str, j);
  return (str);
}



// int main()
// {
//   unsigned long array[3] = {0, 00, 1};
//   int len = 3;
//   char *re_str;
//   re_str = itos(&array[0], len);
//   printf("%s\n", re_str);
//   return (0);
// }
