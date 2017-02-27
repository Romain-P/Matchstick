/*
** main.c for  in /home/romain.pillot/bin
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov 24 11:14:29 2016 romain pillot
** Last update Mon Feb 27 01:25:18 2017 romain pillot
*/

#include "util.h"
#include <stdlib.h>
#include "map.h"
#include <time.h>
#include "turn.h"

static t_map	*init_map(int lines, int matches)
{
  t_map		*map;

  if (!(map = malloc(sizeof(t_map))))
    return (NULL);
  map->max_sticks = 1 + (lines - 1) * 2;
  if (!(map->get = create_map(lines, map->max_sticks)))
    return (NULL);
  map->lines = lines;
  map->max_matches = matches;
  map->status = 0;
  return (map);
}

static void	free_all(t_map *map)
{
  int	i;

  i = -1;
  while (++i < map->lines)
    free(map->get[i]);
  free(map->get);
  free(map);
}

int	main(int ac, char **args)
{
  int	lines;
  int	matches;
  int	status;
  t_map	*map;

  if (ac != 3 ||
      !(lines = getnbr(args[1])) || lines < 0 || lines > 100 ||
      !(matches = getnbr(args[2])) || matches < 0 || !(map = init_map(lines, matches)))
    return (84);
  srand(time(NULL));
  display_map(map);
  player_turn(map);
  status = map->status;
  free_all(map);
  return (status);
}
