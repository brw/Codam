/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                       :+:    :+:             */
/*                                                     +:+                    */
/*   By: bvan-den <bvan-den@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/09 06:14:00 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/11/10 20:25:17 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define LIBFT_H

# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_vprintf(const char *format, va_list args);

#endif
