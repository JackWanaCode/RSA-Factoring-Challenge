#include "rsa_factoring.h"

// unsigned long max = 100000000;


// int div_by_n(unsigned long *arr, int len_num, int n)
// {
//   int i = len_num - 1, j = 0, k = 0;
//   unsigned long mem = 0, temp = 0;
//
//   if (arr[i] < n && i != 0)
//   {
//     len_num = i;
//   }
//   for (; i >= 0; i--)
//   {
//     temp = arr[i];
//     arr[i] = (mem * max + temp) / n;
//     mem = (mem * max + temp) % n;
//   }
//   return (len_num);
// }

int _div(unsigned long *ret_num, unsigned long *arr1, int l1,  unsigned long *arr2, int l2)
{
  int i, j, k, len_temp1, len_temp2 = 0, count = 0, check;
  unsigned long n;
  unsigned long temp1[1024] = {0};
  unsigned long temp2[1024] = {0};

  if (l1 < l2 || cmp(&arr1[0], l1, &arr2[0], l2) < 0)
  {
    return (1);
  }
  else if (cmp(&arr1[0], l1, &arr2[0], l2) == 0)
  {
    ret_num[0] = 1;
    return (1);
  }
  else
  {
    while (1)
    {
      /* make a temp to divide number */
      i = l1 > l2 ? l2 - 1 : l1 - 1;
      for (j = l1 - 1; i >= 0; i--, j--)
      {
        temp1[i] = arr1[j];
      }
      /* divide temp by arr2 */
      // printf("before divide n, temp1[%i] is %lu, arr2[%i] is %lu\n", l2 - 1, temp1[l2 - 1], l2 - 1, arr2[l2 - 1]);
      n = temp1[l2 - 1] / arr2[l2 - 1];
      len_temp1 = l2;
      // printf("1st in a loop, arr2, temp1 is \n");
      // for (i = 0; i < l2; i++)
      // {
      //   printf("arr2[%i] is %lu ", i, arr2[i]);
      // }
      // for (i = 0; i < len_temp1 + 1; i++)
      // {
      //   printf("temp1[%i] is %lu ", i, temp1[i]);
      // }
      // printf("\nn is %lu. %i, %i. before new line \n", n, l1, l2);
      // printf("CHECKHEHERHER %lu, %lu\n", temp1[l2 - 1], arr2[l2 -1]);
      // printf("cmpair is %i\n", cmp(&arr1[0], l1, &arr2[0], l2));
      for (k = l2; n == 0; k++)
      {
        if (l1 < l2 || (l1 == l2 && cmp(&arr1[0], l1, &arr2[0], l2) <= 0))
        {
          // for (i = 0, j = count - 1; i < j; i++, j--)
          // {
          //   n = ret_num[i];
          //   ret_num[i] = ret_num[j];
          //   ret_num[j] = n;
          // }
          // return (count);
          break;
        }
        // printf("check for 7, count is %i\n", count);
        // if (count > 0)
        // {
        //   printf("check herer\n");
        //   ret_num[count++] = n;
        // }
        for (k = l2, i = l1 - 1; k >= 0; k--, i--)
        {
          temp1[k] = arr1[i];
        }
        ret_num[count++] = 0;
        len_temp1 = l2 + 1;
        n = (temp1[l2] * max + temp1[l2 - 1]) / arr2[l2 - 1];
        // printf("2ne in a loop, temp1 is \n");
        // for (i = 0; i < len_temp1; i++)
        // {
        //   printf("%lu ", temp1[i]);
        // }
        // printf("n is %lu. before new line \n", n);
      }
      len_temp2 = mul_by_n(&temp2[0], &arr2[0], l2, n);
      // printf("3rd in a loop, temp2 is \n");
      // for (i = 0; i < len_temp2; i++)
      // {
      //   printf("%lu ", temp2[i]);
      // }
      // printf("before new line \n");
      check = cmp(&temp2[0], len_temp2, &temp1[0], len_temp1);
      while (check > 0)
      {
        // printf("begining loop, check is %i\n", check);
        n--;
        for (i = 0; i < len_temp2; i++)
          temp2[i] = 0;
        len_temp2 = mul_by_n(&temp2[0], &arr2[0], l2, n);
        // printf("4rd in a loop, temp2 is \n");
        // for (i = 0; i < len_temp2; i++)
        // {
        //   printf("%lu ", temp2[i]);
        // }
        // printf("n is %lu, before new line \n", n);
        // check = -1;
        check = cmp(&temp2[0], len_temp2, &temp1[0], len_temp1);
        // printf("end of loop, check is %i\n", check);
      }
      // printf("CHECKE HERER1, n is %lu, count is %i\n", n, count);
      ret_num[count++] = n;
      // printf("ret_num is %lu, count is %i\n", ret_num[count - 1], count - 1);
      // printf("CHECKE HERER2, %lu\n", ret_num[count - 1]);
      for (i = 0; i < len_temp1; i++)
      {
        temp1[i] = 0;
      }
      for (i = l1 - 1, j = len_temp2 - 1; i >= 0; i--, j--)
      {
        if (j < 0)
          temp2[i] = 0;
        else
          temp2[i] = temp2[j];
      }
      len_temp2 = l1;
      len_temp1 = sub(&temp1[0], &arr1[0], l1, &temp2[0], len_temp2);
      if (len_temp1 == 0 || cmp(&temp1[0], len_temp1, &arr2[0], l2) < 0)
        break;
      // printf("before, l1 is %i, len_temp1 is %i, flag is %i\n", l1, len_temp1, flag);
      // for (i = 1 + flag; i < l1 - len_temp1; i++)
      // {
      //   flag = 0;
      //   ret_num[count++] = 0;
      //   printf("ret_num is %lu, count is %i\n", ret_num[count - 1], count - 1);
      // }
      // printf("5rd in a loop, len_temp1 is \n", len_temp1);
      // for (i = 0; i < len_temp1; i++)
      // {
      //   printf("%lu ", temp1[i]);
      // }
      // printf("before new line \n");
      for (i = 0; i < len_temp1; i++)
        arr1[i] =  temp1[i];
      for (;i < l1; i++)
        arr1[i] = 0;
      l1 = len_temp1;
      for (i = 0; i < len_temp1; i++)
      {
        temp1[i] = 0;
      }
      // printf("at the end, l1 is %i, len_temp1 is %i, l2 is %i\n", l1, len_temp1, l2);
    }
  }
  for (i = 0, j = count - 1; i < j; i++, j--)
  {
    n = ret_num[i];
    ret_num[i] = ret_num[j];
    ret_num[j] = n;
  }
  return (count);
}


