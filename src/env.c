#include "../include/my.h"

int     create_env2(char *str, char **env, int i)
{
  int   j;

  if ((env[i] = malloc(sizeof(str) + 1)) == NULL)
    return (1);
  j = -1;
  while (str[++j] != ' ')
    env[i][j] = str[j];
  env[i][j] = '=';
  while (str[++j])
    env[i][j] = str[j];
  env[i][j] = '\0';
  env[i + 1] = NULL;
  return (0);
}

int     create_env(char *str, char **env, int i)
{
  int   j;

  if ((env[i] = malloc(sizeof(str) + 1)) == NULL)
    return (1);
  j = -1;
  while (str[++j])
    env[i][j] = str[j];
  env[i][j] = '=';
  env[i][j + 1] = '\0';
  env[i + 1] = NULL;
  return (0);
}

void	print_env(char **env)
{
  int	i;

  i = -1;
  if (!env)
    return;
  while (env[++i])
    my_printf("%s\n", env[i]);
}

char	*cp_env(char *environ)
{
  int	i;
  char	*str;

  i = -1;
  while (environ[++i]);
  if ((str = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  i = -1;
  while (environ[++i])
    str[i] = environ[i];
  str[i] = '\0';
  return (str);
}

char	**get_env(char **environ)
{
  char	**env;
  int	i;

  if (!environ[0])
    return (NULL);
  i = -1;
  while (environ[++i]);
  if ((env = malloc(sizeof(char*) * (i + 2))) == NULL)
    return (NULL);
  i = -1;
  while (environ[++i])
    if ((env[i] = cp_env(environ[i])) == NULL)
      return (NULL);
  env[i] = NULL;
  return (env);
}
