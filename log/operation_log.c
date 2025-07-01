/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_log.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/07/01 21:49:16 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	log_lst_data(t_link_list *lstest, char *label)
{
	int	count;

	ft_printf("\n%s ", label);
	if (lstest)
		ft_printf("elements(min:%d, max:%d): \t", lstest->min_val, lstest->max_val);
	count = 0;
	while (lstest)
	{
		if (lstest->content)
			ft_printf("%d:%d\t", lstest->content, lstest->index);
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

void	verify_normalization(t_link_list *lst)
{
	t_link_list *tmp = lst;
	ft_printf("=== Normalization Verification ===\n");
	while (tmp)
	{
		ft_printf("content: %d, index: %d, binary: ", tmp->content, tmp->index);
		for (int j = 2; j >= 0; j--)  // Solo 3 bits para ver mejor
			ft_printf("%d", (tmp->index >> j) & 1);
		ft_printf("\n");
		tmp = tmp->next;
	}
	ft_printf("==================================\n");
}

void	debug_print_list(t_link_list *lst, char *name)
{
	t_link_list	*tmp = lst;

	ft_printf("=== %s ===\n", name);
	while (tmp)
	{
		ft_printf("content: %d, index: %d\n", tmp->content, tmp->index);
		tmp = tmp->next;
	}
	ft_printf("==========\n");
}
