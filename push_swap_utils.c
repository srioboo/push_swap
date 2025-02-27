/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:24:03 by srioboo-          #+#    #+#             */
/*   Updated: 2025/02/28 11:10:23 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_show_error_msg(void)
{
	write(1, "Error\n", 7);
	return (0);
}

int	ft_is_str_a_number(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (ft_isalpha((int)s[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	validate_parameters(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 2)
		return (ft_is_str_a_number(argv[i]));
	else if (argc > 2)
	{
		while (argv[i] != NULL)
		{
			if (ft_is_str_a_number(argv[i]) == 1)
				return (1);
			i++;
		}
	}
	return (0);
}

int	process_parameters(char **params)
{
	int		i;
	t_list	*ls_num;

	i = 1;
	while (params[i] != NULL)
	{
		ft_lstadd_back(&ls_num, ft_lstnew(params[i]));
		i++;
	}
	// TODO - this is a test
	while (ls_num)
	{
		printf("%s\n", (char *)ls_num->content);
		ls_num = ls_num->next;
	}
	// TODO - this is the end of tests
	return (0);
}
