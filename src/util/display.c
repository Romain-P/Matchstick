/*
** display.c for  in /home/romain.pillot/projects/PSU_2016_navy/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Feb  7 14:39:21 2017 romain pillot
** Last update Sun Feb 26 21:39:04 2017 romain pillot
*/

#include "util.h"
#include <unistd.h>

static int	str_length(char *str)
{
  int		i;

  i = 0;
  while (str[i] && ++i);
  return (i);
}

void	display(char *str)
{
  write(1, str, str_length(str));
}

void	display_digit(int digit)
{
  char	c;

  c = digit + '0';
  write(1, &c, 1);
}
  
void	display_char(char c)
{
  write(1, &c, 1);
}
