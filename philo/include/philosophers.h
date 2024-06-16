/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:33:02 by kasingh           #+#    #+#             */
/*   Updated: 2024/06/16 15:39:21 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/************************* COLOR *************************/
# define C_R "\033[0;31m"
# define C_G "\033[0;32m"
# define C_Y "\033[0;33m"
# define C_B "\033[0;34m"
# define C_M "\033[0;35m"
# define C_C "\033[0;36m"
# define C_0 "\033[0m"

/*************************DEFINES *************************/

# define E "Error\n"
# define E_arg "Wrong number of arguments\n"
# define E_Iarg "Invalid arguments\n"
# define E_syntax "Syntax error\n"
# define E_int "Number is bigger than int max value\n"
# define E_neg "Negative number not allowed\n"
# define E_time "Time is too big\n"
# define E_init_struct "Failed to init struct\n"
# define E_malloc "Malloc failed\n"
# define E_thread "Thread failed\n"
# define E_mutex "Mutex failed\n"

/************************* STRUCTS *************************/
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
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
int					ft_atoi(char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/************************* FREE_ERR.C *************************/
// void				ft_error(char *s1, char *s2);
void				ft_free_err(t_philo *philo, char *s1, char *s2);
void				free_err_exit(const char *format, ...);

/************************* ITOA_NOSIGNE.C *************************/
char				*ft_itoa_nosigne(long int n);

#endif