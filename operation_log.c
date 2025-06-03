/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_log.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/03 09:50:27 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	log_lst_data(t_link_list *lstest, char *label)
{
	int	count;

	ft_printf("\n\n ==== list content %s === \n", label);
	if (lstest)
		ft_printf("\nelements: \tmax: %d\n", lstest->max_val);
	count = 0;
	while (lstest)
	{
		if (lstest->content)
			ft_printf("[%d] %d\t", lstest->index, lstest->content);
		lstest = lstest->next;
		count++;
	}
}

