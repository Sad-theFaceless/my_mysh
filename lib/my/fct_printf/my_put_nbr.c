#include "../my.h"

void	my_put_nbr(int nb)
{
  int	i;

  i = 0;
  if (nb < 0)
    {
      my_putchar('-');
      if (nb == -2147483648)
	{
	  i = 1;
	  nb = nb + 1;
	}
      nb = nb * (-1);
    }
  if (nb >= 10)
    my_put_nbr(nb / 10);
  if (i == 1)
    {
      i = 0;
      my_putchar(nb % 10 + '1');
    }
  if (i == 0)
    my_putchar(nb % 10 + '0');
}

void	my_put_nbr2(unsigned int nb)
{
  int   i;

  i = 0;
  if (nb >= 10)
    my_put_nbr(nb / 10);
  if (i == 1)
    {
      i = 0;
      my_putchar(nb % 10 + '1');
    }
  if (i == 0)
    my_putchar(nb % 10 + '0');
}
