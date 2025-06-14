/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:30:23 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/14 10:40:16 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdarg.h>

void	show_lst_data_with_label(t_link_list *lstest, char *label)
{
	int	count;

	printf("" COLOR_YELLOW "%s" COLOR_RESET "", label);
	if (lstest)
		printf("\nelements(%d, %d): \t", lstest->min_val, lstest->max_val);
	else
		printf("\n" COLOR_RED "Error lstest null or empty: %p" COLOR_RESET "\n",
			lstest);
	count = 0;
	while (lstest)
	{
		printf("%d\t", lstest->content);
		lstest = lstest->next;
		count++;
	}
	printf("\nsize: %d\n", count);
	printf("\n\n");
}

void	show_lst_data(t_link_list *lstest)
{
	show_lst_data_with_label(lstest, "");
}

t_link_list	*build_test_list(int active_log, int n_elem_lst, ...)
{
	t_link_list	*lstest;
	va_list		args;
	int			aux;

	va_start(args, n_elem_lst);
	lstest = NULL;
	aux = 0;
	printf(COLOR_BLUE "\nelements: \t");
	while (n_elem_lst > 0)
	{
		aux = va_arg(args, int);
		if (active_log > 0)
			printf("%d\t", aux);
		link_lstadd_back(&lstest, link_lstnew(aux));
		n_elem_lst--;
	}
	if (active_log > 0)
		printf(COLOR_BLUE "\nsize: %d max: %d\n",
			link_lstsize(lstest), lstest->max_val);
	printf(COLOR_GREEN "\n\noperations:\t\n");
	va_end(args);
	return (lstest);
}

int	main(int argc, char **argv)
{
	if (!argc)
		printf("%d", argc);
	if (!argv)
		printf("%s", argv[0]);
	test_ft_dummy(0);
	test_swap(0);
	test_push(0);
	test_rotate(0);
	test_rev_rotate(0);
	test_rotate_both(0);
	test_sort(0);
	test_sort_three(0);
	test_sort_four(0);
	test_sort_five(1);
	test_sort_five_1(1);
	test_sort_five_2(1);
	test_full_sort(0);
}
