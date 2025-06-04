/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:30:23 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/04 08:28:53 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_swap(int active)
{
	t_link_list	*lstest;

	lstest = NULL;
	if (active > 0)
	{
		fun_group_start("GROUP SWAP");
		fun_test_header_label(1, "--- test_swap");
		lstest = build_test_list(1, 3, 1, 2, 3);
		swap_a(&lstest);
		show_lst_data(lstest);
	}
}
