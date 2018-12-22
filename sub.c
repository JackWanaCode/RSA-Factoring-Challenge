#include "rsa_factoring.h"




int sub(unsigned long *ret_num, unsigned long *arr1, int l1, unsigned long *arr2, int l2)
{
  int i = 0, j = 0;
  unsigned long mem = 0;
  int check = cmp(&arr1[0], l1, &arr2[0], l2);
  if (check == 0)
    return (0);
  else if (check > 0)
  {
    for (i = 0, j = 0; i < l1; i++, j++)
    {
      if (arr1[i] >= arr2[i] + mem)
      {
        ret_num[j] = arr1[i] - arr2[i] - mem;
        mem = 0;
      }
      else
      {
        ret_num[j] = (arr1[i] + max) - arr2[i] - mem;
        mem = 1;
      }
    }
    while (ret_num[j] == 0)
    {
      j--;
    }
    return (++j);
  }
  else
  {
    for (i = 0, j = 0; i < l2; i++, j++)
    {
      if (arr2[i] >= arr1[i] + mem)
      {
        ret_num[j] = arr2[i] - arr1[i] - mem;
        mem = 0;
      }
      else
      {
        ret_num[j] = (arr2[i] + max) - arr1[i] - mem;
        mem = 1;
      }
    }
    while (ret_num[j] == 0)
      j--;
    return (-(++j));
  }
}

// int main()
// {
//   unsigned long ret_sub[1024] = {0};
//   unsigned long arr1[1024] = {0};
//   unsigned long arr2[1024] = {0};
//   int i = 0, l1, l2, ret_len;
//
//   arr1[0] = 99;
//   arr1[1] = 98;
//   arr1[2] = 0;
//   l1 = 2;
//   arr2[0] = 0;
//   arr2[1] = 0;
//   arr2[2] = 1;
//   l2 = 3;
//   ret_len = sub(&ret_sub[0], &arr1[0], l1, &arr2[0], l2);
//   printf("ret_len is %i\n", ret_len);
//   if (ret_len < 0)
//     ret_len = -ret_len;
//   for (i = 0; i < ret_len; i++)
//     printf("%lu ",ret_sub[i]);
//   return (0);
// }
