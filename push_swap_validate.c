/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_validate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:24:03 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/03 10:09:37 by srioboo-         ###   ########.fr       */
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
			return (1);
		i++;
	}
	return (0);
}

int	ft_validate_parameters(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 2)
		return (ft_validate_isnumber(argv[i]));
	else if (argc > 2)
	{
		while (argv[i] != NULL)
		{
			if (ft_validate_isnumber(argv[i]) == 1)
				return (1);
			i++;
		}
	}
	return (0);
}
