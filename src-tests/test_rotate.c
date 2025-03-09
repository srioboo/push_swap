/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:30:23 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/09 10:43:06 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_rotate(int active)
{
	t_list	*lstest;

	lstest = NULL;
	if (active > 0)
	{
		fun_test_header_label(1, "--- test_rotate");
		lstest = build_test_list(1, 3, 1, 2, 3);
		lstest = ft_rotate(lstest, OP_ROTATE_A);
		show_lst_data(lstest);
	}
}

void	test_rev_rotate(int active)
{
	t_list	*lstest;

	lstest = NULL;
	if (active > 0)
	{
		fun_test_header_label(1, "--- test_rotate");
		lstest = build_test_list(1, 3, 1, 2, 3);
		lstest = ft_rev_rotate(lstest, OP_REV_ROTATE_A);
		show_lst_data(lstest);
		// while (lstest)
		// {
		// 	if (lstest->content)
		// 		printf("%s\n", (char *)(lstest->content));
		// 	lstest = lstest->next;
		// }
	}
}
