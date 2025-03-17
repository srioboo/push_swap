/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:30:23 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/11 23:16:45 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_sort(int active)
{
	t_link_list *lstest;
	t_link_list *lstaux;

	lstest = NULL;
	lstaux = NULL;
	if (active > 0)
	{
		fun_test_header_label(1, "--- test_sort");
		lstest = build_test_list(1, 3, 4, 7, 2);
		show_lst_data(lstest);
		op_sort(lstest, lstaux);
		lstest = op_swap(lstest, OP_SWAP_A);
		show_lst_data(lstest);
	}
}

void	test_sort_three(int active)
{
	t_link_list	*lstest;
	t_link_list *lstaux;

	lstest = NULL;
	lstaux = NULL;
	if (active > 0)
	{
		fun_test_header_label(1, "--- test_sort_three");
		lstest = build_test_list(1, 3, 1, 4, 3);
		show_lst_data(lstest);
		op_sort(lstest, lstaux);
		show_lst_data(lstest);
		fun_test_header_label(2, "--- test_sort_three");
		lstest = build_test_list(1, 3, 4, 1, 3);
		show_lst_data(lstest);
		op_sort(lstest, lstaux);
		show_lst_data(lstest);
	}
}

void	test_find_max(int active)
{
	t_link_list *lstest;

	lstest = NULL;
	if (active > 0)
	{
		fun_test_header_label(1, "--- test_find_max");
		lstest = build_test_list(1, 3, 4, 2, 6);
		printf("max: %d\n", find_max(lstest));
		show_lst_data(lstest);

		fun_test_header_label(2, "--- test_find_max");
		lstest = build_test_list(1, 3, 1, 8, 3);
		printf("max: %d\n", find_max(lstest));
		show_lst_data(lstest);
	}
}
