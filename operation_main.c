/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/05 12:32:27 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sort(t_link_list **list_a, t_link_list **list_b)
{
	// ft_printf("START SORTENING: list size %d %p", ft_lstsize(list_a), list_b);
	// log_lst_data(*list_a, "LIST_A: ");
	if (link_lstsize(*list_a) == 3)
		tiny_sort(list_a); // list_b = tiny_sort(list_a, list_b);
	else
		full_sort(list_a, list_b);// list_b = full_sort(list_a, list_b);


	// ft_printf("\n");
	// log_lst_data(*list_a, "LIST_A: ");
	// log_lst_data(*list_b, "LIST_B: ");
	// ft_printf("\n");

	// TODO - do ordering
	// return (list_a);
}

/*static void	full_sort_aux(t_link_list **list_a,
				t_link_list **list_b, int nb2)
{
	int	bits;
	int bit;
	// int	bit_a;
	//int	bit_b;
	// ft_printf("nb1 %d\n", nb1);

	bits = (sizeof(int) * 8) - 1;
	while (bits >= 0)
	{
		//bit_a = (nb1 >> bits) & 1;
		bit = (nb2 >> bits); 

		ft_printf("a:%d %d\n", bit, (bit & 1));

		if (bit & 0)
		{
			push_b(list_a, list_b);
			return ;
		}
		if (bit & 1)
		{
			rotate_a(list_a);
			return ;
		}
		bits--;
	}

}*/

void	full_sort(t_link_list **list_a, t_link_list **list_b)
{
	int	i;
	int	max_bits;
	int	size;
	int	j;
	int	max_val;

	max_val = (*list_a)->max_val;
	max_bits = 0;
	while ((max_val >> max_bits) != 0)
		max_bits++;
	// ft_printf("max bits %d\n", max_bits);
	i = 0;
	while (i < max_bits)
	{
		size = link_lstsize(*list_a);
		j = 0;
		while (j < size)
		{
			// current = *list_a;
			int num = (*list_a)->content;
			// ft_printf("i: %d, size: %d, j: %d, num: %d %d\n", i, size, j, num, (num >> i) & 1);
			if (((num >> i) & 1) == 0)
				push_b(list_a, list_b);
			else
				rotate_a(list_a);
			//if (size == link_lstsize(*list_a))
			//	*list_a = (*list_a)->next;
			j++;
		}
		//size = link_lstsize(*list_b);
		// ft_printf("size b %d\n", link_lstsize(*list_b));
		int s = link_lstsize(*list_b);
		int p = 0;
		while(p < s)
		{
			// ft_printf("test");
			push_a(list_b, list_a);
			p++;
		}
		i++;
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

/*
void	tiny_sort(t_link_list **list_a)
{
	if ((*list_a)->content == (*list_a)->max_val)
		op_rotate(list_a, OP_ROTATE_A);
	if ((*list_a)->next->content == (*list_a)->max_val)
		op_rev_rotate(list_a, OP_ROTATE_A);
	if (((*list_a)->content > (*list_a)->next->content))
		op_swap(list_a, OP_SWAP_A);
}
*/

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
		else if ((count == 0 && (list_b->content != list_b->max_val))
			&& (list_b->content < list_b->next->content))
		{
			swap_a(list_a);
			tiny_sort(list_a);
		}
		else if (count == 0 && (list_b->content > list_b->next->content))
			swap_a(list_a);
		list_b = list_b->next;
		count++;

	}
}
