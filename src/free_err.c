/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:11:22 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/27 16:13:04 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_error(char *s1, char *s2)
{
	ft_putstr_fd(RED "Error\n", 2);
	if (s2)
	{
		ft_putstr_fd(YELLOW, 2);
		ft_putstr_fd(s2, 2);
		ft_putstr_fd(RED " : ", 2);
	}
	ft_putstr_fd(s1, 2);
	ft_putstr_fd("\n" RESET, 2);
	exit(1);
}

void	ft_free_err(t_philo *philo, char *s1, char *s2)
{
	free(philo);
	ft_error(s1, s2);
}
