/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:30:23 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/17 19:10:55 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_rotate(int active)
{
	t_link_list	*lstest;

	lstest = NULL;
	if (active > 0)
	{
		fun_group_start("ROTATE");
		fun_test_header_label(1, "--- test_rotate");
		lstest = build_test_list(1, 3, 1, 2, 3);
		lstest = op_rotate(lstest, OP_ROTATE_A);
		show_lst_data(lstest);
		fun_test_header_label(2, "--- test_rotate");
		lstest = build_test_list(1, 3, 4, 1, 3);
		lstest = op_rotate(lstest, OP_ROTATE_A);
		show_lst_data(lstest);
		fun_test_header_label(3, "--- test_rotate");
		lstest = build_test_list(1, 5, 10, 4, 2, 8, 9);
		lstest = op_rotate(lstest, OP_ROTATE_A);
		show_lst_data(lstest);
	}
}

void	test_rev_rotate(int active)
{
	t_link_list	*lstest;

	lstest = NULL;
	if (active > 0)
	{
		fun_group_start("REV ROTATE");
		fun_test_header_label(1, "--- test_rev_rotate");
		lstest = build_test_list(1, 3, 1, 2, 3);
		lstest = op_rev_rotate(lstest, OP_REV_ROTATE_A);
		show_lst_data(lstest);
		fun_test_header_label(2, "--- test_rev_rotate");
		lstest = build_test_list(1, 3, 4, 1, 3);
		lstest = op_rev_rotate(lstest, OP_ROTATE_A);
		show_lst_data(lstest);
		fun_test_header_label(3, "--- test_rev_rotate");
		lstest = build_test_list(1, 5, 10, 4, 2, 8, 9);
		lstest = op_rev_rotate(lstest, OP_ROTATE_A);
		show_lst_data(lstest);
	}
}
