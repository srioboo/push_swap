/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/07/01 21:35:41 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	normalize_list(t_link_list *a)
{
	int			size;
	int			*values;
	t_link_list	*tmp;
	int			i;
	int			j;
	// int			k;
	int			temp;

	size = link_lstsize(a);
	values = malloc(sizeof(int) * size);
	if (!values)
		return ;
	
	// Copia los valores content (no index) a un array
	tmp = a;
	i = 0;
	while (tmp)
	{
		values[i++] = tmp->content;  // <-- content, no index
		tmp = tmp->next;
	}

	// Ordena el array usando bubble sort
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (values[j] > values[j + 1])
			{
				temp = values[j];
				values[j] = values[j + 1];
				values[j + 1] = temp;
			}
			j++;
		}
		i++;
	}

	// Asigna el índice normalizado a cada nodo
	tmp = a;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->content == values[i])
			{
				tmp->index = i;  // Asigna la posición en el array ordenado
				break;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(values);
}

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
		//debug_print_list(*a, "ANTES de normalizar");
		normalize_list(*a);
		//debug_print_list(*a, "DESPUÉS de normalizar");
		//verify_normalization(*a);  // Añade esta línea
		full_sort(a, b);
		//debug_print_list(*a, "DESPUÉS de full_sort");
	}
}

void	full_sort(t_link_list **a, t_link_list **b)
{
	//int	binary_content;
	int				i;
	int				bit_size;
	int				size;

	//bit_size = 32; // calculate_max_bits((*a)->max_val, (*a)->min_val);
	bit_size = 0;
	size = link_lstsize(*a);
	while ((1 << bit_size) < size)
		bit_size++;
	// while (size > 1 && ++bit_size)
	// 	size /= 2;


	// ft_printf("Starting radix sort with %d bits for %d elements\n", bit_size, size);
	// debug_print_list(*a, "Initial list");

	i = 0;
	while (i < bit_size)
	{
		// ft_printf("\n--- Processing bit %d ---\n", i);

		size = link_lstsize(*a);
		while (size-- > 0) // && !is_list_sorted(a))
		{
			if ((((*a)->index >> i) & 1) == 0)
			{
				// ft_printf("Element %d (index %d), bit %d = 0 -> push to B\n", 
				   // (*a)->content, (*a)->index, i);
				radix_push_to_b(a, b);
			}
			else
			{
				// ft_printf("Element %d (index %d), bit %d = 1 -> rotate A\n", 
				  //  (*a)->content, (*a)->index, i);
				rotate_a(a);
			}
		}
		// debug_print_list(*a, "Stack A (bit=1)");
		// debug_print_list(*b, "Stack B (bit=0)");
		
		// Segunda pasada: devuelve elementos de B a A
		while (*b)
		{
			//ft_printf("Returning %d (index %d) from B to A\n", 
			 //   (*b)->content, (*b)->index);
			radix_push_to_a(b, a);
		}
		
		// debug_print_list(*a, "Stack A after bit processing");
		i++;
	}
}

void	tiny_sort(t_link_list **a, int list_size)
{
	int	max_val;

	update_min_max(*a);
	max_val = (*a)->max_val;
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
