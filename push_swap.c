/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:23:19 by srioboo-          #+#    #+#             */
/*   Updated: 2025/07/05 10:57:57 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

t_link_list	*prepare_list(int pos, char **argv, t_link_list	**ls_num)
{
	while (argv[pos])
	{
		if (validate_isnumber(argv[pos]) == FALSE
			|| validate_isrepeated(argv[pos], *ls_num) == TRUE)
		{
			link_lstclear(ls_num);
			return (NULL);
		}
		else
			link_lstadd_back(ls_num, link_lstnew(ft_atol(argv[pos])));
		pos++;
	}
	// ft_free(argv);
	return (*ls_num);
}

t_link_list	*process_parameters(int argc, char **argv)
{
	int			pos;
	int			index;
	t_link_list	*ls_num;

	pos = 1;
	index = 0;
	ls_num = NULL;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (ft_arrsize(argv) < 1)
			return (NULL);
		pos = 0;
		ls_num = prepare_list(pos, argv, &ls_num);
		ft_free(argv);
		return (ls_num);
	}
	if (argc > 2)
		ls_num = prepare_list(pos, argv, &ls_num);
	return (ls_num);
}

int	main(int argc, char **argv)
{
	t_link_list	*ls_num;
	t_link_list	*ls_aux;

	ls_aux = NULL;
	if (argc == 1 || ft_strncmp(argv[1], "", 2) == 0)
		return (0);
	if (argc < 1)
		return (show_error_msg());
	else
	{
		ls_num = process_parameters(argc, argv);
		if (ls_num != NULL)
		{
			if (is_list_sorted(&ls_num) == TRUE)
			{
				link_lstclear(&ls_num);
				return (0);
			}
			else if (link_lstsize(ls_num) == 1
				&& ft_isdigit(ls_num->content) == TRUE)
			{
				link_lstclear(&ls_num);
				return (0);
			}
			op_sort(&ls_num, &ls_aux);
			link_lstclear(&ls_num);
			link_lstclear(&ls_aux);
		}
		else
			return (show_error_msg());
	}
	return (0);
}
