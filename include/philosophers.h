/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:33:02 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/22 16:09:27 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
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

typedef struct s_philo
{
	int				id;
	int				num_eat;
	long int		last_eat;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_philo	*next;
	struct s_philo	*prev;
}					t_philo;

/************************* PHILOSOPHERS.C *************************/

/************************* PARRSSING.C *************************/
int					ft_is_good_args(char **av);
int					ft_parse_args(int ac, char **av, t_args *args);

/************************* MINI_LIB.C *************************/
int					ft_strlen(char *s);
void				ft_error(char *s);
void				ft_putstr_fd(char *s, int fd);
int					ft_atoi(char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/************************* ITOA_NOSIGNE.C *************************/
char				*ft_itoa_nosigne(int n);

#endif