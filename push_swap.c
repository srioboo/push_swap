/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:23:19 by srioboo-          #+#    #+#             */
/*   Updated: 2025/02/28 11:07:45 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		is_number;

	if (argc <= 1)
		return (ft_show_error_msg());
	else
	{
		is_number = validate_parameters(argc, argv);
		if (is_number == 1)
			return (ft_show_error_msg());
		else
			process_parameters(argv);
	}
	return (0);
}
