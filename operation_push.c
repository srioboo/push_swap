/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/29 09:14:21 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_push(t_link_list **orig, t_link_list **dest, char *op)
{
	link_lstadd_front(dest, link_lstnew((*orig)->content));
	*orig = (*orig)->next;
	show_op_msg(op);
}

void	push_to_a(t_link_list **orig, t_link_list **dest)
{
	op_push(orig, dest, OP_PUSH_A);
	update_min_max(*orig);
	// ft_printf("min/max %d/%d\n", (*orig)->min_val, (*orig)->max_val);
}

void	push_to_b(t_link_list **orig, t_link_list **dest)
{
	op_push(orig, dest, OP_PUSH_B);
	update_min_max(*orig);
	// ft_printf("min/max %d/%d\n", (*orig)->min_val, (*orig)->max_val);
}
