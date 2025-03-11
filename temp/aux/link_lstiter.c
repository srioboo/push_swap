/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_lstiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 00:17:14 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/11 23:16:45 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstiter(t_link_list *lst, void (*f)(void *))
{
	t_link_list	*aux;

	aux = lst;
	while (aux)
	{
		f(aux->content);
		aux = aux->next;
	}
}
