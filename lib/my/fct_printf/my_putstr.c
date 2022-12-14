#include "../my.h"

int	my_putstr(char *str)
{
  int	a;

  a = 0;
  if (!str[a])
    return (1);
  else if (!str[a + 1])
    return (1);
  else
    while (str[a] != '\0')
      {
	my_putchar(str[a]);
	a = a + 1;
      }
  return (0);
}
