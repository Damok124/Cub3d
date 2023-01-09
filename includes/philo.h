/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:33:15 by zharzi            #+#    #+#             */
/*   Updated: 2023/01/09 13:49:25 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_context {
	int				members;
	int				life_time;
	int				meal_time;
	int				rest_time;
	int				meals_max;
}					t_context;

typedef struct s_philo {
	pthread_t		philo;
	int				id;
	pthread_mutex_t	life;
	int				alive;
	int				full;
	int				meals;
	long int		deadline;
	struct timeval	start_time;
	pthread_mutex_t	right;
	pthread_mutex_t	*left;
	pthread_mutex_t	*mut_printf;
	t_context		context;
}					t_philo;

/////////////////////////
//	UTILS
/////////////////////////
int			ft_isdigit(int c);
int			ft_atoi_safe(const char *nptr, int *check);
void		ft_true_free(void **ptr);
int			ft_get_chrono(struct timeval start);
void		ft_print_msg(t_philo *philo, char *msg);
void		ft_print_last_msg(t_philo *philo, char *msg);
void		ft_usleep(t_philo *philo, int timer);

/////////////////////////
//	PARSERS
/////////////////////////
int			ft_check_args(int ac, char **argv);
int			ft_check_arg_positive(char *arg);
int			ft_check_arg_overflow(char *arg);

/////////////////////////
//	CHECKERS
/////////////////////////
int			ft_is_expired(t_philo *philo);
void		ft_is_full(t_philo *philo, int *all_full);
int			ft_is_dead(t_philo *philo);

/////////////////////////
//	INITIALIZERS
/////////////////////////
t_context	ft_init_context(char **argv, int ac);
t_philo		*ft_init_tab_philo(t_context context);
void		ft_share_printf_mutex(t_philo *philos, pthread_mutex_t *mut_printf);
void		ft_init_mutexes(t_philo *tab);

/////////////////////////
//	CORE
/////////////////////////
void		ft_grab_right(t_philo *philo, int *forks);
void		ft_grab_left(t_philo *philo, int *forks);
int			ft_eating(t_philo *philo);
void		ft_sleeping(t_philo *philo, int *forks);
void		ft_thinking(t_philo *philo);
void		*ft_routine(void *arg);
void		ft_put_thread_on_routine(t_philo *tab);
void		*ft_soul_taking(void *arg);
void		ft_philo(t_philo *philos);

/////////////////////////
//	EXIT
/////////////////////////
void		ft_join_them_all(t_philo *tab);
void		ft_unset_philos(t_philo *tab);

#endif
