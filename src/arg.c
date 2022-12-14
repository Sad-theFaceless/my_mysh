#include "../include/my.h"

void	add_arg(char *av, char **arg)
{
  int   i;
  int   j;
  int   k;

  i = 0;
  while (av[i] != ' ')
    i++;
  i++;
  j = 1;
  k = 0;
  while (av[i] != '\0')
    {
      if (av[i] == ' ')
	{
	  arg[j][k] = '\0';
	  j++;
	  k = 0;
	}
      else
	arg[j][k++] = av[i];
      i++;
    }
  arg[j][k] = '\0';
  arg[j + 1] = (char *)0;
}

char	**malloc_arg(char *av, int j)
{
  int	i;
  int	tmp;
  char	**arg;

  i = 0;
  if ((arg = malloc(sizeof(char*) * (j + 1))) == NULL)
    return (NULL);
  while (av[i] != ' ' && av[i] != '\0')
    i++;
  i++;
  tmp = i;
  j = 1;
  while (av[i++] != '\0')
    {
      if (av[i] == ' ')
	{
	  if ((arg[j++] = malloc(sizeof(char) * (i - tmp + 1))) == NULL)
	    return (NULL);
	  tmp = i;
	}
    }
  if (((arg[j] = malloc(sizeof(char) * (i - tmp + 1))) == NULL) ||
      ((arg[j + 1] = malloc(sizeof(char))) == NULL))
    return (NULL);
  return (arg);
}

char	**recup_arg(char *av, int l)
{
  int	i;
  int	j;
  char	**arg;

  i = -1;
  j = 0;
  while (av[++i] != '\0')
    if (av[i] == ' ')
      j++;
  if (j > 0)
    {
      if ((arg = malloc_arg(av, j + 1)) == NULL)
	return (NULL);
    }
  else
    if ((arg = malloc(sizeof(char*) * 2)) == NULL)
      return (NULL);
  if ((arg[0] = malloc(sizeof(char) * l)) == NULL)
    return (NULL);
  add_path(av, arg);
  if (j > 0)
    add_arg(av, arg);
  return (arg);
}
