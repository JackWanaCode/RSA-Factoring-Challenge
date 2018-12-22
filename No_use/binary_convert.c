#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void str_div(char *str, char *result, char *remain)
{
  int temp = 0, j = 0;
  int mem = 0, i = 0, check = 0;

  for (i = 0, j = 0; str[i] != '\0'; i++)
  {
    if (str[i] == '0' && check == 0)
      continue;
    else
    {
      // printf("mem is %i, str[%i] is %c\n", mem, i, str[i]);
      temp = ((mem * 10) + (str[i] - '0')) / 2;
      mem = ((mem * 10) + (str[i] - '0')) % 2;
      result[j] = temp + '0';
      check = 1;
      j++;
    }
  }
  result[j] = '\0';
  *remain = mem + '0';
  // printf("result is %s, remain is %c\n", result, *remain);
}

char *binary_convert(char *str)
{
  char *re_str = strdup(str);
  char *buffer;
  char result[1024];
  char remain = '0', temp;
  unsigned i = 0;
  unsigned j = 0;

  buffer = malloc(sizeof(char) * 1024);
  printf("%s\n", re_str);
  while (1)
  {
    str_div(re_str, &result[0], &remain);
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
  // printf("buffer is %s\n", buffer);
  return (buffer);
}
