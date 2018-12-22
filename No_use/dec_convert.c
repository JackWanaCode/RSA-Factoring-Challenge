#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void str_div_dec(char *str, char *result, char *remain)
{
  int temp = 0, j = 0, dec_num = 0, k = 0;
  int mem = 0, i = 0, check = 0;
  char re_str[1024];

  /* format binary_str as set of 4 digit */
  for (i = 0; str[i] != 0; i++)
    ;
  for (k = 0; k < 4 - i % 4; k++)
    re_str[k] = '0';
  for (i = 0; str[i] != 0; i++, k++)
    re_str[k] = str[i];
  re_str[k] = '\0';

  /* copy temp to result */
  for (i = 0, j = 0; re_str[i] != '\0'; i += 4)
  {
    if (re_str[i] == '0' && check == 0)
      continue;
    else
    {
      // printf("mem is %i, str[%i] is %c\n", mem, i, str[i]);
      dec_num = (re_str[i] - '0') * 8 + (re_str[i + 1] - '0') * 4 + (re_str[i + 2] - '0') * 2 + (re_str[i] - '0')
      temp = dec_num / "1010";
      mem = dec_num % 10;
      result[j] = temp + '0';
      check = 1;
      j++;
    }
  }
  result[j] = '\0';
  *remain = mem + '0';
  // printf("result is %s, remain is %c\n", result, *remain);
}

char *dec_convert(char *str)
{
  char re_str = strdup(str);
  char *buffer;
  char result[1024];
  char remain = '0', temp;
  int i = 0, k = 0;
  int j = 0;

  buffer = malloc(sizeof(char) * 1024);


  // printf("%i\n", i);

  printf("%s\n", re_str);
  while (1)
  {
    str_div_dec(re_str, &result[0], &remain);
    // printf("result is %s, remain is %c, j is %i\n", result, remain, j);
    buffer[j] = remain;
    // printf("buffer[%i] is %c\n", j, buffer[j]);
    if (result[0] == '0' && result[1] == '\0')
    {
      // j++;
      // printf("j is here %i\n", j);
      buffer[++j] = '\0';
      break;
    }
    for (i = 0; result[i] != '\0'; i++)
    {
      re_str[i] = result[i];
    }
     re_str[i] = '\0';
    j++;
  }
  // j--;
  for (i = 0, --j; i < j; i++, j--)
  {
    // printf("i is %i, j is %i\n", i, j);
    temp = buffer[i];
    buffer[i] = buffer[j];
    buffer[j] = temp;
  }
  printf("buffer is %s\n", buffer);
  return (buffer);
}
