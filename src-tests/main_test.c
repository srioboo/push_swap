/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:30:23 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/04 15:33:21 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_swap(int active)
{
	t_list	*lstest;

	// lstest = ft_lstnew(0);
	if (active > 0)
	{
		fun_test_header_label(1, "--- listadd_back");
		ft_lstadd_back(&lstest, ft_lstnew("contenido1"));
		ft_lstadd_back(&lstest, ft_lstnew("contenido2"));
		ft_lstadd_back(&lstest, ft_lstnew("contenido3"));
		printf("list zize %d\n", ft_lstsize(lstest));
		ft_swap(lstest);
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
