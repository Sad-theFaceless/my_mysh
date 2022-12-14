#include "../include/my.h"

int     setenv_novoid(char *str, char **env)
{
  int   i;
  int   j;

  i = -1;
  while (env[++i])
    {
      if (env[i][0] == str[0] && env[i][1] == str[1] &&
	  env[i][2] == str[2])
	{
	  if ((env[i] = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
	    return (1);
	  j = -1;
	  while (str[++j] != ' ')
	    env[i][j] = str[j];
	  env[i][j] = '=';
	  while (str[++j])
	    env[i][j] = str[j];
	  env[i][j] = '\0';
	  return (0);
	}
    }
  if (create_env2(str, env, i) == 1)
    return (1);
  return (0);
}

int     setenv_void(char *str, char **env)
{
  int   i;
  int   j;

  i = -1;
  while (env[++i])
    {
      if (env[i][0] == str[0] && env[i][1] == str[1] &&
	  env[i][2] == str[2])
	{
	  if ((env[i] = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
	    return (1);
	  j = -1;
	  while (str[++j])
	    env[i][j] = str[j];
	  env[i][j] = '=';
	  env[i][j + 1] = '\0';
	  return (0);
	}
    }
  if (create_env(str, env, i) == 1)
    return (1);
  return (0);
}

int     my_setenv2(char *str, char **env, int nb_arg)
{
  if (nb_arg == 1)
    {
      if (setenv_void(str, env) == 1)
	return (1);
      return (0);
    }
  if (setenv_novoid(str, env) == 1)
    return (1);
  return (0);
}

int     my_setenv(char *str, char **env)
{
  int   i;
  int   j;
  int   k;
  char  *path;

  i = -1;
  j = 0;
  while (str[++i])
    if (str[i] == ' ')
      j++;
  if ((path = malloc(sizeof(str))) == NULL)
    return (1);
  if (j > 2)
    {
      my_printf("setenv: Too many arguments.\n");
      return (-1);
    }
  i = -1;
  while (str[++i] != ' ');
  k = -1;
  while (str[++i])
    path[++k] = str[i];
  path[k + 1] = '\0';
  my_setenv2(path, env, j);
  return (0);
}
