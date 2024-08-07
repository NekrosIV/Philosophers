/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philosophers.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:33:02 by kasingh           #+#    #+#             */
/*   Updated: 2024/07/06 15:05:42 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_PHILOSOPHERS_H
# define BONUS_PHILOSOPHERS_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
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
# define E_ARG "Wrong number of arguments\n"
# define E_IARG "Invalid arguments\n"
# define E_SYNTAX "Syntax error\n"
# define E_INT "Number is bigger than int max value\n"
# define E_NEG "Negative number not allowed\n"
# define E_TIME "Time is too big\n"
# define E_INIT_STRUCT "Failed to init struct\n"
# define E_MALLOC "Malloc failed\n"
# define E_THREAD_C "Thread creation failed\n"
# define E_THREAD_J "Thread join failed\n"
# define E_THREAD_D "Thread detach failed\n"
# define E_MUTEX "Mutex failed\n"
# define E_FORK "Failed to fork\n"
# define E_SEM "Failed to init semaphore\n"

/************************* STRUCTS *************************/
typedef struct s_args
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_eat;
	int				stop_simulation;
	long int		start;
	pid_t			pid_killer;
	sem_t			*forks;
	sem_t			*eat;
	sem_t			*is_dead;
	sem_t			*stop_simu;
	sem_t			*print;
	sem_t			*wait_philo;
}					t_args;

typedef struct s_philo
{
	pid_t			pid;
	int				id;
	int				num_eat;
	long int		last_eat;
	bool			stop;
	pthread_t		thread;
	pthread_mutex_t	eat_mutex;
	t_args			*args;
}					t_philo;

/*********************** PARRSSING.C ***********************/
int					ft_is_good_args(char **av);
int					ft_parse_args(int ac, char **av, t_args *args);

/*********************** MINI_LIB.C ************************/
int					ft_strlen(char *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
int					ft_atoi(char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/************************ FORK.C ***************************/
void				do_all_fork(t_philo *philo);
void				kill_all_fork(t_philo *philos);
void				wait_all_child(t_philo *philo);

/*********************** MONITOR.C *************************/
void				start_routine_thread(t_philo *philo,
						pthread_t *routine_thread);
int					check_death(t_philo *philo);
void				clean_exit(t_philo *philo, t_philo *philos,
						pthread_t routine_thread);
void				child(t_philo *philo, t_philo *philos);

/*********************** ROUTINE.C *************************/
void				print_state(t_philo *philo, char *msg, char *color);
int					check_stop_simulation(t_philo *philo);
void				eat(t_philo *philo);
bool				take_forks(t_philo *philo);
void				sleep_and_think(t_philo *philo);
void				*philo_routine(void *arg);

/*********************** FREE_ERR.C ************************/
void				ft_error(char *s1, char *fautif, char *err);
void				close_semaphores(t_args *args);

/********************** ITOA_NOSIGNE.C *********************/
char				*ft_itoa_nosigne(long int n);

/************************* TIME.C **************************/
long				current_time_ms(void);
void				philo_wait(long time_ms);

#endif
