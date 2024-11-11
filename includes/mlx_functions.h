/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:54:56 by bgoulard          #+#    #+#             */
/*   Updated: 2024/11/11 21:54:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_FUNCTIONS_H
# define MLX_FUNCTIONS_H

# include "mlx_structs.h"

/**
 * @brief Initializes the MLX library.
 * @return Pointer to the MLX instance structure.
 */
t_xvar		*mlx_init(void);

/**
 * @brief Creates a new window.
 * @param mlx_ptr Pointer to the MLX instance.
 * @param size_x Width of the window.
 * @param size_y Height of the window.
 * @param title Title of the window.
 * @return Pointer to the new window structure.
 */
t_win_list	*mlx_new_window(\
	t_xvar *mlx_ptr, int size_x, int size_y, char *title);

/**
 * @brief Gets the screen size.
 * @param mlx_ptr Pointer to the MLX instance.
 * @param sizex Output parameter for the screen width.
 * @param sizey Output parameter for the screen height.
 * @return 0 on success, non-zero on error.
 */
int			mlx_get_screen_size(t_xvar *mlx_ptr, int *sizex, int *sizey);

/**
 * @brief Clears the specified window.
 * @param mlx_ptr Pointer to the MLX instance.
 * @param win_ptr Pointer to the window to clear.
 * @return 0 on success, non-zero on error.
 */
int			mlx_clear_window(t_xvar *mlx_ptr, t_win_list *win_ptr);

/**
 * @brief Draws a pixel in the specified window.
 * @param mlx_ptr Pointer to the MLX instance.
 * @param win_ptr Pointer to the window.
 * @param x X coordinate of the pixel.
 * @param y Y coordinate of the pixel.
 * @param color Color of the pixel.
 * @return 0 on success, non-zero on error.
 */
int			mlx_pixel_put(t_xvar *mlx_ptr, t_win_list *win_ptr, \
			int x, int y, int color);

/**
 * @brief Creates a new image.
 * @param mlx_ptr Pointer to the MLX instance.
 * @param width Width of the image.
 * @param height Height of the image.
 * @return Pointer to the new image structure.
 */
t_img		*mlx_new_image(t_xvar *mlx_ptr, int width, int height);

/**
 * @brief Retrieves the address of the image data.
 * @param img_ptr Pointer to the image.
 * @param bits_per_pixel Bits per pixel of the image.
 * @param size_line Size of each line in bytes.
 * @param endian Endian of the image (0 for little-endian, 1 for big-endian).
 * @return Pointer to the image data.
 */
char		*mlx_get_data_addr(t_img *img_ptr, int *bits_per_pixel, \
			int *size_line, int *endian);

/**
 * @brief Puts an image into a window.
 * @param mlx_ptr Pointer to the MLX instance.
 * @param win_ptr Pointer to the window.
 * @param img_ptr Pointer to the image.
 * @param x X coordinate in the window.
 * @param y Y coordinate in the window.
 * @return 0 on success, non-zero on error.
 */
int			mlx_put_image_to_window(t_xvar *mlx_ptr, t_win_list *win_ptr, \
			t_img *img_ptr, int x, int y);

/**
 * @brief Gets the color value for the specified color.
 * @param mlx_ptr Pointer to the MLX instance.
 * @param color The color to retrieve the value for.
 * @return The color value.
 */
int			mlx_get_color_value(t_xvar *mlx_ptr, int color);

/**
 * @brief Sets a mouse hook on the window.
 * @param win_ptr Pointer to the window.
 * @param funct_ptr Pointer to the function to call on mouse events.
 * @param param Parameter passed to the hook function.
 * @return 0 on success, non-zero on error.
 */
int			mlx_mouse_hook(t_win_list *win_ptr, int (*funct_ptr)(), \
			void *param);

/**
 * @brief Sets a keyboard hook on the window.
 * @param win_ptr Pointer to the window.
 * @param funct_ptr Pointer to the function to call on key events.
 * @param param Parameter passed to the hook function.
 * @return 0 on success, non-zero on error.
 */
int			mlx_key_hook(t_win_list *win_ptr, int (*funct_ptr)(), void *param);

/**
 * @brief Sets an expose hook on the window.
 * @param win_ptr Pointer to the window.
 * @param funct_ptr Pointer to the function to call on expose events.
 * @param param Parameter passed to the hook function.
 * @return 0 on success, non-zero on error.
 */
int			mlx_expose_hook(t_win_list *win_ptr, int (*funct_ptr)(), \
			void *param);

/**
 * @brief Sets a loop hook for repeated execution.
 * @param mlx_ptr Pointer to the MLX instance.
 * @param funct_ptr Pointer to the function to call in the loop.
 * @param param Parameter passed to the hook function.
 * @return 0 on success, non-zero on error.
 */
int			mlx_loop_hook(t_xvar *mlx_ptr, int (*funct_ptr)(), void *param);

/**
 * @brief Starts the main loop for MLX.
 * @param mlx_ptr Pointer to the MLX instance.
 * @return 0 on success, non-zero on error.
 */
int			mlx_loop(t_xvar *mlx_ptr);

