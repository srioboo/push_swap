/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/11 23:34:44 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sort(t_link_list *new_list, t_link_list *aux_list)
{
	// printf("START SORTENING: list size %d %p", ft_lstsize(new_list), aux_list);
	if (link_lstsize(new_list) == 3)
		tiny_short(new_list, aux_list);
	else
		printf("%p", aux_list);

	// printf("START SORTENING: list size %d %p", ft_lstsize(new_list), aux_list);
	// TODO - do ordering
}

void tiny_short(t_link_list *lst, t_link_list *aux)
{

	//int	nb_current;
	//int	nb_next;
	//int count;
	//int	max;

	// aux = lst; //link_lstnew(lst->content);
	//nb_current = 0;
	//nb_next = 0;
	//max = find_max(lst);
	//count = 0;
	// while (lst)
	// {
		//if (count == 0 && (lst->content == max))
//		printf("size before %d\n",link_lstsize(lst));
//t_link_list *aux;
//aux = NULL;
			aux = op_rotate(lst, OP_ROTATE_A);
			printf("size after %d\n",link_lstsize(aux));

		// if (lst->next && (lst->content != max))
		// 	nb_next = aux->next->content;
		// if ((lst->content != max) && nb_current > nb_next)
		// 	aux = op_swap(lst, OP_SWAP_A);
		//lst = lst->next;
		//count++;
	// }
	//lst = aux;
}

int	find_max(t_link_list *lst)
{
	int nb_current;
	int nb_next;
	int max;

	nb_current = 0;
	nb_next = 0;
	max = 0;

	while (lst)
	{
		if (lst->content)
			nb_current = lst->content;
		if (lst->next)
			nb_next = lst->next->content;
		if ((nb_current >= nb_next) && (nb_current > max))
			max = nb_current;
		lst = lst->next;
	}
	return (max);
}