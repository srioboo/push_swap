/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:30:23 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/24 19:59:29 by srioboo-         ###   ########.fr       */
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

void	do_sort_work(char *label, int test_num, t_link_list *lstest,
		t_link_list *lstaux) {
	fun_test_header_label(test_num, label);
	// show_lst_data(lstest);
	op_sort(&lstest, &lstaux);
	show_lst_data(lstest);
	show_lst_data(lstaux);
}

void	test_full_sort(int active)
{
	int	count;

	count = 0;
	if (active > 0)
	{
		fun_group_start("SORT FULL SORT");
		// do_sort_work("--- test_full_sort", ++count,
		// 	build_test_list(1, 6, 4, -1, -2, -20, -35, -10), NULL);
		do_sort_work("--- test_full_sort", ++count,
			build_test_list(1, 6, 4, 1, 2, 20, 35, 10), NULL);
		do_sort_work("--- test_full_sort", ++count,
			build_test_list(1, 6, 4, 1, 0, 20, 35, 10), NULL);
		do_sort_work("--- test_full_sort", ++count,
			build_test_list(1, 6, -4, 1, 3, 20, 35, 10), NULL);
		// do_sort_work("--- test_full_sort", ++count,
		// 	build_test_list(1, 6, 1, 4, 3, 20, 35, 10), NULL);
		// do_sort_work("--- test_full_sort", ++count,
		// 	build_test_list(1, 6, -3, 1, 4, -20, 67, 10), NULL);
		// do_sort_work("--- test_full_sort", ++count,
		// 	build_test_list(1, 15, -77, -102, 56, 77, 85, 95,
		// 		-19, -75, -74, -8, 107, -13, 31, -42, -103), NULL);
	// 	do_sort_work("--- TEST WRONG", ++count,
	// 			build_test_list(1, 100, 47, 11, 16, 90, 24, 20, 96, 77, 99, 60, 15, 73, 82, 53, 71, 26, 34, 61, 66, 56, 81, 58, 64, 55, 89, 63, 38, 10, 27, 67, 7, 83, 68, 69, 17, 57, 13, 32, 88, 80, 23, 1, 62, 65, 45, 49, 85, 78, 19, 46, 51, 70, 91, 75, 87, 52, 4, 29, 6, 41, 50, 37, 12, 39, 94, 33, 59, 72, 84, 92, 25, 9, 44, 0, 93, 97, 31, 35, 95, 22, 42, 86, 74, 36, 18, 40, 76, 14, 5, 8, 28, 54, 48, 3, 98, 30, 79, 43, 21, 2), NULL);
	}
}

void	test_sort_three(int active)
{
	int			count;

	count = 0;
	if (active > 0)
	{
		fun_group_start("SORT TINY SHORT (3 elements)");
		do_sort_work("--- test_sort_three", ++count,
			build_test_list(1, 3, 4, 1, 3), NULL);
		do_sort_work("--- test_sort_three", ++count,
			build_test_list(1, 3, 1, 4, 3), NULL);
		do_sort_work("--- test_sort_three", ++count,
			build_test_list(1, 3, 3, 1, 4), NULL);
		do_sort_work("--- test_sort_three", ++count,
			build_test_list(1, 3, 13, 1, 40), NULL);
		do_sort_work("--- test_sort_three", ++count,
			build_test_list(1, 3, 4, 67, 3), NULL);
		do_sort_work("--- test_sort_three", ++count,
			build_test_list(1, 3, 3, 67, 4), NULL);
		do_sort_work("--- test_sort_three", ++count,
			build_test_list(1, 3, -3, -7, 4), NULL);
	}
}

void	test_sort_four(int active)
{
	int	count;

	count = 0;
	if (active > 0)
	{
		fun_group_start("SORT MEDIUM SHORT (4 elements)");
		do_sort_work("--- test_sort_four", ++count,
			build_test_list(1, 4, 1, 3, 8, 2), NULL);
		do_sort_work("--- test_sort_four", ++count,
			build_test_list(1, 4, 4, 3, 7, 9), NULL);
		do_sort_work("--- test_sort_four", ++count,
			build_test_list(1, 4, 5, 12, 7, 9), NULL);
	}
}

static void	test_sort_five_0(int active)
{
	int	count;

	count = 0;
	if (active > 0)
	{
		fun_group_start("SORT MEDIUM SHORT (5 elements)");
		do_sort_work("--- test_sort_five", ++count, 
			build_test_list(1, 5, 4, 1, 3, 8, 2), NULL);
		do_sort_work("--- test_sort_five", ++count, 
			build_test_list(1, 5, 1, 4, 3, 7, 9), NULL);
		do_sort_work("--- test_sort_five", ++count, 
			build_test_list(1, 5, 2, 5, 12, 7, 9), NULL);
		do_sort_work("--- test_sort_five", ++count, 
			build_test_list(1, 5, 2, 4, 3, 5, 1), NULL);
	}
}

static void	test_sort_five_1(int active)
{
	int	count;

	count = 0;
	if (active > 0)
	{
		fun_group_start("SORT MEDIUM SHORT (5 elements)");
		do_sort_work("--- test_sort_five", ++count, 
			build_test_list(1, 5, 14, 36, 100, 3, 18), NULL);
		do_sort_work("--- test_sort_five", ++count, 
			build_test_list(1, 5, 12, 98, 46, 71, 16), NULL);
		do_sort_work("--- test_sort_five", ++count, 
			build_test_list(1, 5, 7, 1, 5, 87, 28), NULL);
	}
}

static void	test_sort_five_2(int active)
{
	int	count;

	count = 0;
	if (active > 0)
	{
		fun_group_start("SORT MEDIUM SHORT (5 elements)");
		do_sort_work("--- test_sort_five", ++count, 
			build_test_list(1, 5, 6, 59, 98, 33, 22), NULL);
		do_sort_work("--- test_sort_five", ++count, 
			build_test_list(1, 5, 69, 19, 70, 17, 1), NULL);
		do_sort_work("--- test_sort_five", ++count, 
			build_test_list(1, 5, 45, 49, 14, 1, 20), NULL);
	}
}

void	test_sort_five(int active)
{
	int	count;

	count = 0;
	if (active > 0)
	{
		fun_group_start("SORT MEDIUM SHORT (5 elements)");
		do_sort_work("--- test_sort_five", ++count, 
			build_test_list(1, 5, -26, 38, 13, 0, 31), NULL);
		do_sort_work("--- test_sort_five", ++count, 
			build_test_list(1, 5, 69, 19, 0, 17, 1), NULL);
		test_sort_five_0(0);
		test_sort_five_1(0);
		test_sort_five_2(0);
	}
}
