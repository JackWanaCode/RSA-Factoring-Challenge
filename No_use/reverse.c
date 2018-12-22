#include <stdio.h>
#include <stdlib.h>

char *reverse_str(char *str)
{
	char *re_str;
	int i = 0, j = 0;
	char temp;

	for (; str[i] != '\0'; i++)
		;
	re_str = malloc(sizeof(char) * (i + 1));
	if (!re_str)
		return (NULL);
	i--;
	for (j = 0; i >= 0; j++, i--)
	{
		re_str[j] = str[i];
	}
	re_str[j] = '\0';
	return (re_str);
}

int main ()
{
	char *str = "Holberton";
	char *rev_str;

	rev_str = reverse_str(str);
	printf("%s\n", rev_str);
	return (0);
}
