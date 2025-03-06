/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:30:23 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/07 11:13:04 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_swap(int active)
{
	t_list	*lstest;

	lstest = NULL;
	if (active > 0)
	{
		fun_test_header_label(1, "--- listadd_back");
		ft_lstadd_back(&lstest, ft_lstnew("contenido1"));
		ft_lstadd_back(&lstest, ft_lstnew("contenido2"));
		ft_lstadd_back(&lstest, ft_lstnew("contenido3"));
		printf("list size %d\n", ft_lstsize(lstest));
		printf("contenido1\n");
		printf("contenido2\n");
		printf("contenido3\n");
		lstest = ft_swap_a(lstest);
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
	test_swap(1);
}
