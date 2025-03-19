/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:30:23 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/19 17:26:16 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdarg.h>

void	show_lst_data(t_link_list *lstest)
{
	int	count;
	printf("\n\n" COLOR_YELLOW "==== list content ===" COLOR_RESET " \n");
	printf("\nelements: \n");
	count = 0;
	while (lstest)
	{
		if (lstest->content)
			printf("[%d] %d\t", lstest->index, lstest->content);
		lstest = lstest->next;
		count++;
	}
	printf("\nsize: %d\n", count);
	printf("\n" COLOR_YELLOW "==== list content end ===" COLOR_RESET "\n\n");
}

t_link_list	*build_test_list(int active_log, int n_elem_lst, ...)
{
	t_link_list	*lstest;
	va_list		args;
	int			aux;

	va_start(args, n_elem_lst);
	lstest = NULL;
	aux = 0;
	printf(COLOR_BLUE "\nelements: \n");
	while (n_elem_lst > 0)
	{
		aux = va_arg(args, int);
		if(active_log > 0)
			printf("%d\t", aux);
		link_lstadd_back(&lstest, link_lstnew(aux));
		n_elem_lst--;
	}
	if (active_log > 0)
			printf(COLOR_BLUE "\nsize: %d\n", link_lstsize(lstest));
	printf(COLOR_GREEN "\n\noperations:\n");
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
	test_sort(0);
	test_sort_three(1);
	test_find_max(0);
}
