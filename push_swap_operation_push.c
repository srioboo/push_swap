/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation_push.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/07 12:34:54 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_push(t_list *orig, t_list *dest, char *op)
{
	ft_utils_show_op_msg(op);
	ft_lstadd_back(&dest, ft_lstnew(orig->content));
	// TODO - rotate to the first
	return (dest);
}
