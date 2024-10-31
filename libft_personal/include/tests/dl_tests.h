/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_tests.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:51:11 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 16:52:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DL_TESTS_H
# define DL_TESTS_H

int	t_dl_add_front(void);
int	t_dl_add_back(void);

int	t_dl_apply(void);
int	t_dl_apply_range(void);
int	t_dl_apply_range_node(void);

int	t_dl_clear(void);
int	t_dl_clear_range(void);

int	t_dl_create(void);

int	t_dl_copy_node(void);
int	t_dl_copy_list(void);

int	t_dl_delete_self(void);
int	t_dl_delete_range(void);
int	t_dl_delete(void);

int	t_dl_find(void);

int	t_dl_get_datas(void);
int	t_dl_get_nodes(void);

int	t_dl_at(void);
int	t_dl_begin(void);
int	t_dl_end(void);

int	t_dl_map(void);

int	t_dl_new(void);

int	t_dl_pop(void);
int	t_dl_pop_back(void);
int	t_dl_push(void);
int	t_dl_push_back(void);

int	t_dl_rev(void);

int	t_dl_size(void);
int	t_dl_size_of_data(void);

int	t_dl_subrange(void);

#endif /* DL_TESTS_H */
