#include "rsa_factoring.h"

unsigned long max = 100000000;
// int check_prime(unsigned long *num, int len, unsigned long *temp, int temp_len);
// int prime_ret(unsigned long *arr_num, int arr_len, unsigned long *ret_num);

// int check_prime(unsigned long *num, int len, unsigned long *temp, int temp_len)
// {
//   unsigned long root_num[1024] = {0};
//   unsigned long mod_num[1024] = {0};
//   unsigned long one[1024] = {0};
//   int root_len = 0, mod_len = 0, one_len, i;
//   // printf("%lu\n", n);
//   root(&num[0], len, &root_num[0], &root_len);
//
//   if (len == 1 && (num[0] == 2 || num[0] == 3))
//     return (1);
//   one[0] = 1;
//   one_len = 1;
//   while (i > 3)
//   {
//     if (root_len == 1 && root_num[0] <= 3)
//       break;
//     mod_len = _mod(&mod_num[0], &num[0], len, &root_num[0], root_len);
//     if (mod_len == 1 && mod_num[0] == 0)
//     {
//       for (i = 0; i < root_len; i++)
//         temp[i] = root_num[i];
//       for (; i < temp_len; i++)
//         temp[i] = 0;
//       temp_len = root_len;
//       return (0);
//     }
//     temp_len = sub(&temp[0], &root_num[0], root_len, &one[0], one_len);
//     for (i = 0; i < temp_len; i++)
//       root_num[i] = temp[i];
//     for (; i < root_len; i++)
//       root_num[i] = 0;
//     for (i = 0; i < temp_len; i++)
//       temp[i] = 0;
//   }
//   return (1);
// }

int prime_ret(char *str_num, unsigned long *ret_num)
{
  unsigned long arr_num[1024] = {0};
  unsigned long temp[1024] = {0};
  unsigned long create[1024] = {0};
  unsigned long root_num[1024] = {0};
  unsigned long mod_num[1024] = {0};
  unsigned long prime_num[1024] = {0};
  hash_table_t *ht;
  char *temp_str;
  int root_len = 0, mod_len, arr_len = 0, temp_len = 1, check_loop = 1;
  int prime_len = 1, check_3 = 0, cre_len = 1, i;
  // int count1 = 0, count2 = 0;


  // printf("n is %lu, root is %lu\n", n, num);
  arr_len = stoi(str_num, &arr_num[0]);
  root(&arr_num[0], arr_len, &root_num[0], &root_len);
  // one[0] = 1;
  // while(1)
  // {
  //   mod_len = _mod(&mod_num[0], &arr_num[0], arr_len, &root_num[0], root_len);
  //   if (mod_len == 1 && mod_num[0] == 0) //n % num == 0
  //   {
  //     if (check_prime(&root_num[0], root_len, &temp[0], temp_len)) // check num is prime or not
  //     {
  //       for (i = 0; i < root_len; i++)
  //         ret_num[i] = root_num[i];
  //       return (root_len);
  //     }
  //     for (i = 0; i < temp_len; i++)
  //       root_num[i] = temp[i];
  //     for (; i < root_len; i++)
  //       root_num[i] = 0;
  //   }
  //   else
  //   {
  //     temp_len = sub(&temp[0], &root_num[0], root_len, &one[0], one_len);
  //     for (i = 0; i < temp_len; i++)
  //       root_num[i] = temp[i];
  //     for (; i < root_len; i++)
  //       root_num[i] = 0;
  //     for (i = 0; i < temp_len; i++)
  //       temp[i] = 0;
  //   }
  // }
  for (i = 0; str_num[i] != '\0'; i++)
    check_3 += str_num[i] - '0';
  prime_num[0] = 2;
  prime_len = 1;
  if (arr_num[0] % 2 == 0)
  {
    ret_num[0] = 2;
    return (1);
  }
  else if (check_3 % 3 == 0)
  {
    ret_num[0] = 3;
    return (1);
  }
  else if (str_num[strlen(str_num) - 1] == '5')
  {
    ret_num[0] = 5;
    return (1);
  }
  else
  {
    prime_num[0] = 3;
    prime_len = 1;
    create[0] = 3;
    ht = hash_table_create(1024);
    while (cmp(&prime_num[0], prime_len, &root_num[0], root_len) <= 0)
    {
      /* update the non-prime in hast table, value will be until root num */
      // printf("in begining. root num is %lu\n", root_num[0]);
      for (i = 0; i < temp_len; i++)
        temp[i] = 0;
      for (create[0] = 3, cre_len = 1; check_loop;)
      {
        // printf("in create %lu, prime num is %lu \n", create[0], prime_num[0]);
        for (i = 0; i < temp_len; i++)
          temp[i] = 0;
        temp_len = mul(&temp[0], &prime_num[0], prime_len, &create[0], cre_len);
        if (cmp(&temp[0], temp_len, &root_num[0], root_len) >= 0)
          check_loop = 0;
        temp_str = itos(&temp[0], temp_len);
        hash_table_set(ht, temp_str, temp_str);
        cre_len = add_by_n(&create[0], cre_len, 2);
      }
      hash_table_print(ht);
      // printf("after update. prime num is %lu\n", prime_num[0]);
      /* next prime number which is the next one and not in the hash table*/
      prime_len = add_by_n(&prime_num[0], prime_len, 2);
      temp_str = itos(&temp[0], temp_len);
      // printf("after added by 2. prime num is %lu\n", prime_num[0]);
      while (hash_table_check(ht, temp_str) == 0)
      {
        // printf("prime num is %lu\n", prime_num[0]);
        prime_len = add_by_n(&prime_num[0], prime_len, 2);
        temp_str = itos(&prime_num[0], prime_len);
        // if (cmp(&prime_num[0], prime_len, &root_num[0], root_len) > 0)
        //   return (1);
      }
      // printf("after check prime. prime num is %lu\n", prime_num[0]);
      /* calculate result of mod of number and prime */
      mod_len = _mod(&mod_num[0], &arr_num[0], arr_len, &prime_num[0], prime_len);
      if (mod_len == 1 && mod_num[0] == 0)
      {
        for (i = 0; i < prime_len; i++)
          ret_num[i] = prime_num[i];
        return (prime_len);
      }
      else
      {
        for (i = 0; i < mod_len; i++)
          mod_num[i] = 0;
      }
    }
  }
  return (1);
}


int main()
{
  char *str_num = "44756099";
  char *ret_str_num;
  unsigned long ret_num[1024] = {0};
  int ret_len;

  // num_len = stoi(str_num, &arr_num[0]);
  ret_len = prime_ret(str_num, &ret_num[0]);
  ret_str_num = itos(&ret_num[0], ret_len);
  printf("%s\n", ret_str_num);


  return (0);
}
