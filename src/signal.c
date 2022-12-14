#include "../include/my.h"

void    sighandler(int signum)
{
  (void)signum;
  write(1, "\n", 1);
  prompt();
}
