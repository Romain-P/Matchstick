/*
** gnl.c for  in /home/romain.pillot/gnl
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Feb 21 11:35:52 2017 romain pillot
** Last update Mon Feb 27 00:56:32 2017 romain pillot
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static char	*app(char *str, char c)
{
  char		*ap;
  int		i;
  int		j;

  i = (j = 0);
  while (str && str[i] && ++i);
  if (!(ap = malloc(sizeof(char) * (i + 2))))
    return (NULL);
  while(str && j < i)
    {
      ap[j] = str[j];
      j++;
    }
  ap[j] = c;
  ap[j + 1] = 0;
  if (str)
    free(str);
  return (ap);
}

char	*scan_line()
{
  char	*str;
  char	buffer[1];
  int	error;

  str = NULL;
  while ((error = read(0, buffer, 1)))
    {
      if (error == -1)
	{
	  if (str)
	    free(str);
	  return (NULL);
	}
      if (buffer[0] == '\n')
	return (str);
      else if (buffer[0] == EOF || !(str = app(str, buffer[0])))
	break;
    }
  if (str)
    free(str);
  return (NULL);
}
