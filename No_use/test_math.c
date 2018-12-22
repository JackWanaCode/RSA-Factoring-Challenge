#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *binary_convert(char *str);
char *dec_convert(char *str);

int main()
{
  char *str = "1718944";
  char *re_str1;
  char *re_str2;

  re_str1 = binary_convert(str);
  printf("%s\n", re_str1);
  re_str2 = dec_convert(re_str1);
  printf("%s\n", re_str2);
  return (0);
}
