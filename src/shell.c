#include "../include/my.h"

int	cmd2(char *str, char **env)
{
  if (my_strcmp(str, "setenv ") == 0)
    {
      if (my_setenv(str, env) == 1)
	return (0);
    }
  else if (my_strcmp(str, "unsetenv") == 0)
    {
      if (my_unsetenv(str, env) == 1)
	return (0);
    }
  else if (env)
    {
      if (my_exec(str, env) == 1)
	return (1);
    }
  return (0);
}

int	cmd(char *str, char **env)
{
  str = my_epur_str(str);
  if (my_strcmp(str, "exit\0") == 0)
    my_exit();
  else if (my_strcmp(str, "cd ") == 0)
    {
      if (str[3] == '-')
	return (0);
      if (my_exec_cd(str, env) == 1)
	return (1);
    }
  else if (my_strcmp(str, "env\0") == 0)
    print_env(env);
  else if (str[0] == '.' || str[0] == '/')
    {
      if (my_exec_abs(str, env) == 1)
	return (1);
    }
  else
    if (cmd2(str, env) == 1)
      return (1);
  return (0);
}

char	*get_my_line(char buf, char *str, char **env, int *pos)
{
  if (buf != '\n')
    {
      str[*pos] = buf;
      *pos = *pos + 1;
      str[*pos] = '\0';
      if ((str = my_realloc(str)) == NULL)
	return (NULL);
    }
  else
    {
      if (cmd(str, env) == 1)
	return (NULL);
      if ((str = malloc(sizeof(char) * (1 + 1))) == NULL)
	return (NULL);
      *pos = 0;
      prompt();
    }
  return (str);
}

int	start_minishell(char **env)
{
  int	end_of_file;
  char	*str;
  char	buf;
  int	pos;

  if ((str = malloc(sizeof(char) * (1 + 1))) == NULL)
    return (1);
  pos = 0;
  prompt();
  while ((end_of_file = read(0, &buf, 1)) > 0)
    if ((str = get_my_line(buf, str, env, &pos)) == NULL)
      return (1);
  if (!end_of_file)
    ctrl_d();
  return (0);
}
