#include "my.h"

void	my_printf_flags(char *str, va_list ap, int count)
{
  if (str[count] == '%')
    my_putchar('%');
  else if (str[count] == 'c')
    my_putchar((char)va_arg(ap, int));
  else if (str[count] == 's')
    my_putstr(va_arg(ap, char *));
  else if (str[count] == 'i' || str[count] == 'd')
    my_put_nbr(va_arg(ap, int));
  else if (str[count] == 'b')
    my_put_nbr_base(va_arg(ap, unsigned int), "01");
  else if (str[count] == 'o')
    my_put_nbr_base(va_arg(ap, unsigned int), "01234567");
  else if (str[count] == 'x')
    my_put_nbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
  else if (str[count] == 'X')
    my_put_nbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
  else if (str[count] == 'u')
    my_put_nbr2(va_arg(ap, unsigned int));
  else if (str[count] == 'S')
    my_strascii(va_arg(ap, char*));
  else if (str[count] == 'p')
    {
      my_putstr("0x");
      my_put_nbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
    }
}

void		my_printf(char *str, ...)
{
  va_list	ap;
  int		count;

  count = -1;
  va_start(ap, str);
  while (str[++count] != '\0')
    {
      if (str[count] == '%')
	{
	  count++;
	  if (str[count] == 'c' || str[count] == 's' || str[count] == 'i' || \
	      str[count] == 'd' || str[count] == 'b' || str[count] == 'o' || \
	      str[count] == 'x' || str[count] == 'X' || str[count] == 'u' || \
	      str[count] == 'S' || str[count] == 'p' || str[count] == '%')
	    my_printf_flags(str, ap, count);
	  else
	    {
	      my_putchar('%');
	      my_putchar(str[count]);
	    }
	}
      else
	my_putchar(str[count]);
    }
  va_end(ap);
}
