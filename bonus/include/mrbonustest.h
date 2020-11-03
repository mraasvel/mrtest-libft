#ifndef MRBONUSTEST_H
# define MRBONUSTEST_H

#include <stdio.h>
#include "libft.h"

/* main */
int		print_success_message(int b);
void	print_start_msg(char *f_name);
void	print_end_msg(char *f_name);

/* list utils */
void	test_lstdelone(t_list *lst, void (*del)(void*));
void	test_lstclear(t_list **lst, void (*del)(void*));

/* test bonus functions */
int		test_lstnew(void);

#endif