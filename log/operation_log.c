/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_log.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/15 18:34:12 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	log_lst_data(t_link_list *lstest, char *label)
{
	int	count;

	ft_printf("\n%s ", label);
	if (lstest)
		ft_printf("elements(%d, %d): \t", lstest->min_val, lstest->max_val);
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

void	print_binary_32(unsigned int number)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		ft_printf("%d", (number >> i) & 1);
		if (i % 8 == 0 && i != 0)
		{
			ft_printf(" ");
		}
		i--;
	}
	ft_printf("\n");
}
