#include "../include/my.h"

void	add_path(char *av, char **arg)
{
  int	k;

  k = 0;
  while (av[k] != ' ' && av[k] != '\0')
    {
      arg[0][k] = av[k];
      k++;
    }
  arg[0][k] = '\0';
}

void	recup_path_2(char *path, char **env_path, char *av)
{
  int	fd;
  int	i;
  int	j;
  int	k;

  fd =  -1;
  j = -1;
  while ((fd < 0) && (env_path[++j]))
    {
      i = -1;
      while (env_path[j][++i])
	path[i] = env_path[j][i];
      k = 0;
      path[i] = '/';
      i++;
      while (av[k] != ' ' && av[k] != '\0')
	{
	  path[i] = av[k];
	  i++;
	  k++;
	}
      path[i] = '\0';
      fd = open(path, 00);
    }
  close(fd);
}

char	*recup_path(char *av, int *l, char **env_path)
{
  char	*path;
  int	i;

  i = 0;
  while (av[i] != ' ' && av[i] != '\0')
    i++;
  *l = i + 1;
  *l = *l + 20;
  if ((path = malloc(sizeof(char) * (i + 1 + *l))) == NULL)
    return (NULL);
  recup_path_2(path, env_path, av);
  return (path);
}
