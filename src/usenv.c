#include "../include/my.h"

int     my_unsetenv2(char *str, char **env)
{
  int   i;

  i = -1;
  while (env[++i])
    {
      if (env[i][0] == str[0] && env[i][1] == str[1] &&
	  env[i][2] == str[2])
	{
	  while (env[i])
	    {
	      env[i] = env[i + 1];
	      i++;
	    }
	  return (0);
	}
    }
  return (0);
}

int     my_unsetenv(char *str, char **env)
{
  int   i;
  char  *arg;
  int   tmp;

  i = 7;
  while (str[++i] == ' ');
  if (str[i] == '\0')
    {
      my_printf("unsetenv: Too few arguments.\n");
      return (0);
    }
  tmp = i;
  while (str[++i]);
  if ((arg = malloc(sizeof(char) * (i - 7))) == NULL)
    return (1);
  i = tmp;
  i--;
  tmp = -1;
  while (str[++i])
    arg[++tmp] = str[i];
  arg[tmp + 1] = '\0';
  if (my_unsetenv2(arg, env) == 1)
    return (1);
  return (0);
}
