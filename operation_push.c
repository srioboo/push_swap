/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/07/01 19:59:20 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_push(t_link_list **orig, t_link_list **dest, char *op)
{
	//link_lstadd_front(dest, link_lstnew((*orig)->content));
	//*orig = (*orig)->next;
	t_link_list	*tmp;

    if (!*orig)
        return ;
    tmp = *orig;
    *orig = (*orig)->next;
    tmp->next = *dest;
    *dest = tmp;
	
	show_op_msg(op);
}

void	push_to_a(t_link_list **orig, t_link_list **dest)
{
	op_push(orig, dest, OP_PUSH_A);
	//update_min_max(*orig);
}

void	push_to_b(t_link_list **orig, t_link_list **dest)
{
	op_push(orig, dest, OP_PUSH_B);
	//update_min_max(*orig);
}

void	radix_push_to_a(t_link_list **orig, t_link_list **dest)
{
    op_push(orig, dest, OP_PUSH_A);
    // Sin actualizar min_max para preservar índices
}

void	radix_push_to_b(t_link_list **orig, t_link_list **dest)
{
    op_push(orig, dest, OP_PUSH_B);
    // Sin actualizar min_max para preservar índices
}