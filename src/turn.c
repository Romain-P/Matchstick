/*
** turn.c for  in /home/romain.pillot/projects/CPE_2016_matchstick/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun Feb 26 21:50:01 2017 romain pillot
** Last update Mon Feb 27 00:30:08 2017 romain pillot
*/

#include "map.h"
#include "util.h"
#include <stdlib.h>
#include "turn.h"

static bool	scan_matches(t_map *map, int *matches, int line)
{
  char		*scan;

  display("Matches: ");
  scan = scan_line();
  *matches = getnbr(scan);
  free(scan);
  if (*matches == 0)
    display("Error: you have to remove at least one match\n");
  else if (*matches < 0)
    display("Error: invalid input (positive number expected)\n");
  else if (*matches > map->max_matches)
    {
      display("Error: you cannot remove more than ");
      putnbr(map->max_matches);
      display(" matches per turn\n");
    }
  else if (*matches > get_matches(map, line - 1))
    display("Error: not enough matches on this line\n");
  else
    return (true);
  return (false);
}

static bool	scan_lines(t_map *map, int *line)
{
  char		*scan;

  display("Line: ");
  scan = scan_line();
  *line = getnbr(scan);
  free(scan);
  if (*line <= 0 || *line > map->lines)
    {
      display(*line < 0 ? "Error: invalid input (positive number expected)\n" :
	      "Error: this line is out of range\n");
      return (false);
    }
  return (true);
}

/* note: naive AI, cba this */
static void	robot_turn(t_map *map)
{
  int		i;
  int		n;

  display("\nAI's turn...\n");
  i = -1;
  while (++i < map->lines)
    if ((n = get_matches(map, i)))
      {
	remove_matches(map, i + 1, n > 1 ? (rand() % n) + 1 : 1, false);
	break;
      }
  display_map(map);
  if (!empty_map(map))
    player_turn(map);
  else
    {
      display("I lost... snif... but I'll get you next time!!\n");
      map->status = 1;
    }
}

void	player_turn(t_map *map)
{
  int	lines;
  int	matches;

  display("\nYour turn :\n");
  while (!scan_lines(map, &lines) ||
	 !scan_matches(map, &matches, lines));
  remove_matches(map, lines, matches, true);
  display_map(map);
  if (!empty_map(map))
    robot_turn(map);
  else
    {
      display("You lost, too bad...\n");
      map->status = 2;
    }
}
