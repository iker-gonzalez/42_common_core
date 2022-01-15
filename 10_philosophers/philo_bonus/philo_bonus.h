/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:46:09 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/01/13 12:39:37 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>

typedef struct s_threads
{
	int		nbr_philos;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		died;
	pid_t	*pid;
	sem_t	*init;
	sem_t	*forks;
	sem_t	*death;
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
void		init_structs(t_th *th, t_ph *ph, int argc, char **argv);

///////FREE////////
int			ft_destroy_sem(t_th *th);

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
void		ft_kill_them_all(t_ph *ph);
void		ft_check_pid(t_ph *ph);

////////FREE//////////
int			ft_destroy_sem(t_th *th);

#endif