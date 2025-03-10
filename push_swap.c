/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:23:19 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/10 15:33:12 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*process_parameters(int argc, char **argv)
{
	int			i;
	t_list		*ls_num;

	i = 1;
	ls_num = NULL;
	if (argc >= 2)
	{
		if (argc == 2)
			argv = ft_split(argv[1], ' ');
		while (argv[i] != NULL)
		{
			if (validate_isnumber(argv[i]) == FALSE
				|| validate_isrepeated(argv[i], ls_num) == TRUE)
			{
				// ft_lstclear(&ls_num); // TODO - clear list
				return (NULL);
			}
			else
				ft_lstadd_back(&ls_num, ft_lstnew(argv[i]));
			i++;
		}
	}
	else
		return (NULL);
	return (ls_num);
}

int	main(int argc, char **argv)
{
	t_list	*ls_num;
	t_list	*ls_aux;

	if (argc <= 1)
		return (show_error_msg());
	else
	{
		ls_num = process_parameters(argc, argv);
		if (ls_num != NULL)
			op_sort(ls_num, ls_aux);
		else
			return (show_error_msg());
	}
	return (0);
}
