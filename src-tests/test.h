/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:31:27 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/14 10:39:45 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "funtestlib.h"

// add here funcions prototipe
int			test_ft_dummy(int active);

t_link_list	*build_test_list(int active_log, int n_elem_lst, ...);

void		test_push(int active);
void		test_rotate(int active);
void		test_rev_rotate(int active);
void		test_rotate_both(int active);
void		test_swap(int active);
void		test_sort(int active);
void		test_sort_three(int active);
void		test_sort_four(int active);
void		test_sort_five(int active);
void		test_sort_five_1(int active);
void		test_sort_five_2(int active);
void		test_find_max(int active);
void		test_full_sort(int active);

void		show_lst_data_with_label(t_link_list *lstest, char *label);
void		show_lst_data(t_link_list *lstest);

#endif
