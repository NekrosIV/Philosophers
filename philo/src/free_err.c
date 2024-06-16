/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:11:22 by kasingh           #+#    #+#             */
/*   Updated: 2024/04/17 14:23:19 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	ft_error(char *s1, char *s2)
// {
// 	ft_putstr_fd(RED "Error\n", 2);
// 	if (s2)
// 	{
// 		ft_putstr_fd(YELLOW, 2);
// 		ft_putstr_fd(s2, 2);
// 		ft_putstr_fd(RED " : ", 2);
// 	}
// 	ft_putstr_fd(s1, 2);
// 	ft_putstr_fd("\n" RESET, 2);
// 	exit(1);
// }

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_check_format(char c, va_list arg)
{
	ft_putstr_fd(C_Y, 2);
	if (c == 's')
		ft_putstr_fd(va_arg(arg, char *), 2);
	else if (c == 'c')
		ft_putchar_fd(va_arg(arg, int), 2);
	else if (c == 'f')
		free(va_arg(arg, void *));
	else if (c == 'F')
		free_split(va_arg(arg, char **));
	ft_putstr_fd(C_R, 2);
}

void	free_err_exit(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		e;

	i = 0;
	e = 0;
	va_start(arg, format);
	ft_putstr_fd(C_R, 2);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[++i] == 'e')
				e = va_arg(arg, int);
			else
				ft_check_format(format[i], arg);
		}
		else
			write(2, &format[i], 1);
		i++;
	}
	va_end(arg);
	ft_putstr_fd(C_0, 2);
	exit(e);
}

void	ft_free_err(t_philo *philo, char *s1, char *s2)
{
	free(philo);
	free_err_exit(s1, s2);
}
