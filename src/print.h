/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   print.h                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/11/10 20:20:57 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/11/10 20:48:54 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdarg.h>
# include <unistd.h>

ssize_t	print_char(int c);
ssize_t	print_str(const char *str);
ssize_t	print_unbr(unsigned long num, const char *symbols, unsigned int base);
ssize_t	print_nbr(long c, const char *symbols, unsigned int base);
ssize_t	print_ptr(unsigned long p);
#endif
