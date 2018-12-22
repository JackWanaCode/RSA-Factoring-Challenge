#include <stdio.h>
#include <stdlib.h>
// #include <ctype.h>
// #include <string.h>
#include <limits.h>

unsigned long stoi(char *str)
{
  int i;
  unsigned long n = 0;

  for (i = 0; str[i] != '\n'; i++)
    n = n*10 + str[i] - '0';
  return (n);
}

unsigned long simple_root(unsigned long n)
{
  unsigned long root = 0;
  unsigned long bit;
  unsigned long trial;

  printf("%lu\n", n);

  for (bit = ULONG_MAX; bit > 0; bit >>= 1)
  {
      trial = root + bit;
      if (trial * trial <= n)
      {
          root += bit;
      }
  }
  return root;
}

unsigned long check_prime(unsigned long n)
{
  unsigned long i = simple_root(n);

  // printf("%lu\n", n);
  if (n == 2 || n == 3)
    return (1);
  while (i > 3)
  {
    if (n % i == 0)
      return (i);
    i--;
  }
  return (1);
}

void prime_ret(unsigned long n, unsigned long *ret)
{
  unsigned long num = simple_root(n);
  unsigned long temp;

  // printf("n is %lu, root is %lu\n", n, num);
  while(1)
  {
    if (n % num == 0)
    {
      temp = check_prime(num);
      if (temp == 1)
      {
        *ret = num;
        return;
      }
      num = temp;
    }
    else
      num--;
  }
}


int main(int argc, char **argv)
{
  FILE *file;
  unsigned long n = 0;
  unsigned long len = 0;
  unsigned long ret = 0;
  char *line;

  if (argc != 2)
    exit(1);
  file = fopen(argv[1], "r");
  while (getline(&line, &len, file) != -1)
  {
    n = stoi(line);
    prime_ret(n, &ret);
    printf("%lu=%lu*%lu\n", n, n / ret, ret);
  }
  fclose(file);
  return (0);
}
