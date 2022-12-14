#include "../include/my.h"

void	my_exit(void)
{
  write(1, "exit\n", 5);
  exit(0);
}

char    *my_realloc(char *str)
{
  char  *str2;

  if ((str2 = malloc(sizeof(str) + 1)) == NULL)
    return (NULL);
  str2 = str;
  return (str2);
}

void    prompt(void)
{
  write(1, "$> ", 3);
}

void    ctrl_d(void)
{
  my_printf("exit\n");
  exit(0);
}
