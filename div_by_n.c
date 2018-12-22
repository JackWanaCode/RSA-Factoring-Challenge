#include "rsa_factoring.h"

// unsigned long max = 1000000000;

int div_by_n(unsigned long *arr, int len_num, int n)
{
  int i = len_num - 1, j = 0, k = 0;
  unsigned long mem = 0, temp = 0;

  if (arr[i] < n && i != 0)
  {
    len_num = i;
  }
  for (; i >= 0; i--)
  {
    temp = arr[i];
    arr[i] = (mem * max + temp) / n;
    mem = (mem * max + temp) % n;
  }
  return (len_num);
}

// int main()
// {
//   printf("-----1---str_a-123456-num-2\n");
//   char *str_1 = "123456";
//   char *re_str1;
//   unsigned long arr_1[1024] = {0};
//   int arr_len, ret_len, i;
//   arr_len = stoi(str_1, &arr_1[0]);
//   ret_len = div_by_n(&arr_1[0], arr_len, 2);
//   re_str1 = itos(&arr_1[0], ret_len);
//   printf("%i, %s, %s\n", strcmp("61728", re_str1), "61728", re_str1);
//   printf("-----2---str_a-123456-num-7\n");
//   char *str_2 = "123456";
//   char *re_str2;
//   unsigned long arr_2[1024] = {0};
//   arr_len = stoi(str_2, &arr_2[0]);
//   ret_len = div_by_n(&arr_2[0], arr_len, 7);
//   re_str2 = itos(&arr_2[0], ret_len);
//   printf("%i, %s, %s\n", strcmp("17636", re_str2), "17636", re_str2);
//   printf("-----3---str_a-123456-num-9\n");
//   char *str_3 = "123456";
//   char *re_str3;
//   unsigned long arr_3[1024] = {0};
//   arr_len = stoi(str_3, &arr_3[0]);
//   ret_len = div_by_n(&arr_3[0], arr_len, 9);
//   re_str3 = itos(&arr_3[0], ret_len);
//   printf("%i, %s, %s\n", strcmp("13717", re_str3), "13717", re_str3);
//   printf("-----4---str_a-123456-num-99\n");
//   char *str_4 = "123456";
//   char *re_str4;
//   unsigned long arr_4[1024] = {0};
//   arr_len = stoi(str_4, &arr_4[0]);
//   ret_len = div_by_n(&arr_4[0], arr_len, 99);
//   re_str4 = itos(&arr_4[0], ret_len);
//   printf("%i, %s, %s\n", strcmp("1247", re_str4), "1247", re_str4);
//   printf("-----5---str_a-123456-num-1\n");
//   char *str_5 = "123456";
//   char *re_str5;
//   unsigned long arr_5[1024] = {0};
//   arr_len = stoi(str_5, &arr_5[0]);
//   ret_len = div_by_n(&arr_5[0], arr_len, 1);
//   re_str5 = itos(&arr_5[0], ret_len);
//   printf("%i, %s, %s\n", strcmp("123456", re_str5), "123456", re_str5);
//   printf("-----6---str_a-123456-num-123456\n");
//   char *str_6 = "123456";
//   char *re_str6;
//   unsigned long arr_6[1024] = {0};
//   arr_len = stoi(str_6, &arr_6[0]);
//   ret_len = div_by_n(&arr_6[0], arr_len, 123456);
//   re_str6 = itos(&arr_6[0], ret_len);
//   printf("%i, %s, %s\n", strcmp("1", re_str6), "1", re_str6);
//   printf("-----7---str_a-1-num-2\n");
//   char *str_7 = "1";
//   char *re_str7;
//   unsigned long arr_7[1024] = {0};
//   arr_len = stoi(str_7, &arr_7[0]);
//   ret_len = div_by_n(&arr_7[0], arr_len, 2);
//   re_str7 = itos(&arr_7[0], ret_len);
//   printf("%i, %s, %s\n", strcmp("0", re_str7), "0", re_str7);
//   printf("-----8---str_a-1-num-3\n");
//   char *str_8 = "1";
//   char *re_str8;
//   unsigned long arr_8[1024] = {0};
//   arr_len = stoi(str_8, &arr_8[0]);
//   ret_len = div_by_n(&arr_8[0], arr_len, 3);
//   re_str8 = itos(&arr_8[0], ret_len);
//   printf("%i, %s, %s\n", strcmp("0", re_str8), "0", re_str8);
//   return (0);
// }
