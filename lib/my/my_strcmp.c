#include "my.h"

int	my_strcmp(char *str1, char *str2)
{
  int	i;
  int	j;
  int	tmp;
  int	count;

  if (!(str1) || !(str2) || !(str1[0]) || !(str2[0]))
    return (1);
  i = -1;
  while (str1[++i])
    {
      count = 0;
      j = -1;
      tmp = i - 1;
      while (str2[++j] && str1[++tmp])
	if (str2[j] == str1[tmp])
	  count++;
      if (count == my_strlen(str2))
	return (i);
    }
  return (-1);
}
