#include "../my.h"

void		my_put_nbr_base(unsigned int nb, char *base)
{
  unsigned int	rt;
  unsigned int	length;
  unsigned int	div;

  length = my_strlen(base);
  rt = 0;
  div = 1;
  while ((nb / div) >= length)
    div = div * length;
  while (div > 0)
    {
      rt = (nb / div) % length;
      my_putchar(base[rt]);
      div = div / length;
    }
}
