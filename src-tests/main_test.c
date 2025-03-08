/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:30:23 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/08 19:48:17 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdarg.h>

void	show_lst_data(t_list *lstest)
{
	printf("\n\n" COLOR_YELLOW "==== lst content ===" COLOR_RESET " \n");
	while (lstest)
	{
		if (lstest->content)
			printf("%s\t", (char *)(lstest->content));
		lstest = lstest->next;
	}
	printf("\n" COLOR_YELLOW "==== lst content end ===" COLOR_RESET "\n\n");
}

t_list *build_test_list(int active_log, int n_elem_lst, ...)
{
	t_list	*lstest;
	va_list	args;
	int		aux;

	va_start(args, n_elem_lst);
	lstest = NULL;
	aux = 0;
	while (n_elem_lst > 0)
	{
		aux = va_arg(args, int);
		if(active_log > 0)
			printf("%d\t", aux);
		ft_lstadd_back(&lstest, ft_lstnew(ft_itoa(aux)));
		n_elem_lst--;
	}
	if (active_log > 0)
		printf("list size: %d\n\n", ft_lstsize(lstest));
	va_end(args);
	return (lstest);
}

int	main(int argc, char **argv)
{
	if (!argc)
		printf("%d", argc);
	if (!argv)
		printf("%s", argv[0]);
	test_ft_dummy(1);
	test_swap(1);
	test_push(0);
	test_rotate(0);
	test_rev_rotate(0);
}
