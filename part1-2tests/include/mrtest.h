/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mrtest.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 13:00:05 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/10/30 10:52:00 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MR_TEST_H
# define MR_TEST_H

/* header for strlcat and strlcpy functions on linux, remove on MAC
** comment out STRLS to skip the 'ft_strlcat' and 'ft_strlcpy' tests.
** IF ON MAC: remove LINUX define and the "-lbsd" FLAG in the Makefile variable "LIBFLAG"
*/
#define STRLS
#define LINUX
#ifdef LINUX
	#include "/usr/include/bsd/string.h"
#else
	#include <string.h>
#endif

#include "libft.h"

/* main */
int		print_success_message(int b);
void	print_start_msg(char *f_name);
void	print_end_msg(char *f_name);
void	print_bytes(void *s, size_t n);

/* test prototypes */
int		test_memset(void);
int		test_bzero(void);
int		test_memcpy(void);
int		test_memccpy(void);
int		test_memmove(void);
int		test_memchr(void);
int		test_memcmp(void);
int		test_strlen(void);
int		test_strlcpy(void);
int		test_strlcat(void);
int		test_strchr(void);
int		test_strrchr(void);
int		test_strnstr(void);
int		test_atoi(void);
int		test_isalpha(void);
int		test_isdigit(void);
int		test_isalnum(void);
int		test_isascii(void);
int		test_isprint(void);
int		test_toupper(void);
int		test_tolower(void);
int		test_calloc(void);
int		test_strdup(void);
int		test_strjoin(void);
int		test_strtrim(void);
int		test_itoa(void);
int		test_strmapi(void);

/* part 2 */
int		test_substr(void);

int		test_split(void);

#endif
