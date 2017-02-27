/*
** map.c for  in /home/romain.pillot/projects/CPE_2016_matchstick/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun Feb 26 19:56:38 2017 romain pillot
** Last update Mon Feb 27 00:28:46 2017 romain pillot
*/

#include <stdlib.h>
#include "util.h"
#include "map.h"

char	**create_map(int lines, int max_sticks)
{
  char	**map;
  int	i;
  int	j;
  int	sticks;

  if (!(map = malloc(sizeof(char *) * lines)))
    return (NULL);
  i = (j =  -1);
  while (++i < lines)
    {
      map[i] = malloc(sizeof(char) * max_sticks);
      sticks = 1 + i * 2;
      j = -1;
      while (++j < max_sticks)
	map[i][j] = 0;
      j = (max_sticks - sticks) / 2;
      while (sticks--)
	map[i][j++] = STICK;
    }
  return (map);
}

void	display_map(t_map *map)
{
  int	i;
  int	j;
  char	c;

  i = -1;
  while (++i < map->lines + 2)
    {
      j = -1;
      while (++j < map->max_sticks + 2)
	{
	  if (!j || j == map->max_sticks + 1 || i == 0 || i == map->lines + 1)
	    display_char('*');
	  else
	    display_char((c = map->get[i - 1][j - 1]) ? c : ' ');
	}
      display_char('\n');
    }
}

int	get_matches(t_map *map, int line)
{
  int	i;
  int	matches;

  matches = 0;
  i = -1;
  while (++i < map->max_sticks)
    matches += map->get[line][i] == STICK ? 1 : 0;
  return (matches);
}

void	remove_matches(t_map *map, int line, int matches, bool player)
{
  int	i;
  char	*c;
  
  display(player ? "Player" : "AI");
  display(" removed ");
  putnbr(matches);
  display(" match(es) from line ");
  putnbr(line);
  display_char('\n');
  i = map->max_sticks;
  while (--i >= 0 && matches)
    if (*(c = &map->get[line - 1][i]) == STICK && matches--)
      *c = 0;
}

bool	empty_map(t_map *map)
{
  int	i;
  int	j;

  i = -1;
  while (++i < map->lines && (j = -1))
    while (++j < map->max_sticks)
      if (map->get[i][j] == STICK)
	return (false);
  return (true);
}
