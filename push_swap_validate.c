/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_validate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:24:03 by srioboo-          #+#    #+#             */
/*   Updated: 2025/07/02 21:41:08 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_isnumber(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i] != 0 && s[i] != '\n')
	{
		if (ft_isdigit((int)s[i]) == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	validate_isrepeated(char *s, t_link_list *lst)
{
	int	num_a;

	num_a = ft_atol(s);
	if (lst != NULL)
	{
		while (lst)
		{
			if (num_a == lst->content)
				return (TRUE);
			lst = lst->next;
		}
	}
	return (FALSE);
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
