#include "../include/my.h"

int	main(int ac, char **av, char **environ)
{
  char	**env;

  if (ac > 1 || av[1])
    return (1);
  signal(SIGINT, sighandler);
  env = get_env(environ);
  if (env == NULL)
    if ((env = malloc(sizeof(char*) * 2)) == NULL)
      return (1);
  if (start_minishell(env) == 1)
    return (1);
  return (0);
}
