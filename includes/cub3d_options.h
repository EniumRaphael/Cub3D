/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_options.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 01:15:15 by bgoulard          #+#    #+#             */
/*   Updated: 2024/11/27 11:35:39 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_OPTIONS_H
# define CUB3D_OPTIONS_H

void	c3_set_parse_excl(void *usr_control_struct);
void	c3_set_file(void *usr_control_struct, const char *arg);
void	c3_set_debug(void *usr_control_struct);
void	c3_set_save(void *usr_control_struct);
void	c3_print_help(void *usr_control_struct);

#endif /* CUB3D_OPTIONS_H */
