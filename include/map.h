/*
** util.h for  in /home/romain.pillot/projects/CPE_2016_matchstick/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun Feb 26 19:49:53 2017 romain pillot
** Last update Mon Feb 27 00:12:44 2017 romain pillot
*/

#ifndef MAP_H_
# define MAP_H_

# define STICK ('|')

# include <stdbool.h>

typedef struct	s_map
{
  char		**get;
  int		lines;
  int		max_sticks;
  int		max_matches;
  int		status;
}		t_map;

char		**create_map(int lines, int max_sticks);

void		display_map(t_map *map);

int		get_matches(t_map *map, int line);

void		remove_matches(t_map *map, int line, int matches, bool player);

bool		empty_map(t_map *map);

#endif /* !MAP_H_ */
