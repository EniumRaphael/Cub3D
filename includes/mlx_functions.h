/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:54:56 by bgoulard          #+#    #+#             */
/*   Updated: 2024/11/10 05:35:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_MLX_H
# define FIXED_MLX_H

# include "mlx_structs.h"

t_xvar		*mlx_init(void);
t_win_list	*mlx_new_window(t_xvar *mlx_ptr, int size_x, int size_y, char *title);

int			mlx_clear_window(t_xvar *mlx_ptr, t_win_list *win_ptr);
int			mlx_pixel_put(t_xvar *mlx_ptr, t_win_list *win_ptr, int x, int y, int color);

t_img		*mlx_new_image(t_xvar *mlx_ptr,int width,int height);
char		*mlx_get_data_addr(t_img *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
int			mlx_put_image_to_window(t_xvar *mlx_ptr, t_win_list *win_ptr, t_img *img_ptr, int x, int y);
int			mlx_get_color_value(t_xvar *mlx_ptr, int color);

int			mlx_mouse_hook (t_win_list *win_ptr, int (*funct_ptr)(), void *param);
int			mlx_key_hook (t_win_list *win_ptr, int (*funct_ptr)(), void *param);
int			mlx_expose_hook (t_win_list *win_ptr, int (*funct_ptr)(), void *param);

int			mlx_loop_hook (t_xvar *mlx_ptr, int (*funct_ptr)(), void *param);
int			mlx_loop (t_xvar *mlx_ptr);
int			mlx_loop_end (t_xvar *mlx_ptr);

int			mlx_string_put(t_xvar *mlx_ptr, t_win_list *win_ptr, int x, int y, int color, char *string);
void		mlx_set_font(t_xvar *mlx_ptr, t_win_list *win_ptr, char *name);
t_img		*mlx_xpm_to_image(t_xvar *mlx_ptr, char **xpm_data, int *width, int *height);
t_img		*mlx_xpm_file_to_image(t_xvar *mlx_ptr, char *filename, int *width, int *height);
int			mlx_destroy_window(t_xvar *mlx_ptr, t_win_list *win_ptr);

int			mlx_destroy_image(t_xvar *mlx_ptr, t_img *img_ptr);

int			mlx_destroy_display(t_xvar *mlx_ptr);
int			mlx_hook(t_win_list *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);

int			mlx_do_key_autorepeatoff(t_xvar *mlx_ptr);
int			mlx_do_key_autorepeaton(t_xvar *mlx_ptr);
int			mlx_do_sync(t_xvar *mlx_ptr);

int			mlx_mouse_get_pos(t_xvar *mlx_ptr, t_win_list *win_ptr, int *x, int *y);
int			mlx_mouse_move(t_xvar *mlx_ptr, t_win_list *win_ptr, int x, int y);
int			mlx_mouse_hide(t_xvar *mlx_ptr, t_win_list *win_ptr);
int			mlx_mouse_show(t_xvar *mlx_ptr, t_win_list *win_ptr);

int			mlx_get_screen_size(t_xvar *mlx_ptr, int *sizex, int *sizey);

#endif /* FIXED_MLX_H */
