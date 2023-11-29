/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:00:51 by mdouiri           #+#    #+#             */
/*   Updated: 2022/02/28 18:27:49 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx_int.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include "define.h"
# include <X11/keysym.h>
# include "./mlx/mlx.h"
# include <X11/X.h>
# include <X11/Xlib.h>

int		move(int keysum, t_window *data);
int		simple(int fd);
int		ft_iter(t_node *list, t_window *data);
int		ft_verification(char *str, int *count, int *round, int nbline);
int		ft_verif2(char *str, t_mappy *map, t_window *data, int *round);
int		ft_lstsize(t_node *lst);
int		ft_destroy(t_window *data);
int		checkerss(t_window *data, int x, int y);
int		move(int keysum, t_window *data);
int		ft_strleni(char *str);
int		ft_strlen(char *str);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_printf(char *bon, ...);

void	ft_begin(int *cara, t_window *data);
void	ft_lstadd_back(t_node **alst, t_node *new);
void	deleteallnodes(t_node *start);
void	ft_draw_scene(t_window *data);
void	init_image(t_window *data);
void	move2(t_window *data, int x, int y);
void	ft_putnbr(long int n, char *base, int *count);
void	ft_putnbri(unsigned long int n, char *base, int *count);
void	ft_what(const char m, va_list va, int *count);

t_node	*ft_lstlast(t_node *lst);
t_node	*ft_lstnew(char *content);

char	*ft_strchr2(char *s, int c);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strjoin2(char **s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*get_my_line(char *str);
char	*upgradebuffer(char *myline, char *buffertot);
char	*ft_continu(char *buffer, char *final, int numb, int fd);
char	*get_next_line(int fd);

t_data	ft_generate_image(t_window *data, char *pos);
void	ft_window(int *cara, t_window *data);
void	ft_checkinit(t_window *data);

#endif