/**
 * @brief Ends the main loop for MLX.
 * @param mlx_ptr Pointer to the MLX instance.
 * @return 0 on success, non-zero on error.
 */
int			mlx_loop_end(t_xvar *mlx_ptr);

/**
 * @brief Draws a string in the specified window.
 * @param mlx_ptr Pointer to the MLX instance.
 * @param win_ptr Pointer to the window.
 * @param x X coordinate for the string.
 * @param y Y coordinate for the string.
 * @param color Color of the string.
 * @param string The string to display.
 * @return 0 on success, non-zero on error.
 */
int			mlx_string_put(t_xvar *mlx_ptr, t_win_list *win_ptr, \
			int x, int y, int color, char *string);

/**
 * @brief Sets the font for the window.
 * @param mlx_ptr Pointer to the MLX instance.
 * @param win_ptr Pointer to the window.
 * @param name The font name.
 */
void		mlx_set_font(t_xvar *mlx_ptr, t_win_list *win_ptr, char *name);

/**
 * @brief Converts XPM data to an image.
 * @param mlx_ptr Pointer to the MLX instance.
 * @param xpm_data The XPM data.
 * @param width Output parameter for the width of the image.
 * @param height Output parameter for the height of the image.
 * @return Pointer to the created image.
 */
t_img		*mlx_xpm_to_image(t_xvar *mlx_ptr, char **xpm_data, int *width, \
			int *height);

/**
 * @brief Converts an XPM file to an image.
 * @param mlx_ptr Pointer to the MLX instance.
 * @param filename The XPM file name.
 * @param width Output parameter for the width of the image.
 * @param height Output parameter for the height of the image.
 * @return Pointer to the created image.
 */
t_img		*mlx_xpm_file_to_image(t_xvar *mlx_ptr, char *filename, \
			int *width, int *height);

/**
 * @brief Destroys a window.
 * @param mlx_ptr Pointer to the MLX instance.
 * @param win_ptr Pointer to the window.
 * @return 0 on success, non-zero on error.
 */
int			mlx_destroy_window(t_xvar *mlx_ptr, t_win_list *win_ptr);

/**
 * @brief Destroys an image.
 * @param mlx_ptr Pointer to the MLX instance.
 * @param img_ptr Pointer to the image.
 * @return 0 on success, non-zero on error.
 */
int			mlx_destroy_image(t_xvar *mlx_ptr, t_img *img_ptr);

/**
 * @brief Destroys the MLX display.
 * @param mlx_ptr Pointer to the MLX instance.
 * @return 0 on success, non-zero on error.
 */
int			mlx_destroy_display(t_xvar *mlx_ptr);

/**
 * @brief Sets an event hook for a specific event.
 * @param win_ptr Pointer to the window.
 * @param x_event The event type.
 * @param x_mask The event mask.
 * @param funct Function to call for the event.
 * @param param Parameter passed to the hook function.
 * @return 0 on success, non-zero on error.
 */
int			mlx_hook(t_win_list *win_ptr, int x_event, int x_mask, \
			int (*funct)(), void *param);

/**
 * @brief Disables key auto-repeat.
 * @param mlx_ptr Pointer to the MLX instance.
 * @return 0 on success, non-zero on error.
 */
int			mlx_do_key_autorepeatoff(t_xvar *mlx_ptr);

/**
 * @brief Enables key auto-repeat.
 * @param mlx_ptr Pointer to the MLX instance.
 * @return 0 on success, non-zero on error.
 */
int			mlx_do_key_autorepeaton(t_xvar *mlx_ptr);

/**
 * @brief Synchronizes the MLX display.
 * @param mlx_ptr Pointer to the MLX instance.
 * @return 0 on success, non-zero on error.
 */
int			mlx_do_sync(t_xvar *mlx_ptr);

/**
 * @brief Retrieves the current mouse position.
 * @param mlx_ptr Pointer to the MLX instance.
 * @param win_ptr Pointer to the window.
 * @param x Output parameter for the X coordinate.
 * @param y Output parameter for the Y coordinate.
 * @return 0 on success, non-zero on error.
 */
int			mlx_mouse_get_pos(t_xvar *mlx_ptr, t_win_list *win_ptr, \
			int *x, int *y);

/**
 * @brief Moves the mouse to a specified position.
 * @param mlx_ptr Pointer to the MLX instance.
 * @param win_ptr Pointer to the window.
 * @param x X coordinate to move to.
 * @param y Y coordinate to move to.
 * @return 0 on success, non-zero on error.
 */
int			mlx_mouse_move(t_xvar *mlx_ptr, t_win_list *win_ptr, int x, int y);

/**
 * @brief Hides the mouse cursor.
 * @param mlx_ptr Pointer to the MLX instance.
 * @param win_ptr Pointer to the window.
 * @return 0 on success, non-zero on error.
 */
int			mlx_mouse_hide(t_xvar *mlx_ptr, t_win_list *win_ptr);

/**
 * @brief Shows the mouse cursor.
 * @param mlx_ptr Pointer to the MLX instance.
 * @param win_ptr Pointer to the window.
 * @return 0 on success, non-zero on error.
 */
int			mlx_mouse_show(t_xvar *mlx_ptr, t_win_list *win_ptr);

#endif /* FIXED_MLX_H */
