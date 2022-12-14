#include "../include/my.h"

void	add_env_path(char *path, char **env_path)
{
  int	i;
  int	j;
  int	k;

  i = -1;
  j = 0;
  k = -1;
  while (path[++i])
    {
      if (path[i] == ':')
	{
	  env_path[j][k + 1] = '\0';
	  j++;
	  k = -1;
	}
      else
	env_path[j][++k] = path[i];
    }
  env_path[j + 1] = NULL;
}

char	**recup_env_path_2(char *path)
{
  int	i;
  int	j;
  char	**env_path;

  i = -1;
  j = 1;
  while (path[++i])
    if (path[i] == ':')
      j++;
  if ((env_path = malloc(sizeof(char*) * j)) == NULL)
    return (NULL);
  i = -1;
  while (++i <= j)
    if ((env_path[i] = malloc(sizeof(char) * 21)) == NULL)
      return (NULL);
  add_env_path(path, env_path);
  return (env_path);
}

char	**recup_env_path(char **env, char **env_path)
{
  char	*path;
  int   i;
  int   j;
  int   k;

  i = -1;
  j = 4;
  k = -1;
  if (!env)
    return (NULL);
  while (env[++i])
    if (my_strcmp(env[i], "PATH=") == 0)
      {
	while (env[i][++j]);
	if ((path = malloc(sizeof(char) * (j + 4 + 1))) == NULL)
	  return (NULL);
	j = 4;
	while (env[i][++j])
	  path[++k] = env[i][j];
      }
  if (env[i])
    path[k + 1] = '\0';
  if ((env_path = recup_env_path_2(path)) == NULL)
    return (NULL);
  return (env_path);
}

int	my_exec(char *av, char **env)
{
  char	*path;
  char	**arg;
  char	**env_path;
  pid_t	pid;
  int	l;

  if (((env_path = recup_env_path(env, NULL)) == NULL) ||
      ((path = recup_path(av, &l, env_path)) == NULL) ||
      ((arg = recup_arg(av, l)) == NULL))
    return (1);
  if ((pid = fork()) == -1)
    return (1);
  if (pid > 0)
    waitpid(pid, 0, 0);
  else if (pid == 0)
    {
      if (execve(path, arg, env) == -1)
	{
	  error_command_not_found(av);
	  exit(1);
	}
      else
	exit(0);
    }
  return (0);
}
