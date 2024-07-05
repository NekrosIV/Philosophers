/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_free_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:11:22 by kasingh           #+#    #+#             */
/*   Updated: 2024/07/05 18:55:56 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

void	ft_error(char *s1, char *fautif, char *err)
{
	ft_putstr_fd(C_R, 2);
	ft_putstr_fd(s1, 2);
	if (fautif)
	{
		ft_putstr_fd(C_Y, 2);
		ft_putstr_fd(fautif, 2);
		ft_putstr_fd(C_R " : ", 2);
	}
	ft_putstr_fd(err, 2);
	ft_putstr_fd(C_0, 2);
}

void	close_semaphores(t_args *args)
{
	sem_close(args->forks);
	sem_unlink("/forks");
	sem_close(args->stop_simu);
	sem_unlink("/stop_simu");
	sem_close(args->print);
	sem_unlink("/print");
	sem_close(args->is_dead);
	sem_unlink("/is_dead");
	sem_close(args->eat);
	sem_unlink("/eat");
}
