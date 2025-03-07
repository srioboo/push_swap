/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:30:23 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/07 13:15:12 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static t_list	*build_test_list(int active_log)
{
	t_list	*lstest;

	lstest = NULL;
	ft_lstadd_back(&lstest, ft_lstnew("contenido1"));
	ft_lstadd_back(&lstest, ft_lstnew("contenido2"));
	ft_lstadd_back(&lstest, ft_lstnew("contenido3"));
	if (active_log > 0)
	{
		printf("list size %d\n", ft_lstsize(lstest));
		printf("contenido1\n");
		printf("contenido2\n");
		printf("contenido3\n\n");
	}
	return (lstest);
}

void	test_swap(int active)
{
	t_list	*lstest;

	lstest = NULL;
	if (active > 0)
	{
		fun_test_header_label(1, "--- test_swap");
		lstest = build_test_list(1);
		lstest = ft_swap_a(lstest);
		while (lstest)
		{
			if (lstest->content)
				printf("%s\n", (char *)(lstest->content));
			lstest = lstest->next;
		}
	}
}

void	test_push(int active)
{
	t_list	*lstest_a;
	t_list	*lstest_b;

	lstest_a = NULL;
	lstest_b = NULL;
	if (active > 0)
	{
		fun_test_header_label(1, "--- test_push");
		lstest_a = build_test_list(1);
		lstest_b = build_test_list(1);
		lstest_b = ft_push(lstest_a, lstest_b, OP_PUSH_A);
		printf("result size: %d\n", ft_lstsize(lstest_a));
		while (lstest_b)
		{
			if (lstest_b->content)
				printf("%s\n", (char *)(lstest_b->content));
			lstest_b = lstest_b->next;
		}
	}
}

void	test_rotate(int active)
{
	t_list	*lstest;

	lstest = NULL;
	if (active > 0)
	{
		fun_test_header_label(1, "--- test_rotate");
		lstest = build_test_list(1);
		lstest = ft_rotate(lstest, OP_ROTATE_A);
		while (lstest)
		{
			if (lstest->content)
				printf("%s\n", (char *)(lstest->content));
			lstest = lstest->next;
		}
	}
}

int	main(int argc, char **argv)
{
	if (!argc)
		printf("%d", argc);
	if (!argv)
		printf("%s", argv[0]);
	test_ft_dummy(1);
	test_swap(0);
	test_push(1);
	test_rotate(0);
}
