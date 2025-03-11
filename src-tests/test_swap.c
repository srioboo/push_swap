/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:30:23 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/11 23:16:45 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_swap(int active)
{
	t_link_list	*lstest;

	lstest = NULL;
	if (active > 0)
	{
		fun_test_header_label(1, "--- test_swap");
		lstest = build_test_list(1, 3, 1, 2, 3);
		lstest = op_swap(lstest, OP_SWAP_A);
		show_lst_data(lstest);
	}
}
