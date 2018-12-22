#include "rsa_factoring.h"

// unsigned long max = 100;

int add(unsigned long *trial, unsigned long *root, int lr, unsigned long *bit, int lb)
{
  int i = 0;
  unsigned long nr, nb;
  unsigned long mem = 0;
  for (; i < lr || i < lb; i++)
  {
    if (i >= lr)
      nr = 0;
    else
      nr = root[i];
    if (i >= lb)
      nb = 0;
    else
      nb = bit[i];
    trial[i] = mem + nr + nb;
    mem = 0;
    if (trial[i] >= max)
    {
      mem = trial[i] / max;
      trial[i] = trial[i] % max;
    }
  }
  if (mem > 0)
  {
    trial[i] = mem;
    return (i + 1);
  }
  return (i);
}

int add_by_n(unsigned long *arr, int arr_len, unsigned long num)
{
  int i = 0;
  unsigned long mem = 0;
  for (; i < arr_len; i++)
  {
    arr[i] = mem + arr[i] + num;
    num = 0;
    mem = 0;
    if (arr[i] >= max)
    {
      mem = arr[i] / max;
      arr[i] = arr[i] % max;
    }
  }
  if (mem > 0)
  {
    arr[i] = mem;
    return (i + 1);
  }
  return (i);
}

// int main()
// {
//   // unsigned long ret_add[1024] = {0};
//   unsigned long arr1[1024] = {0};
//   // unsigned long arr2[1024] = {0};
//   int i = 0, l1, l2, ret_len;
//
//   arr1[0] = 99;
//   arr1[1] =99;
//   arr1[2] = 0;
//   l1 = 2;
//   // arr2[0] = 999;
//   // arr2[1] = 0;
//   // arr2[2] = 0;
//   // l2 = 1;
//   // ret_len = add(&ret_add[0], &arr1[0], l1, &arr2[0], l2);
//   ret_len = add_by_n(&arr1[0], l1, 1);
//   for (i = 0; i < ret_len; i++)
//     printf("%lu ", arr1[i]);
//   return (0);
// }
