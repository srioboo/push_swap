/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/14 13:09:52 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_push(t_link_list **orig, t_link_list **dest, char *op)
{
	int			min;
	int			max;
	t_link_list	*aux;

	min = (*orig)->min_val;
	max = (*orig)->max_val;
	link_lstadd_front(dest, link_lstnew((*orig)->content));
	*orig = (*orig)->next;
	if (*orig != NULL)
	{
		aux = *orig;
		while (aux->next != NULL)
		{
			min = set_min(min, aux->next->content);
			aux = aux->next;
		}
		(*orig)->min_val = min;
		(*orig)->max_val = max;
	}
	show_op_msg(op);
}

void	push_to_a(t_link_list **orig, t_link_list **dest)
{
	op_push(orig, dest, OP_PUSH_A);
}

void	push_to_b(t_link_list **orig, t_link_list **dest)
{
	op_push(orig, dest, OP_PUSH_B);
}
