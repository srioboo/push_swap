/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:31:27 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/09 10:47:46 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "funtestlib.h"

// add here funcions prototipe
int		test_ft_dummy(int active);
t_list	*build_test_list(int active_log, int n_elem_lst, ...);
void	test_push(int active);
void	test_rotate(int active);
void	test_rev_rotate(int active);
void	test_swap(int active);
void	show_lst_data(t_list *lstest);

#endif
