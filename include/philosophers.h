/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:33:02 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/27 16:13:45 by kasingh          ###   ########.fr       */
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

/************************* COLOR *************************/
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"

/************************* STRUCTS *************************/
typedef struct s_args
{
	long int		num_philo;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	long int		num_eat;
	pthread_mutex_t	print_mutex;
	long int		start;
}					t_args;

typedef struct s_philo
{
	int				id;
	int				num_eat;
	long int		last_eat;
	pthread_t		thread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	t_args			*args;
}					t_philo;

/************************* PHILOSOPHERS.C *************************/

long				current_time_ms(void);

/************************* PARRSSING.C *************************/
int					ft_is_good_args(char **av);
int					ft_parse_args(int ac, char **av, t_args *args);

/************************* MINI_LIB.C *************************/
int					ft_strlen(char *s);
void				ft_putstr_fd(char *s, int fd);
int					ft_atol(char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/************************* FREE_ERR.C *************************/
void				ft_error(char *s1, char *s2);
void				ft_free_err(t_philo *philo, char *s1, char *s2);

/************************* ITOA_NOSIGNE.C *************************/
char				*ft_itoa_nosigne(long int n);

#endif