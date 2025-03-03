/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation_swap.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/04 15:54:59 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list *lst)
{
	t_list	*aux;
	void	*test;

	printf("Swap: list size %d %p", ft_lstsize(lst), lst->content);
	ft_lstadd_back(&lst, aux);
	// ft_lstadd_back(&aux, lst->content);
	// int i = 0;
	while (lst)
	{
	//	ft_lstadd_back(&aux, lst->content);
		test = lst->content;
		printf("%s\n", (char *)test);
		lst = lst->next;
	}
	ft_utils_show_op_msg("sa");
}
