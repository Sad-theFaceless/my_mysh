#include "../my.h"

void	my_strascii(char *str)
{
  int	count;
  int	length;

  length = my_strlen(str);
  count = -1;
  while (++count <= length)
    {
      if (str[count] > 0 && str[count] <= 7)
	{
	  my_putstr("\\00");
	  my_put_nbr_base(str[count], "01234567");
	}
      else if (str[count] > 7 && str[count] < 32)
	{
	  my_putstr("\\0");
	  my_put_nbr_base(str[count], "01234567");
	}
      else if (str[count] == 127)
	{
	  my_putstr("\\");
	  my_put_nbr_base(str[count], "01234567");
	}
      else if (str[count] >= 32 && str[count] < 127)
       	my_putchar(str[count]);
    }
}
