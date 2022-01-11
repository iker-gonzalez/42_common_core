/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:46:09 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/01/11 10:11:02 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_threads
{
	pthread_t		*th;
	pthread_mutex_t	init_mutex;
	pthread_mutex_t	*eat_mutex;
	pthread_mutex_t	dead_mutex;
	int				nbr_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				died;
}					t_th;

typedef struct s_philosopher
{
	int				id;
	int				meals;
	int				t_last_meal;
	int				stamina;
	struct timeval	t_born;
	t_th			*th;
}					t_ph;

///////INITIALIZE///////
void		init_th(t_th *th, char **argv);
void		init_ph(t_ph *ph, t_th *th, int argc, char **argv);
void		init_structs_forks(t_th *th, t_ph *ph, int argc, char **argv);

///////FORKS////////
void		ft_forks_mutex(t_ph *ph);

///////UTILS////////
intptr_t	ft_atoi(const char *str);
int			get_time_diff(struct timeval ta);
void		ft_usleep(t_ph *ph, int time);
void		ft_print_status(t_ph *ph, char c);
char		*ft_status_conversion(char c);

///////ACTIONS////////
void		ft_check_forks(t_ph *ph);
void		ft_eat(t_ph *ph);
int			ft_die(t_ph *ph);
void		ft_caseof1(t_ph *ph);

////////FREE//////////
int			ft_destroy_mutex(t_th *th);

#endif