/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:30:23 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/14 10:47:49 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_sort(int active)
{
	t_link_list	*lstest;
	t_link_list	*lstaux;

	lstest = NULL;
	lstaux = NULL;
	if (active > 0)
	{
		fun_group_start("SORT");
		fun_test_header_label(1, "--- test_sort");
		lstest = build_test_list(1, 3, 4, 7, 2);
		show_lst_data(lstest);
		op_sort(&lstest, &lstaux);
		swap_a(&lstest);
		show_lst_data(lstest);
	}
}

void	test_full_sort(int active)
{
	t_link_list	*lstest;
	t_link_list	*lstaux;

	lstest = NULL;
	lstaux = NULL;
	if (active > 0)
	{
		fun_group_start("SORT FULL SORT");
		fun_test_header_label(1, "--- test_sort_three");
		lstest = build_test_list(1, 5, -4, 1, 3, 20, 10);
		op_sort(&lstest, &lstaux);
		show_lst_data_with_label(lstest, "list aux A");
		show_lst_data_with_label(lstaux, "list aux B");
		fun_test_header_label(2, "--- test_sort_three");
		lstest = build_test_list(1, 5, 1, 4, 3, 20, 10);
		op_sort(&lstest, &lstaux);
		show_lst_data_with_label(lstest, "list aux A");
		show_lst_data_with_label(lstaux, "list aux B");
		fun_test_header_label(3, "--- test_sort_three");
		lstest = build_test_list(1, 5, -3, 1, 4, -20, 10);
		op_sort(&lstest, &lstaux);
		show_lst_data_with_label(lstest, "list aux A");
		show_lst_data_with_label(lstaux, "list aux B");
	}
}

void	test_sort_three(int active)
{
	t_link_list	*lstest;
	t_link_list	*lstaux;
	int			count;

	count = 0;
	lstest = NULL;
	lstaux = NULL;
	if (active > 0)
	{
		fun_group_start("SORT TINY SHORT (3 elements)");
		fun_test_header_label(++count, "--- test_sort_three");
		lstest = build_test_list(1, 3, 4, 1, 3);
		op_sort(&lstest, &lstaux);
		show_lst_data(lstest);
		lstaux = NULL;
		fun_test_header_label(++count, "--- test_sort_three");
		lstest = build_test_list(1, 3, 1, 4, 3);
		op_sort(&lstest, &lstaux);
		show_lst_data(lstest);
		lstaux = NULL;
		fun_test_header_label(++count, "--- test_sort_three");
		lstest = build_test_list(1, 3, 3, 1, 4);
		op_sort(&lstest, &lstaux);
		show_lst_data(lstest);
		lstaux = NULL;
		fun_test_header_label(++count, "--- test_sort_three");
		lstest = build_test_list(1, 3, 13, 1, 40);
		op_sort(&lstest, &lstaux);
		show_lst_data(lstest);
		lstaux = NULL;
		fun_test_header_label(++count, "--- test_sort_three");
		lstest = build_test_list(1, 3, 4, 67, 3);
		op_sort(&lstest, &lstaux);
		show_lst_data(lstest);
		lstaux = NULL;
		fun_test_header_label(++count, "--- test_sort_three");
		lstest = build_test_list(1, 3, 3, 67, 4);
		op_sort(&lstest, &lstaux);
		show_lst_data(lstest);
		lstaux = NULL;
		fun_test_header_label(++count, "--- test_sort_three");
		lstest = build_test_list(1, 3, -3, -7, 4);
		op_sort(&lstest, &lstaux);
		show_lst_data(lstest);
		lstaux = NULL;
	}
}

void	test_sort_four(int active)
{
	t_link_list	*lstest;
	t_link_list	*lstaux;
	int			count;

	count = 0;
	lstest = NULL;
	lstaux = NULL;
	if (active > 0)
	{
		fun_group_start("SORT MEDIUM SHORT (4 elements)");
		fun_test_header_label(++count, "--- test_sort_four");
		lstest = build_test_list(1, 4, 1, 3, 8, 2);
		op_sort(&lstest, &lstaux);
		show_lst_data(lstest);
		lstaux = NULL;
		fun_test_header_label(++count, "--- test_sort_four");
		lstest = build_test_list(1, 4, 4, 3, 7, 9);
		op_sort(&lstest, &lstaux);
		show_lst_data(lstest);
		lstaux = NULL;
		fun_test_header_label(++count, "--- test_sort_four");
		lstest = build_test_list(1, 4, 5, 12, 7, 9);
		op_sort(&lstest, &lstaux);
		show_lst_data(lstest);
	}
}

