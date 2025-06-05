/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:30:23 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/05 12:08:04 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_push(int active)
{
	t_link_list	*lstest_a;
	t_link_list	*lstest_b;

	lstest_a = NULL;
	lstest_b = NULL;
	if (active > 0)
	{
		fun_group_start("PUSH");
		fun_test_header_label(1, "--- test_push");
		lstest_a = build_test_list(1, 3, 1, 2, 3);
		lstest_b = build_test_list(1, 3, 4, 5, 6);
		push_a(&lstest_a, &lstest_b);
		show_lst_data(lstest_a);
		show_lst_data(lstest_b);
		fun_test_header_label(2, "--- test_push");
		lstest_a = build_test_list(1, 3, 8, 7, 9);
		lstest_b = build_test_list(1, 3, 4, 5, 6);
		push_b(&lstest_b, &lstest_a);
		show_lst_data(lstest_a);
		show_lst_data(lstest_b);
		fun_test_header_label(3, "--- test_push");
		lstest_a = build_test_list(1, 3, 1, 3, 4);
		lstest_b = build_test_list(1, 2, 5, 9);
		push_a(&lstest_b, &lstest_a);
		show_lst_data(lstest_a);
		show_lst_data(lstest_b);
		fun_test_header_label(4, "--- test_push");
		lstest_a = build_test_list(1, 3, 0, 9, 2);
		lstest_b = build_test_list(1, 2, 1, 4);
		push_b(&lstest_a, &lstest_b);
		show_lst_data(lstest_a);
		show_lst_data(lstest_b);
	}
}
