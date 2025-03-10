/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_validate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:24:03 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/10 15:10:42 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_isnumber(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (ft_isalpha((int)s[i]) == 1)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	validate_isrepeated(char *s, t_list *lst)
{
	int	num_a;

	num_a = ft_atoi(s);
	if (lst != NULL)
	{
		while (lst)
		{
			if (num_a == ft_atoi((char *)(lst->content)))
				return (TRUE);
			lst = lst->next;
		}
	}
	return (FALSE);
}