/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_putnbr_fd.c                                    :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/10/30 18:53:49 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/30 18:53:49 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = (unsigned int)(n * -1);
	}
	else
		num = (unsigned int)n;
	if (num > 9)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd(num % 10 + '0', fd);
}
