#include "my.h"

int	my_getnbr(char *str)
{
  int	i;
  int	result;
  int	sign;

  i = -1;
  result = 0;
  sign = 0;
  while (str[++i])
    {
      if (str[i] == '-')
	sign++;
      else if (str[i] >= '0' && str[i] <= '9')
	result = (result * 10) + (str[i] - '0');
      else if (str[i] != '+')
	return (0);
    }
  if ((sign % 2) == 0)
    return (result);
  else
    return (-result);
}
