#include "my.h"

char	*my_epur_str(char *str)
{
  char	*epur_str;
  int	i;
  int	j;

  if ((epur_str = malloc(sizeof(str))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str[i] && (str[i] == ' ' || str[i] == '\t'))
    i++;
  while (str[i])
    {
      if (!((str[i] == ' ' && str[i - 1] == ' ') ||
	    (str[i] == '\t' && str[i - 1] == '\t')))
	{
	  epur_str[j] = str[i];
	  j++;
	}
      i++;
    }
  if (epur_str[j - 1] == ' ' || epur_str[j - 1] == '\t')
    epur_str[j - 1] = '\0';
  else
    epur_str[j] = '\0';
  return (epur_str);
}
