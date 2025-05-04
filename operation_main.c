/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/04 23:02:17 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link_list	*op_sort(t_link_list *list_a, t_link_list *list_b)
{
	// ft_printf("START SORTENING: list size %d %p", ft_lstsize(list_a), list_b);
	if (link_lstsize(list_a) == 3)
		tiny_sort(&list_a); // list_b = tiny_sort(list_a, list_b);
	else
		full_sort(&list_a, &list_b);// list_b = full_sort(list_a, list_b);

	// TODO - do ordering
	return (list_a);
}

void	full_sort(t_link_list **list_a, t_link_list **list_b)
{
	int	count;
	int	max;
	int	nb1;
	int	nb2;
	int	i;

	nb1 = 0;
	nb2 = 0;
	max = (*list_a)->max_val;
	ft_printf("TS MAX: %d \n", max);

	int bits = sizeof(int) * 8;

	count = 0;
	while (*list_a)
	{
		if (count == 0)
			nb1 = (*list_a)->content;
		else
		{
			nb2 = (*list_a)->content;
			i = bits - 1;
			while (i >= 0) {
				int bit_a = (nb1 >> i) & 1;
				int bit_b = (nb2 >> i) & 1;

				if (bit_a != bit_b) {
					if (bit_a > bit_b) {
						ft_printf("a: %d es mayor que %d\n", nb1, nb2);
						op_push(list_a, *list_b, OP_PUSH_B);
					} else {
						ft_printf("b: %d es menor que %d\n", nb1, nb2);
						op_rotate(list_a, OP_ROTATE_A);
					}
					return;
				}
				// if (binary_compare(nb1, nb2) == 1)
				// {
				// 	ft_printf("%d es mayor que %d", nb1, nb2);
				// }

				i--;
			}
			nb1 = nb2;
		}


		// ft_printf("%d %d\n", (*lst)->content, (*lst)->max_val);
		/*if (count == 0 && ((*lst)->content == (*lst)->max_val))
		{
			ft_printf("here 0\t");
			op_rotate(lst, OP_ROTATE_A);
		}
		else if (count == 0 && ((*lst)->content != (*lst)->max_val))
		{
			ft_printf("here 1\t");
			op_swap(lst, OP_SWAP_A);
			op_rotate(lst, OP_ROTATE_A);
		}*/
		//ft_printf("HEE %p\t", (*lst)->next);
		(*list_a) = (*list_a)->next;
		// ft_printf("HEE 2\n");
		count++;
	}
	// ft_printf("TESSSSS");

	// aux = lst;
	// ft_printf("LS AUX: %p \n", aux);
	// return (aux);
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

void	tiny_sort(t_link_list **list_a)
{
	int			count;
	t_link_list	*list_b;

	list_b = *list_a;
	count = 0;
	while (list_b)
	{
		if (count == 0 && (list_b->content == list_b->max_val))
			op_rotate(list_a, OP_ROTATE_A);
		else if (count == 0 && (list_b->content != list_b->max_val))
		{
			ft_printf("TODO - Swap not implemented correctly?");
			op_swap(&list_b, OP_SWAP_A);
			// op_rotate(&list_b, OP_ROTATE_A);
		}
		list_b = list_b->next;
		count++;
	}
}
