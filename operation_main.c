/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/29 10:36:29 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	normalize_list(t_link_list *a)
// {
// 	int			size = link_lstsize(a);
// 	int			*arr = malloc(sizeof(int) * size);
// 	t_link_list	*tmp = a;
// 	int			i = 0;
// 	int			j, k;

// 	// Copia los valores a un array
// 	while (tmp)
// 	{
// 		arr[i++] = tmp->content;
// 		tmp = tmp->next;
// 	}

// 	// Ordena el array (bubble sort con while)
// 	j = 0;
// 	while (j < size - 1)
// 	{
// 		k = j + 1;
// 		while (k < size)
// 		{
// 			if (arr[j] > arr[k])
// 			{
// 				int t = arr[j];
// 				arr[j] = arr[k];
// 				arr[k] = t;
// 			}
// 			k++;
// 		}
// 		j++;
// 	}

// 	// Reemplaza cada valor por su índice ordenado
// 	tmp = a;
// 	while (tmp)
// 	{
// 		i = 0;
// 		while (i < size)
// 		{
// 			if (tmp->content == arr[i])
// 			{
// 				tmp->content = i;
// 				break;
// 			}
// 			i++;
// 		}
// 		tmp = tmp->next;
// 	}
// 	free(arr);
// }

int	is_list_sorted(t_link_list **ls)
{
	t_link_list	*lst;

	lst = *ls;
	while (lst && lst->next)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	op_sort(t_link_list **a, t_link_list **b)
{
	int	list_size;

	list_size = link_lstsize(*a);
	if (list_size < 4)
		tiny_sort(a, list_size);
	else if (list_size == 4 || list_size == 5)
		medium_sort(a, b);
	else
	{
		// normalize_list(*a);
		full_sort(a, b);
	}
}

// static void	full_sort_stack_b(t_link_list **a, t_link_list **b,
// 		int b_size, int bit_size, int i)
// {
// 	unsigned int	binary_content;

// 	while (b_size-- && i <= bit_size && !is_list_sorted(b))
// 	{
// 		// binary_content = (*b)->content;
// 		binary_content = (((unsigned int)(*a)->content) ^ 0x80000000);
// 		if (((binary_content >> i) & 1) == 0)
// 			rotate_b(b);
// 		else
// 			push_to_a(b, a); // push("pa", s);
// 	}
// 	// log_lst_data(*b, "lista b");
// 	if (is_list_sorted(b))
// 		while (*b)
// 			push_to_a(b, a); //push("pa", s);
// }

void	full_sort(t_link_list **a, t_link_list **b)
{
	unsigned int	binary_content;
	int				i;
	int				bit_size;
	int				size;

	bit_size = 32; // calculate_max_bits((*a)->max_val, (*a)->min_val);
	// bit_size = 0;
	// size = link_lstsize(*a);
	// while (size > 1 && ++bit_size)
	// 	size /= 2;
	i = -1;
	while (++i < bit_size)
	{
		size = link_lstsize(*a);
		while (size-- && !is_list_sorted(a))
		{
			// binary_content = (*a)->content;
			binary_content = (((unsigned int)(*a)->content) ^ 0x80000000);
			if (((binary_content >> i) & 1) == 0)
				push_to_b(a, b);
			else
				rotate_a(a);
		}
		// full_sort_stack_b(a, b, link_lstsize(*b), bit_size, i + 1);
		while (*b)
			push_to_a(b, a);
	}
	// log_lst_data(*a, "lista a");
	while (*b)
		push_to_a(b, a);

}

void	tiny_sort(t_link_list **a, int list_size)
{
	int	max_val;

	update_min_max(*a);
	max_val = (*a)->max_val;
	// ft_printf("%d", max_val);
	while (is_list_sorted(a) == 0)
	{
		if (list_size == 2)
			swap_a(a);
		else if ((*a)->content == max_val)
			rotate_a(a);
		else if (((*a)->next->content) == max_val)
		{
			swap_a(a);
			rotate_a(a);
		}
		else if (((*a)->content) > ((*a)->next->content))
			swap_a(a);
	}
}

void	medium_sort(t_link_list **a, t_link_list **b)
{
	int		min_pos;

	while (link_lstsize(*a) > 3)
	{
		update_min_max(*a);
		min_pos = find_min_pos(*a, (*a)->min_val);
		// ft_printf("size: %d\n", (*a)->size);
		if (min_pos <= link_lstsize(*a) / 2)
			while ((*a)->content != (*a)->min_val)
				rotate_a(a);
		else
			while ((*a)->content != (*a)->min_val)
				rev_rotate_a(a);
		push_to_b(a, b);
	}
	tiny_sort(a, 3);
	while (*b)
		push_to_a(b, a);
}
