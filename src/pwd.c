#include "../include/my.h"

char	*recup_pwd(char **env)
{
  char	*pwd;
  int	i;
  int	j;
  int	k;

  i = -1;
  k = -1;
  j = 3;
  if (!env)
    return (NULL);
  while (env[++i])
    if (my_strcmp(env[i], "PWD=") == 0)
      {
	if (!env[i][0])
	  return (NULL);
	while (env[i][++j]);
	if ((pwd = malloc(sizeof(char) * (j + 4))) == NULL)
	  return (NULL);
	j = 3;
	while (env[i][++j])
	  pwd[++k] = env[i][j];
      }
  pwd[k + 1] = '\0';
  return (pwd);
}
