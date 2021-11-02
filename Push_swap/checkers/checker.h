#ifndef CHECKER_H
#define	CHECKER_H

# define PA 1
# define PB 2
# define SA 3
# define SB 4
# define RA 5
# define RB 6 
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10
# define SS 11


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/*
typedef struct s_elem
{
	int		action;
	struct s_elem *next;

}				t_elem;

typedef struct	s_list
{
	t_elem	*first;
	t_elem	*last;
	int		size;
}				t_list;
*/

void	error(int i);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdupp(const char *s1, int leaks);
int	get_next_line(int fd, char **line);
void	ft_putstr(char *str);




#endif
