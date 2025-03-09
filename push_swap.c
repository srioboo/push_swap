/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:23:19 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/09 17:14:29 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_process_parameters(int argc, char **argv)
{
	int i;
	static t_list *ls_num;

	i = 1;
	ls_num = NULL;
	if (argc >= 2)
	{
		while (argv[i] != NULL)
		{
			if (ft_validate_isnumber(argv[i]) == FALSE
				|| ft_validate_isrepeated(argv[i], ls_num) == TRUE)
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
	static t_list	*ls_num;

	if (argc <= 1)
		return (ft_utils_show_error_msg());
	else
	{
		ls_num = ft_process_parameters(argc, argv);
		if (ls_num != NULL)
			ft_sort(ls_num);
		else
			return (ft_utils_show_error_msg());
	}
	return (0);
}
