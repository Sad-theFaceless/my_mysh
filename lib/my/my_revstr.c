#include "my.h"

char	*my_revstr(char *str)
{
  int	i;
  int	j;
  char	cpy[] = "*str";

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      cpy[i] = str[i];
      i = i + 1;
    }
  cpy[i] = '\0';
  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  while (i != (-1))
    {
      str[j] = cpy[i - 1];
      i = i - 1;
      j = j + 1;
    }
  str[j] = '\0';
  return (str);
}
