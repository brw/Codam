/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   print.h                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/11/10 20:20:57 by bvan-den      #+#    #+#                 */
/*   Updated: 2023/06/01 20:03:23 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdarg.h>
# include <unistd.h>

ssize_t	print_char(int fd, int c);
ssize_t	print_str(int fd, const char *str);
ssize_t	print_unbr(int fd, unsigned long num, const char *symbols,
			unsigned int base);
ssize_t	print_nbr(int fd, long c, const char *symbols, unsigned int base);
ssize_t	print_ptr(int fd, unsigned long p);

#endif