static void	test_sort_five_0(int active)
{
	t_link_list	*lstest;
	t_link_list	*lstaux;
	int			count;

	count = 0;
	lstest = NULL;
	lstaux = NULL;
	if (active > 0)
	{
		fun_group_start("SORT MEDIUM SHORT (5 elements)");
		fun_test_header_label(++count, "--- test_sort_five");
		lstest = build_test_list(1, 5, 4, 1, 3, 8, 2);
		op_sort(&lstest, &lstaux);
		show_lst_data(lstest);
		lstaux = NULL;
		fun_test_header_label(++count, "--- test_sort_five");
		lstest = build_test_list(1, 5, 1, 4, 3, 7, 9);
		op_sort(&lstest, &lstaux);
		show_lst_data(lstest);
		lstaux = NULL;
		fun_test_header_label(++count, "--- test_sort_five");
		lstest = build_test_list(1, 5, 2, 5, 12, 7, 9);
		op_sort(&lstest, &lstaux);
		show_lst_data(lstest);
	}
}

static void	test_sort_five_1(int active)
{
	t_link_list	*lstest;
	t_link_list	*lstaux;
	int			count;

	count = 0;
	lstest = NULL;
	lstaux = NULL;
	if (active > 0)
	{
		fun_group_start("SORT MEDIUM SHORT (5 elements)");
		fun_test_header_label(++count, "--- test_sort_five");
		lstest = build_test_list(1, 5, 14, 36, 100, 3, 18);
		op_sort(&lstest, &lstaux);
		show_lst_data(lstest);
		lstaux = NULL;
		fun_test_header_label(++count, "--- test_sort_five");
		lstest = build_test_list(1, 5, 12, 98, 46, 71, 16);
		op_sort(&lstest, &lstaux);
		show_lst_data(lstest);
		lstaux = NULL;
		fun_test_header_label(++count, "--- test_sort_five");
		lstest = build_test_list(1, 5, 7, 1, 5, 87, 28);
		op_sort(&lstest, &lstaux);
		show_lst_data(lstest);
	}
}

static void	test_sort_five_2(int active)
{
	t_link_list	*lstest;
	t_link_list	*lstaux;
	int			count;

	count = 0;
	lstest = NULL;
	lstaux = NULL;
	if (active > 0)
	{
		fun_group_start("SORT MEDIUM SHORT (5 elements)");
		fun_test_header_label(++count, "--- test_sort_five");
		lstest = build_test_list(1, 5, 6, 59, 98, 33, 22);
		op_sort(&lstest, &lstaux);
		show_lst_data(lstest);
		lstaux = NULL;
		fun_test_header_label(++count, "--- test_sort_five");
		lstest = build_test_list(1, 5, 69, 19, 70, 17, 1);
		op_sort(&lstest, &lstaux);
		show_lst_data(lstest);
		lstaux = NULL;
		fun_test_header_label(++count, "--- test_sort_five");
		lstest = build_test_list(1, 5, 45, 49, 14, 1, 20);
		op_sort(&lstest, &lstaux);
		show_lst_data(lstest);
	}
}

void	test_sort_five(int active)
{
	t_link_list	*lstest;
	t_link_list	*lstaux;
	int			count;

	count = 0;
	lstest = NULL;
	lstaux = NULL;
	if (active > 0)
	{
		fun_group_start("SORT MEDIUM SHORT (5 elements)");
		fun_test_header_label(++count, "--- test_sort_five");
		lstest = build_test_list(1, 5, 26, 38, 13, 6, 31);
		op_sort(&lstest, &lstaux);
		show_lst_data(lstest);
		lstaux = NULL;
		fun_test_header_label(++count, "--- test_sort_five");
		lstest = build_test_list(1, 5, 69, 19, 70, 17, 1);
		op_sort(&lstest, &lstaux);
		show_lst_data(lstest);
		test_sort_five_0(active);
		test_sort_five_1(active);
		test_sort_five_2(active);
	}
}
