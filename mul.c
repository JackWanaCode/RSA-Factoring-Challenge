#include "rsa_factoring.h"

// unsigned long max = 100;

int mul_by_n(unsigned long *ret_num, unsigned long * arr, int len, unsigned long num)
{
  int i;
  unsigned long mem = 0;

  for (i = 0; i < len; i++)
  {
    ret_num[i] = mem + arr[i] * num;
    if (ret_num[i] >= max)
    {
      mem = ret_num[i] / max;
      ret_num[i] = ret_num[i] % max;
    }
    else
      mem = 0;
  }
  if (mem != 0)
  {
    ret_num[i] = mem;
    return (i + 1);
  }
  return (i);
}


int mul(unsigned long *ret_num, unsigned long *arr1, int l1,  unsigned long *arr2, int l2)
{
  int i1 = 0, i2 = 0, k = 0;
  unsigned long mem = 0;

  for (i2 = 0; i2 < l1; i2++)
  {
    mem = 0;
    for (i1 = 0, k = i2; i1 < l2; i1++, k++)
    {
      ret_num[k] = mem + ret_num[k] + (arr1[i1] * arr2[i2]);
      if (ret_num[k] >= max)
      {
        mem = ret_num[k] / max;
        ret_num[k] = ret_num[k] % max;
      }
      else
        mem = 0;
    }
    ret_num[k] = mem;
  }
  if (mem != 0)
    return (k + 1);
  return (k);
}

// int main()
// {
//   // 1 31 10 85 39 24
//   unsigned long ret_num[1024] = {0};
//   unsigned long arr1[1024] = {0};
//   unsigned long arr2[1024] = {0};
//   int i = 0, l1, l2, ret_len;
//
//   arr1[0] = 24;
//   arr1[1] = 39;
//   arr1[2] = 85;
//   arr1[3] = 10;
//   arr1[4] = 31;
//   arr1[5] = 1;
//   l1 = 6;
//   arr2[0] = 24;
//   arr2[1] = 39;
//   arr2[2] = 85;
//   arr2[3] = 10;
//   arr2[4] = 31;
//   arr2[5] = 1;
//   l2 = 6;
//   ret_len = mul(&ret_num[0], &arr1[0], l1, &arr2[0], l2);
//   for (i = 0; i < ret_len; i++)
//     printf("%lu ",ret_num[i]);
//   return (0);
// }
