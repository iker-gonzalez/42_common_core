/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:08:47 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/11/24 11:22:14 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include "Libft/libft.h"

///////////LINKED LIST////////
void	ft_check_args(int argc, char **argv, t_list **head_a);
void	ft_newnode(t_list **head_a, size_t num);
///////////ERRORS/////////////
void	ft_checknum(char **str, int argc);
int		ft_check_max_lenght(char *str);
int		ft_check_lenght_10(char *str);
void	ft_checkrepeat(t_list **head_a);
///////////DISTRIBUTION//////
void	ft_distribution(t_list **head_a, t_list **head_b, int size);
///////////UTILS/////////////
void	ft_pos(t_list *lst);
void	ft_small(t_list **lst);
void	ft_pos_upd(t_list **lst);
void	ft_rank(t_list *lst);
int		ft_sizeof_chunk(t_list *lst);
int		ft_sorted(t_list *lst);
int		ft_part(t_list **lst, int range_min, int range_max, int part);
int		ft_check_pair(int nb);
int		ft_biggest_content(t_list *lst);
int		ft_smallest_content(t_list *lst);
int		ft_ra_mov(t_list **head, int part);
int		ft_rra_mov(t_list **head, int part);
int		ft_ra_rra_mov(t_list **lst, int part);
void	ft_free(t_list **head);
void	ft_reverse_list(t_list **head);
///////////MOVES////////////
void	ft_swap_a(t_list **head_a);
void	ft_swap_b(t_list **head_b);
void	ft_swap_ab(t_list **head_a, t_list **head_b);
void	ft_push_a(t_list **head_a, t_list **head_b);
void	ft_push_b(t_list **head_b, t_list **head_a);
void	ft_rotate_a(t_list **head_a);
void	ft_rotate_b(t_list **head_b);
void	ft_rotate_a_b(t_list **head_a, t_list **head_b);
void	ft_reverse_a(t_list **head_a);
void	ft_reverse_b(t_list **head_b);
void	ft_reverse_a_b(t_list **head_a, t_list **head_b);
////////////ALGORITHM////////
void	ft_caseof2(t_list **lst);
void	ft_caseof3(t_list **lst);
void	ft_caseof4(t_list **head_a, t_list **head_b);
void	ft_caseof5(t_list **head_a, t_list **head_b);
void	ft_iterate_5(t_list **head_a, t_list **head_b);
void	ft_push_a_b(t_list **head_a, t_list **head_b, int part, int x);
void	ft_ra_push_a(t_list **head_a, t_list **head_b, int biggest);
void	ft_ra_push_b(t_list **head_a, t_list **head_b, int part, int x);
void	ft_rra_push_b(t_list **head_a, t_list **head_b, int part, int x);
void	ft_push_b_a(t_list **head_a, t_list **head_b);
int		ft_rb_rrb_mov(t_list **lst, int biggest);
int		ft_rb_mov(t_list **head, int biggest);
int		ft_rrb_mov(t_list **head, int biggest);
void	ft_ra_push_a(t_list **head_a, t_list **head_b, int biggest);
void	ft_rra_push_a(t_list **head_a, t_list **head_b, int biggest);
void	ft_iterate_part(t_list **head_a, t_list **head_b, int size, int x);
#endif
