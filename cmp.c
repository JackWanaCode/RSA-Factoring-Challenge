#include "rsa_factoring.h"

// unsigned long max = 100;

int cmp(unsigned long *arr1, int l1, unsigned long *arr2, int l2)
{
  int j;

  j = l1 < l2 ? l2 - 1 : l1 - 1;
  for (; j >= 0; j--)
  {
    // printf("in CMP arr1 %lu,  arr2 %lu\n", arr1[j], arr2[j]);
    if (arr1[j] > arr2[j])
      return (1);
    else if (arr1[j] < arr2[j])
      return (-1);
  }
  return (0);
}

// int main()
// {
//   unsigned long arr1[1024] = {0};
//   unsigned long arr2[1024] = {0};
//   int i = 0, l1, l2, ret;
//
//   arr1[0] = 96;
//   arr1[1] = 24;
//   arr1[2] = 0;
//   l1 = 2;
//   arr2[0] = 56;
//   arr2[1] = 34;
//   arr2[2] = 0;
//   l2 = 2;
//   ret = cmp(&arr1[0], l1, &arr2[0], l2);
//   printf("%i\n", ret);
//   return (0);
// }
