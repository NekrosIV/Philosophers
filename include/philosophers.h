/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:33:02 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/21 18:35:04 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_args
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_eat;
	pthread_mutex_t	print_mutex;
	long int		start;
}					t_args;

/************************* PHILOSOPHERS.C *************************/

/************************* PARRSSING.C *************************/
int					ft_is_good_args(char **av);
int					ft_parse_args(int ac, char **av, t_args *args);

/************************* MINI_LIB.C *************************/
int					ft_atoi(char *s);
void				ft_putstr_fd(char *s, int fd);
void				ft_error(char *s);
#endif