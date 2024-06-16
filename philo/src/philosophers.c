/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:32:08 by kasingh           #+#    #+#             */
/*   Updated: 2024/06/15 15:35:38 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_strcut(t_args *args) {
  printf("num_philo = %d\n", args->num_philo);
  printf("time_to_die = %d\n", args->time_to_die);
  printf("time_to_eat = %d\n", args->time_to_eat);
  printf("time_to_sleep = %d\n", args->time_to_sleep);
  printf("num_eat = %d\n", args->num_eat);
  printf("start = %ld\n", args->start);
}

long	current_time_ms(void) {
  struct timeval time;

  if (gettimeofday(&time, NULL) == -1)
    return (-1);
  return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}

int	init_philo(t_args *args, t_philo **philo) {
  int i;

  *philo = malloc(sizeof(t_philo) * args->num_philo);
  if (!(*philo))
    return (-1);
  i = 0;
  while (i < args->num_philo) {
    (*philo)[i].id = i + 1;
    (*philo)[i].num_eat = 0;
    (*philo)[i].last_eat = args->start;
    (*philo)[i].args = args;
    pthread_mutex_init(&((*philo)[i].left_fork), NULL);
    if (i == args->num_philo - 1)
      (*philo)[i].right_fork = &((*philo)[0].left_fork);
    else
      (*philo)[i].right_fork = &((*philo)[i + 1].left_fork);
    i++;
  }
  return (0);
}

void	philo_wait(int time_ms) {
  long start_time;

  start_time = current_time_ms();
  while (current_time_ms() - start_time < time_ms)
    usleep(100);
}

void	ft_print_philo(t_philo **philo) {
  int i;

  i = 0;
  while (i < (*philo)->args->num_philo) {
    printf("id = %d\n", (*philo)[i].id);
    printf("num_eat = %d\n", (*philo)[i].num_eat);
    printf("last_eat = %ld\n", (*philo)[i].last_eat);
    printf("left_fork = %p\n", &(*philo)[i].left_fork);
    printf("right_fork = %p\n", (*philo)[i].right_fork);
    i++;
  }
}

int	main(int ac, char **av) {
  t_args args;
  t_philo *philo;

  if (ft_parse_args(ac, av, &args) == -1)
    free_err_exit(E E_arg "%e", 1);
  ft_print_strcut(&args);
  if (init_philo(&args, &philo) == -1)
    free_err_exit(E E_init_struct "%e", 1);
  ft_print_philo(&philo);
  free(philo);
  return (0);
}
