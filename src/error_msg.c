#include "../include/my.h"

void    error_perm_denied(char *av)
{
  if (av[0])
    {
      if (!av[1])
	my_printf("%c: Permission denied.\n", av[0]);
      else
	my_printf("%s: Permission denied.\n", av);
    }
}

void    error_not_a_directory(char *av)
{
  if (av[0])
    {
      if (!av[1])
	my_printf("%c: Not a directory.\n", av[0]);
      else
	my_printf("%s: Not a directory.\n", av);
    }
}

void    error_no_such_file_or_dir(char *av)
{
  if (av[0])
    {
      if (!av[1])
	my_printf("%c: No such file or directory.\n", av[0]);
      else
	my_printf("%s: No such file or directory.\n", av);
    }
}

void    error_command_not_found(char *av)
{
  if (av[0])
    {
      if (!av[1])
	my_printf("%c: Command not found.\n", av[0]);
      else
	my_printf("%s: Command not found.\n", av);
    }
}
