#include "../include/my.h"

void    modif_pwd2(char *path, char **env, int i)
{
  int   j;
  int   k;

  j = -1;
  env[i][0] = 'P';
  env[i][1] = 'W';
  env[i][2] = 'D';
  env[i][3] = '=';
  k = 3;
  while (path[++j])
    env[i][++k] = path[j];
  env[i][k + 1] = '\0';
}

int	modif_pwd(char *path, char **env)
{
  int	l;
  int	i;
  int	j;
  char	*old_path;

  i = -1;
  j = -1;
  while (env[++i])
    {
      if (my_strcmp(env[i], "PWD=") == 0)
	{
	  l = my_strlen(path) + my_strlen(env[i]) + 1;
	  if ((old_path = malloc(sizeof(char) *
				 my_strlen(env[i]) + 1)) == NULL)
	    return (1);
	  j = -1;
	  while (env[i][++j])
	    old_path[j] = env[i][j];
	  old_path[j] = '\0';
	  if ((env[i] = malloc(sizeof(char) * l)) == NULL)
	    return (1);
	  modif_pwd2(path, env, i);
	}
    }
  return (0);
}

int		my_exec_cd_2(char *path, char **env)
{
  struct stat	sb;

  if (stat(path, &sb) == -1)
    {
      error_no_such_file_or_dir(path);
      return (-1);
    }
  if (S_ISDIR(sb.st_mode) != 1)
    {
      error_not_a_directory(path);
      return (-1);
    }
  if (opendir(path) == NULL)
    {
      error_perm_denied(path);
      return (-1);
    }
  if (modif_pwd(path, env) == 1)
    return (1);
  chdir(path);
  return (0);
}

void	copy_exec_cd_path(char *path, char *str, int j)
{
  int	i;

  i = 2;
  while (str[++i])
    path[++j] = str[i];
  path[++j] = '\0';
  if (!path[0])
    return;
}

int	my_exec_cd(char *str, char **env)
{
  char	*pwd;
  char	*path;
  int	l;
  int	i;
  int	j;

  if ((pwd = recup_pwd(env)) == NULL)
    return (1);
  l = my_strlen(str) + my_strlen(pwd) + 1;
  if ((path = malloc(sizeof(char) * l + 1)) == NULL)
    return (1);
  i = -1;
  j = -1;
  if (str[3] != '/')
    {
      while (pwd[++i])
	path[++j] = pwd[i];
      path[++j] = '/';
    }
  copy_exec_cd_path(path, str, j);
  if (my_exec_cd_2(path, env) == 1)
    return (1);
  return (0);
}
