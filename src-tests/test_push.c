/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:30:23 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/10 15:01:53 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_push(int active)
{
	t_list	*lstest_a;
	t_list	*lstest_b;

	lstest_a = NULL;
	lstest_b = NULL;
	if (active > 0)
	{
		fun_test_header_label(1, "--- test_push");
		lstest_a = build_test_list(1, 3, 1, 2, 3);
		lstest_b = build_test_list(1, 3, 1, 2, 3);
		lstest_b = op_push(lstest_a, lstest_b, OP_PUSH_A);
		printf("result size: %d\n", ft_lstsize(lstest_a));
		show_lst_data(lstest_b);
	}
}
