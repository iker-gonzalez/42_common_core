/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:34:42 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/12/13 18:14:28 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

///////MINILIBX STRUCTURE///////
typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img_1;
	void	*img_0;
	void	*img_p;
	void	*img_e;
	void	*img_c;
	void	*img_y;
	int		width;
	int		height;
	char	**map;
	int		col_len;
	int		row_len;
	int		p_col;
	int		p_row;
	int		lap;
	char	*player;
	char	key;
	int		c;
	int		e_col;
	int		e_row;
	int		exit;
	int		moves;
}				t_data;

////////LIBFT//////////
size_t	ft_strlen1(const char *s);

//////// GNL/////////
char	*get_next_line(int fd);
int		check_line_break(char *buff);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t end);
char	*ft_substr2(char *s, unsigned int start, size_t end);
void	zero_bytes_read(int bytes_read, char *line);
size_t	ft_strlen2(char *str, int c);

////////ERRORS////////
void	ft_check_perimeter(t_data *m);
void	ft_check_values1(t_data *m, int row);
void	ft_check_values2(t_data *m, int row);
void	ft_check_values3(t_data *m, int row);
void	ft_check_errors(t_data *mlx);
void	ft_check_ber(char *argv);

///////UTILS//////////
int		ft_get_p_row(t_data *mlx, char c);
int		ft_get_p_col(t_data *mlx, char c);
void	ft_check_key_a_w(t_data *mlx, int row, int col);
void	ft_check_key_s_d(t_data *mlx, int row, int col);
int		ft_transformaitor(t_data *mlx, int row, int col);
void	ft_free_map(t_data **mlx);
void	ft_initialize(t_data *mlx, char *str);
void	ft_printf_moves(t_data *mlx, int row, int col);

///////MAP////////////
void	ft_fill_map(t_data *mlx);
void	ft_fill_1_0(t_data *mlx);
void	ft_fill_c_e(t_data *mlx);
void	ft_fill_p(t_data *mlx, int x, int y);
int		ft_keycode(int key, t_data *mlx);
int		ft_hook(t_data *mlx);
void	ft_refill_map(t_data *mlx);
void	ft_move_player(t_data *mlx, int row, int col);
void	ft_set_key(t_data *mlx);
void	ft_fill_p2(t_data *mlx);

#endif
