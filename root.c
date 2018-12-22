#include "rsa_factoring.h"

unsigned long max = 1000000000;

int div_by_2(unsigned long *arr, int len_num)
{
  /* for root only */
  int i = len_num;
  unsigned long mem = 0, temp = 0;

  if (arr[i - 1] < 2)
  {
    len_num = i - 1;
  }
  for (; i >= 0; i--)
  {
    temp = arr[i];
    arr[i] = (mem * max + temp) / 2;
    mem = (mem * max + temp) % 2;
    if (mem != 0)
      arr[i]++;
  }
  return (len_num);
}

void root(unsigned long *array, int arr_len, unsigned long *root, int *len_root)
{
  int i = 0, count = 0, len_bit = 0, len_trial = 0, len_ret = 0, temp = 0;
  unsigned long bit[1024] = {0};
  unsigned long trial[1024] = {0};
  unsigned long ret_num[1024] = {0};
  unsigned long zero[1024] = {0};

  for (i = 0; i < arr_len; i++)
  {
    bit[i] = array[i];
  }
  len_bit = arr_len;
  // for (bit = ULONG_MAX; bit > 0; bit >>= 1)
  // {
  //     trial = root + bit;
  //     if (trial * trial <= n)
  //     {
  //         root += bit;
  //     }
  // }
  // return root;
  while (cmp(&bit[0], len_bit, &zero[0], 1) > 0) //for (bit = array; bit > 0; bit >> 1)
  {
    for (i = 0; i < len_trial && i < 1024; i++)
    {
      trial[i] = 0;
    }
    len_trial = add(&trial[0], &root[0], *len_root, &bit[0], len_bit); //trial = root + bit:

    for (i = 0; i < len_ret && i < 1024; i++)
    {
      ret_num[i] = 0;
    }
    len_ret = mul(&ret_num[0], &trial[0], len_trial, &trial[0], len_trial); //ret_num = trial * trial
    if (cmp(&ret_num[0], len_ret, &array[0], arr_len) <= 0) //if trial * trial <= n
    {
      temp = add(&root[0], &root[0], *len_root, &bit[0], len_bit); //root += bit
      *len_root = temp;
      for (i = *len_root; root[i] != 0 && i < 1024; i++)
      {
        root[i] = 0;
      }
      temp = 0;
    }
    temp = div_by_2(&bit[0], len_bit); //bit >> 1
    // printf("root is %lu\n", root[0]);
    // printf("bit is %lu\n", bit[0]);
    len_bit = temp;
    for (i = len_bit; bit[i] != 0 && i < 1024; i++)
    {
      bit[i] = 0;
    }
    temp = 0;
    count++;
  }
}

