/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed_mlx.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:54:56 by bgoulard          #+#    #+#             */
/*   Updated: 2024/11/09 00:16:25 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_MLX_H
# define FIXED_MLX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <X11/extensions/XShm.h>
# include <X11/XKBlib.h>
/* #include	<X11/xpm.h> */


# define MLX_TYPE_SHM_PIXMAP 3
# define MLX_TYPE_SHM 2
# define MLX_TYPE_XIMAGE 1

# define MLX_MAX_EVENT LASTEvent

# define ENV_DISPLAY "DISPLAY"
# define LOCALHOST "localhost"
# define ERR_NO_TRUECOLOR "MinilibX Error : No TrueColor Visual available.\n"
# define WARN_SHM_ATTACH "MinilibX Warning : X server can't attach shared memory.\n"

typedef	struct	s_xpm_col
{
	int		name;
	int		col;
}				t_xpm_col;


struct	s_col_name
{
	char	*name;
	int		color;
};

typedef struct	s_event_list
{
	int		mask;
	int		(*hook)();
	void	*param;
}				t_event_list;


typedef struct	s_win_list
{
	Window				window;
	GC					gc;
	struct s_win_list	*next;
	int					(*mouse_hook)();
	int					(*key_hook)();
	int					(*expose_hook)();
	void				*mouse_param;
	void				*key_param;
	void				*expose_param;
	t_event_list		hooks[MLX_MAX_EVENT];
}				t_win_list;


typedef struct	s_img
{
	XImage			*image;
	Pixmap			pix;
	GC				gc;
	int				size_line;
	int				bpp;
	int				width;
	int				height;
	int				type;
	int				format;
	char			*data;
	XShmSegmentInfo	shm;
}				t_img;

typedef struct	s_xvar
{
	Display		*display;
	Window		root;
	int			screen;
	int			depth;
	Visual		*visual;
	Colormap	cmap;
	int			private_cmap;
	t_win_list	*win_list;
	int			(*loop_hook)();
	void		*loop_param;
	int			use_xshm;
	int			pshm_format;
	int			do_flush;
	int			decrgb[6];
	Atom		wm_delete_window;
	Atom		wm_protocols;
	int 		end_loop;
}				t_xvar;

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
