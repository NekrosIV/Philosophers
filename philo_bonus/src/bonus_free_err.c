/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_free_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:11:22 by kasingh           #+#    #+#             */
/*   Updated: 2024/06/26 17:26:13 by kasingh          ###   ########.fr       */
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
