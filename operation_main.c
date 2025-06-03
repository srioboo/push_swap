/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/03 15:19:33 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sort(t_link_list **list_a, t_link_list **list_b)
{
	// ft_printf("START SORTENING: list size %d %p", ft_lstsize(list_a), list_b);
	if (link_lstsize(*list_a) == 3)
		tiny_sort(list_a); // list_b = tiny_sort(list_a, list_b);
	else
		full_sort(list_a, list_b);// list_b = full_sort(list_a, list_b);

	// TODO - do ordering
	// return (list_a);
}

static void	full_sort_aux(t_link_list **list_a,
			t_link_list **list_b, int nb1, int nb2)
{
	int	bits;
	int	bit_a;
	int	bit_b;

	bits = (sizeof(int) * 8) - 1;
	while (bits >= 0)
	{
		bit_a = (nb1 >> bits) & 1;
		bit_b = (nb2 >> bits) & 1;
		if ((bit_a != bit_b) && (bit_a > bit_b))
		{
			// ft_printf("a: %d es mayor que %d\n", nb1, nb2);
			op_push(list_a, *list_b, OP_PUSH_B);
			return ;
		}
		if ((bit_a != bit_b) && (bit_a < bit_b))
		{
			// 	ft_printf("b: %d es menor que %d\n", nb1, nb2);
			op_rotate(list_a, OP_ROTATE_A);
			return ;
		}
		bits--;
	}
}

void	full_sort(t_link_list **list_a, t_link_list **list_b)
{
	int	count;
	// int	max;
	int	prev_nb;

	prev_nb = 0;
// 	max = (*list_a)->max_val;
	// ft_printf("TS MAX: %d \n", max);

	count = 0;
	while (*list_a)
	{
		if (count == 0)
			prev_nb = (*list_a)->content;
		else
		{
			full_sort_aux(list_a, list_b, prev_nb, (*list_a)->content);
			prev_nb = (*list_a)->content;
		}
		(*list_a) = (*list_a)->next;
		count++;
	}
}

/*t_link_list	*full_sort(t_link_list *lst, t_link_list *aux)
{
	int	count;
	int	max;

	// TODO - redo implementation
	max = lst->max_val;
	ft_printf("FS MAX: %d \n", max);
	count = 0;
	while (lst)
	{
		op_push(&lst, aux, OP_PUSH_B);
		// if (count == 0 && (lst->content == max))
		// 	aux = op_rotate(lst, OP_ROTATE_A);
		// else if (count == 0 && (lst->content != max))
		// {
		// 	aux = op_swap(lst, OP_SWAP_A);
		// 	aux = op_rotate(aux, OP_ROTATE_A);
		// }
		lst = lst->next;
		count++;
	}
	return (aux);
}*/



/*static t_link_list	*link_lstdup(t_link_list *lstest)
{
	int	count;
	t_link_list **aux;

	aux = link_lstnew(0);
	count = 0;
	while (lstest)
	{
		if (lstest->content)
			link_lstadd_back(&lstest, &aux);
		lstest = lstest->next;
		count++;
	}

	return (aux);
}*/


void	tiny_sort(t_link_list **list_a)
{
	int			count;
	t_link_list	*list_b;

	list_b = *list_a;
	count = 0;
	while (list_b)
	{
		if (count == 0 && (list_b->content == list_b->max_val))
		{
			op_rotate(list_a, OP_ROTATE_A);
			tiny_sort(list_a);
		}
		else if ((count == 0 && (list_b->content != list_b->max_val)) && (list_b->content < list_b->next->content))
		{
			op_swap(list_a, OP_SWAP_A);
			tiny_sort(list_a);
		}
		else if (count == 0 && (list_b->content > list_b->next->content))
			op_swap(list_a, OP_SWAP_A);
		list_b = list_b->next;
		count++;

	}
}

