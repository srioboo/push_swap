/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:23:19 by srioboo-          #+#    #+#             */
/*   Updated: 2025/06/05 23:29:56 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link_list	*process_parameters(int argc, char **argv)
{
	int			pos;
	int			index;
	t_link_list	*ls_num;

	pos = 1;
	index = 0;
	ls_num = NULL;
	if (argc >= 2)
	{
		if (argc == 2)
		{
			argv = ft_split(argv[1], ' ');
			pos = 0;
		}
		while (argv[pos] != NULL)
		{
			if (validate_isnumber(argv[pos]) == FALSE
				|| validate_isrepeated(argv[pos], ls_num) == TRUE)
				return (NULL);
			else
				link_lstadd_back(&ls_num, link_lstnew(ft_atoi(argv[pos])));
			pos++;
		}
	}
	return (ls_num);
}

int	main(int argc, char **argv)
{
	t_link_list	*ls_num;
	t_link_list	*ls_aux;

	if (argc <= 1)
		return (show_error_msg());
	else
	{
		ls_num = process_parameters(argc, argv);
		if (ls_num != NULL)
			op_sort(&ls_num, &ls_aux);
		else
			return (show_error_msg());
	}
	return (0);
}
