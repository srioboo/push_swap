/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:23:19 by srioboo-          #+#    #+#             */
/*   Updated: 2025/02/26 17:25:44 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO - convert to operations
void	*do_something(t_list new_list)
{
	printf("list size %d", ft_lstsize(&new_list));
}

// process the parameters
void	process(t_list ls_numbers)
{
	t_list new_list;

	ft_lstiter(&ls_numbers, do_something(new_list));
}

int	main(int argc, char **argv)
{
	int is_number;
	t_list ls_numbers;

	if (argc <= 1)
		return (ft_show_error_msg());
	else
	{
		is_number = validate_parameters(argc, argv);
		if (is_number == 1)
			return (ft_show_error_msg());
		else
			process(ls_numbers);
	}		
	return (0);
}