// int main()
// {
//   printf("-----1---str_a-123456-str_b-3456-result-35\n");
//   char *str_a_1 = "123456";
//   char *str_b_1 = "3456";
//   char *re_str1;
//   unsigned long arr_a_1[1024] = {0};
//   unsigned long arr_b_1[1024] = {0};
//   unsigned long ret_num_1[1024] = {0};
//   int arr_len_a, arr_len_b, ret_len, i;
//   arr_len_a = stoi(str_a_1, &arr_a_1[0]);
//   arr_len_b = stoi(str_b_1, &arr_b_1[0]);
//   ret_len = _div(&ret_num_1[0], &arr_a_1[0], arr_len_a, &arr_b_1[0], arr_len_b);
//   re_str1 = itos(&ret_num_1[0], ret_len);
//   printf("%s / %s = %s\n", str_a_1, str_b_1, re_str1);
//   printf("Check with 35, STRCMP is %i\n", strcmp("35", re_str1));
//   printf("%lu\n", arr_a_1[0]);
//   printf("-----2---str_a-12345678-str_b-3456-result-3572\n");
//   char *str_a_2 = "12345678";
//   char *str_b_2 = "3456";
//   char *re_str2;
//   unsigned long arr_a_2[1024] = {0};
//   unsigned long arr_b_2[1024] = {0};
//   unsigned long ret_num_2[1024] = {0};
//   arr_len_a = stoi(str_a_2, &arr_a_2[0]);
//   arr_len_b = stoi(str_b_2, &arr_b_2[0]);
//   ret_len = _div(&ret_num_2[0], &arr_a_2[0], arr_len_a, &arr_b_2[0], arr_len_b);
//   re_str2 = itos(&ret_num_2[0], ret_len);
//   printf("%s / %s = %s\n", str_a_2, str_b_2, re_str2);
//   printf("Check with 3572, STRCMP is %i\n", strcmp("3572", re_str2));
//   printf("%lu\n", arr_a_2[0]);
//   printf("-----3---str_a-1234567891-str_b-3456-result-357224\n");
//   char *str_a_3 = "1234567891";
//   char *str_b_3 = "3456";
//   char *re_str3;
//   unsigned long arr_a_3[1024] = {0};
//   unsigned long arr_b_3[1024] = {0};
//   unsigned long ret_num_3[1024] = {0};
//   arr_len_a = stoi(str_a_3, &arr_a_3[0]);
//   arr_len_b = stoi(str_b_3, &arr_b_3[0]);
//   ret_len = _div(&ret_num_3[0], &arr_a_3[0], arr_len_a, &arr_b_3[0], arr_len_b);
//   re_str3 = itos(&ret_num_3[0], ret_len);
//   printf("%s / %s = %s\n", str_a_3, str_b_3, re_str3);
//   printf("Check with 357224, STRCMP is %i\n", strcmp("357224", re_str3));
//   printf("%lu\n", arr_a_3[0]);
//   printf("-----4---str_a-1-str_b-3456-result-0\n");
//   char *str_a_4 = "1";
//   char *str_b_4 = "3456";
//   char *re_str4;
//   unsigned long arr_a_4[1024] = {0};
//   unsigned long arr_b_4[1024] = {0};
//   unsigned long ret_num_4[1024] = {0};
//   arr_len_a = stoi(str_a_4, &arr_a_4[0]);
//   arr_len_b = stoi(str_b_4, &arr_b_4[0]);
//   ret_len = _div(&ret_num_4[0], &arr_a_4[0], arr_len_a, &arr_b_4[0], arr_len_b);
//   re_str4 = itos(&ret_num_4[0], ret_len);
//   printf("%s / %s = %s\n", str_a_4, str_b_4, re_str4);
//   printf("Check with 0, STRCMP is %i\n", strcmp("0", re_str4));
//   printf("%lu\n", arr_a_4[0]);
//   printf("-----5---str_a-0-str_b-3456-result-0\n");
//   char *str_a_5 = "0";
//   char *str_b_5 = "3456";
//   char *re_str5;
//   unsigned long arr_a_5[1024] = {0};
//   unsigned long arr_b_5[1024] = {0};
//   unsigned long ret_num_5[1024] = {0};
//   arr_len_a = stoi(str_a_5, &arr_a_5[0]);
//   arr_len_b = stoi(str_b_5, &arr_b_5[0]);
//   ret_len = _div(&ret_num_5[0], &arr_a_5[0], arr_len_a, &arr_b_5[0], arr_len_b);
//   re_str5 = itos(&ret_num_5[0], ret_len);
//   printf("%s / %s = %s\n", str_a_5, str_b_5, re_str5);
//   printf("Check with 0, STRCMP is %i\n", strcmp("0", re_str5));
//   printf("%lu\n", arr_a_5[0]);
//   printf("-----6---str_a-123-str_b-123-result-1\n");
//   char *str_a_6 = "123";
//   char *str_b_6 = "123";
//   char *re_str6;
//   unsigned long arr_a_6[1024] = {0};
//   unsigned long arr_b_6[1024] = {0};
//   unsigned long ret_num_6[1024] = {0};
//   arr_len_a = stoi(str_a_6, &arr_a_6[0]);
//   arr_len_b = stoi(str_b_6, &arr_b_6[0]);
//   ret_len = _div(&ret_num_6[0], &arr_a_6[0], arr_len_a, &arr_b_6[0], arr_len_b);
//   re_str6 = itos(&ret_num_6[0], ret_len);
//   printf("%s / %s = %s\n", str_a_6, str_b_6, re_str6);
//   printf("Check with 1, STRCMP is %i\n", strcmp("1", re_str6));
//   printf("%lu\n", arr_a_6[0]);
//   printf("-----7---str_a-98765432123456,78912345-str_b-12345678934562-result-800000005\n");
//   char *str_a_7 = "9876543212345678912345";
//   char *str_b_7 = "12345678934562";
//   char *re_str7;
//   unsigned long arr_a_7[1024] = {0};
//   unsigned long arr_b_7[1024] = {0};
//   unsigned long ret_num_7[1024] = {0};
//   arr_len_a = stoi(str_a_7, &arr_a_7[0]);
//   arr_len_b = stoi(str_b_7, &arr_b_7[0]);
//   ret_len = _div(&ret_num_7[0], &arr_a_7[0], arr_len_a, &arr_b_7[0], arr_len_b);
//   re_str7 = itos(&ret_num_7[0], ret_len);
//   printf("%s / %s = %s, ret_len is %i\n", str_a_7, str_b_7, re_str7, ret_len);
//   printf("Check with 1, STRCMP is %i\n", strcmp("800000005", re_str7));
//   printf("%lu\n", arr_a_7[0]);
//   printf("-----8---str_a-1 000 110 021 100 210 002-str_b-100 010 002-result-10000100001\n");
//   char *str_a_8 = "1000110021100210002";
//   char *str_b_8 = "100010002";
//   char *re_str8;
//   unsigned long arr_a_8[1024] = {0};
//   unsigned long arr_b_8[1024] = {0};
//   unsigned long ret_num_8[1024] = {0};
//   arr_len_a = stoi(str_a_8, &arr_a_8[0]);
//   arr_len_b = stoi(str_b_8, &arr_b_8[0]);
//   ret_len = _div(&ret_num_8[0], &arr_a_8[0], arr_len_a, &arr_b_8[0], arr_len_b);
//   re_str8 = itos(&ret_num_8[0], ret_len);
//   printf("%s / %s = %s, ret_len is %i\n", str_a_8, str_b_8, re_str8, ret_len);
//   printf("Check with 1, STRCMP is %i\n", strcmp("10000100001", re_str8));
//   printf("%lu\n", arr_a_8[0]);
//   printf("-----9---str_a-72040361660505508500021-str_b-900500007-result-80000401000003\n");
//   char *str_a_9 = "72040361660505508500021";
//   char *str_b_9 = "900500007";
//   char *re_str9;
//   unsigned long arr_a_9[1024] = {0};
//   unsigned long arr_b_9[1024] = {0};
//   unsigned long ret_num_9[1024] = {0};
//   arr_len_a = stoi(str_a_9, &arr_a_9[0]);
//   arr_len_b = stoi(str_b_9, &arr_b_9[0]);
//   ret_len = _div(&ret_num_9[0], &arr_a_9[0], arr_len_a, &arr_b_9[0], arr_len_b);
//   re_str9 = itos(&ret_num_9[0], ret_len);
//   printf("%s / %s = %s, ret_len is %i\n", str_a_9, str_b_9, re_str9, ret_len);
//   printf("Check with 1, STRCMP is %i\n", strcmp("80000401000003", re_str9));
//   printf("%lu\n", arr_a_9[0]);
//   printf("-----10---str_a-454504500450004500004500004500000045-str_b-45-result-10100100010000100000100000100000001\n");
//   char *str_a_10 = "454504500450004500004500004500000045";
//   char *str_b_10 = "45";
//   char *re_str10;
//   unsigned long arr_a_10[1024] = {0};
//   unsigned long arr_b_10[1024] = {0};
//   unsigned long ret_num_10[1024] = {0};
//   arr_len_a = stoi(str_a_10, &arr_a_10[0]);
//   arr_len_b = stoi(str_b_10, &arr_b_10[0]);
//   ret_len = _div(&ret_num_10[0], &arr_a_10[0], arr_len_a, &arr_b_10[0], arr_len_b);
//   re_str10 = itos(&ret_num_10[0], ret_len);
//   printf("%s / %s = %s, ret_len is %i\n", str_a_10, str_b_10, re_str10, ret_len);
//   printf("Check with 1, STRCMP is %i\n", strcmp("10100100010000100000100000100000001", re_str10));
//   printf("%lu\n", arr_a_10[0]);
//   return (0);
// }
