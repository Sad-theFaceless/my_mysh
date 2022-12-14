#include "my.h"

int	my_strlen(char *str)
{
  int	a;

  a = 0;
  while (str[a] != '\0')
    a = a + 1;
  return (a);
}
