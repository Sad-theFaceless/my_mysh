#include "../include/my.h"

char	**recup_arg_abs(char *str)
{
  char	**arg;
  int	l;
  int	i;

  l = my_strlen(str);
  if ((arg = malloc(sizeof(char*) * (1 + 1))) == NULL)
    return (NULL);
  if ((arg[0] = malloc(sizeof(char) * (l + 1))) == NULL)
    return (NULL);
  if ((arg[0] = malloc(sizeof(char))) == NULL)
    return (NULL);
  i = -1;
  while (str[++i])
    arg[0][i] = str[i];
  arg[0][i] = '\0';
  arg[1] = NULL;
  return (arg);
}

int	my_exec_abs(char *str, char **env)
{
  pid_t	pid;
  char	**arg;

  if ((arg = recup_arg_abs(str)) == NULL)
    return (1);
  if ((pid = fork()) == -1)
    return (1);
  if (pid > 0)
    waitpid(pid, 0, 0);
  else if (pid == 0)
    {
      if (execve(str, arg, env) == -1)
	{
	  error_command_not_found(str);
	  exit(1);
	}
      else
	exit(0);
    }
  return (0);
}
