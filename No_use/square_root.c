#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

void add(char *trial, char *root, char *binary_str)
{
  int i = 0, j = 0;
  char mem;
  int len_root = strlen(root);
  int len_bin = strlen(binary_str);

  for (i )

  for (i = 0; binary_str[i] != '\0'; i++)
  {
    if (root[i] == '0' && binary_str[i] == )
  }
}

char *simple_root(char *binary_str)
{
  char *root;
  char *re_binary_str;
  char trial[1024] = {'0'};
  int len = 0;
  int i = 0;

  re_binary_str = strdup(binary_str);
  root = malloc(sizeof(char) * 1024);
  while (binary_str[len] != 0)
    len++;
  len--;
  while (len > 0)
  {
    re_binary_str[len] = '\0';
    add(trial, root, re_binary_str);
    if (check_mul(trial, re_binary_str))
      add(root, root, num)
    len--;
  }
  return root;
}
