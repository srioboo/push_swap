/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_log.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/05 12:44:06 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	log_lst_data(t_link_list *lstest, char *label)
{
	int	count;

	ft_printf("\n%s ", label);
	if (lstest)
		ft_printf("elements(%d): \t", lstest->max_val);
	count = 0;
	while (lstest)
	{
		if (lstest->content)
			ft_printf("%d\t", lstest->content);
		lstest = lstest->next;
		count++;
	}
	ft_printf("size(%d)\n", count);
}
