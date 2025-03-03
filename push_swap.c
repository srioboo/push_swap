/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:23:19 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/03 16:31:01 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process_parameters(char **params)
{
	int		i;
	t_list	*ls_num;

	i = 1;
	ls_num = ft_lstnew(0);
	while (params[i] != NULL)
	{
		ft_lstadd_back(&ls_num, ft_lstnew(params[i]));
		i++;
	}
	// TODO - this is a test
	// while (ls_num)
	// {
	//	printf("%s\n", (char *)ls_num->content);
	//	ls_num = ls_num->next;
	// }
	// TODO - this is the end of tests
	ft_swap(ls_num);
	return (0);
}

int	main(int argc, char **argv)
{
	int		is_number;

	if (argc <= 1)
		return (ft_utils_show_error_msg());
	else
	{
		is_number = ft_validate_parameters(argc, argv);
		if (is_number == 1)
			return (ft_utils_show_error_msg());
		else
			process_parameters(argv);
	}
	return (0);
}
