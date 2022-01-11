/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:32:15 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/12/01 11:58:38 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdarg.h>
# include <stdlib.h>

////////DATA EXCHANGE//////
int		ft_server(void);
int		ft_client(int args, char **argv);
void	ft_signal_handler(int signum, siginfo_t *info, void *context);

/////////LIBFT////////////
int		ft_atoi(const char *str);

/////////PRINTF///////////
int		ft_printf(const char *format, ...);
int		ft_checkk_conditions(char c, va_list args);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_count_nb(int nb);
int		ft_put_nb(int nb);

#endif
