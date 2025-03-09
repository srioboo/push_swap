/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_validate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:24:03 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/09 17:13:34 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_validate_isnumber(char *s)
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

int	ft_validate_isrepeated(char *s, t_list *lst)
{
	int	num_a;
	int num_b;

	num_a = ft_atoi(s);
	if (lst != NULL)
	{
		while (lst)
		{
			num_b = ft_atoi((char *)(lst->content));
			if (num_a == num_b)
				return (TRUE);
			lst = lst->next;
		}
	}
	return (FALSE);
}