int main ()
{
  char *str1 = "1009881397871923546909564894309468582818233821955573955141120516205831021338528545374366109757154363664913380084917065169921701524733294389270280234380960909804976440540711201965410747553824948672771374075011577182305398340606162079";
  char *re_str1;
  unsigned long squareroot1[1024] = {0};
  int arr_len = 0, root_len = 0, i = 0;
  unsigned long array1[1024] = {0};
  arr_len = stoi(str1, &array1[0]);
  root(&array1[0], arr_len, &squareroot1[0], &root_len);
  re_str1 = itos(&squareroot1[0], root_len);
  printf("-----1---str-171906614699083568656\n");
  printf("%i, %s, %s\n", strcmp("13111316284", re_str1), "13111316284", re_str1);
  // printf("-----2---str-13111316284\n");
  // char *str2 = "100";
  // char *re_str2;
  // unsigned long squareroot2[1024] = {0};
  // unsigned long array2[1024] = {0};
  // arr_len = stoi(str2, &array2[0]);
  // root(&array2[0], arr_len, &squareroot2[0], &root_len);
  // re_str2 = itos(&squareroot2[0], root_len);
  // printf("%i, %s, %s\n", strcmp("10", re_str2), "10", re_str2);
  // printf("-----3---str-10\n");
  // char *str3 = "9";
  // char *re_str3;
  // unsigned long squareroot3[1024] = {0};
  // unsigned long array3[1024] = {0};
  // arr_len = stoi(str3, &array3[0]);
  // root(&array3[0], arr_len, &squareroot3[0], &root_len);
  // re_str3 = itos(&squareroot3[0], root_len);
  // printf("%i, %s, %s\n", strcmp("3", re_str3), "3", re_str3);
  // printf("-----4---str-1524157877488187881\n");
  // char *str4 = "1524157877488187881";
  // char *re_str4;
  // unsigned long squareroot4[1024] = {0};
  // unsigned long array4[1024] = {0};
  // arr_len = stoi(str4, &array4[0]);
  // root(&array4[0], arr_len, &squareroot4[0], &root_len);
  // re_str4 = itos(&squareroot4[0], root_len);
  // printf("%i, %s, %s\n", strcmp("1234567891", re_str4), "1234567891", re_str4);
  // printf("-----5---str-1000200012000200001\n");
  // char *str5 = "1000200012000200001";
  // char *re_str5;
  // unsigned long squareroot5[1024] = {0};
  // unsigned long array5[1024] = {0};
  // arr_len = stoi(str5, &array5[0]);
  // root(&array5[0], arr_len, &squareroot5[0], &root_len);
  // re_str5 = itos(&squareroot5[0], root_len);
  // printf("%i, %s, %s\n", strcmp("1000100001", re_str5), "1000100001", re_str5);
  // printf("-----6---str-100010001\n");
  // char *str6 = "100010001";
  // char *re_str6;
  // unsigned long squareroot6[1024] = {0};
  // unsigned long array6[1024] = {0};
  // arr_len = stoi(str6, &array6[0]);
  // root(&array6[0], arr_len, &squareroot6[0], &root_len);
  // re_str6 = itos(&squareroot6[0], root_len);
  // printf("%i, %s, %s\n", strcmp("10000", re_str6), "10000", re_str6);
  // printf("-----7---str-10000001\n");
  // char *str7 = "10000001";
  // char *re_str7;
  // unsigned long squareroot7[1024] = {0};
  // unsigned long array7[1024] = {0};
  // arr_len = stoi(str7, &array7[0]);
  // root(&array7[0], arr_len, &squareroot7[0], &root_len);
  // re_str7 = itos(&squareroot7[0], root_len);
  // printf("%i, %s, %s\n", strcmp("3162", re_str7), "3162", re_str7);
  // printf("-----8---str-10101\n");
  // char *str8 = "10101";
  // char *re_str8;
  // unsigned long squareroot8[1024] = {0};
  // unsigned long array8[1024] = {0};
  // arr_len = stoi(str8, &array8[0]);
  // root(&array8[0], arr_len, &squareroot8[0], &root_len);
  // re_str8 = itos(&squareroot8[0], root_len);
  // printf("%i, %s, %s\n", strcmp("100", re_str8), "100", re_str8);
  // printf("-----9---str-3\n");
  // char *str9 = "3";
  // char *re_str9;
  // unsigned long squareroot9[1024] = {0};
  // unsigned long array9[1024] = {0};
  // arr_len = stoi(str9, &array9[0]);
  // root(&array9[0], arr_len, &squareroot9[0], &root_len);
  // re_str9 = itos(&squareroot9[0], root_len);
  // printf("%i, %s, %s\n", strcmp("1", re_str9), "1", re_str9);
  // printf("-----10---str-81\n");
  // char *str10 = "81";
  // char *re_str10;
  // unsigned long squareroot10[1024] = {0};
  // unsigned long array10[1024] = {0};
  // arr_len = stoi(str10, &array10[0]);
  // root(&array10[0], arr_len, &squareroot10[0], &root_len);
  // re_str10 = itos(&squareroot10[0], root_len);
  // printf("%i, %s, %s\n", strcmp("9", re_str10), "9", re_str10);
  // printf("-----11---str-1524095615320213852017618798289566414118355644681\n");
  // char *str11 = "1524095615320213852017618798289566414118355644681";
  // char *re_str11;
  // unsigned long squareroot11[1024] = {0};
  // unsigned long array11[1024] = {0};
  // arr_len = stoi(str11, &array11[0]);
  // root(&array11[0], arr_len, &squareroot11[0], &root_len);
  // re_str11 = itos(&squareroot11[0], root_len);
  // printf("%i, %s, %s\n", strcmp("1234542674564234677763459", re_str11), "1234542674564234677763459", re_str11);
  // printf("-----12---str-10000\n");
  // char *str12 = "10000";
  // char *re_str12;
  // unsigned long squareroot12[1024] = {0};
  // unsigned long array12[1024] = {0};
  // arr_len = stoi(str12, &array12[0]);
  // root(&array12[0], arr_len, &squareroot12[0], &root_len);
  // re_str12 = itos(&squareroot12[0], root_len);
  // printf("%i, %s, %s\n", strcmp("100", re_str12), "100", re_str12);
  // printf("-----13---str-10201\n");
  // char *str13 = "10101";
  // char *re_str13;
  // unsigned long squareroot13[1024] = {0};
  // unsigned long array13[1024] = {0};
  // arr_len = stoi(str13, &array13[0]);
  // root(&array13[0], arr_len, &squareroot13[0], &root_len);
  // re_str13 = itos(&squareroot13[0], root_len);
  // printf("%i, %s, %s\n", strcmp("100", re_str13), "100", re_str13);
  return (0);
}
