/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:23:19 by srioboo-          #+#    #+#             */
/*   Updated: 2025/02/25 21:56:05 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_show_error()
{
	write(1, "Error\n", 7);
}

void ft_extract_numbers(char *str)
{
	printf("extract numbers from %s\n", str);
}

// retrieve parameters and test if are numbers
int	validate_parameters(char *argv)
{
	return (ft_atoi((const char *)argv));
}

// process the parameters
void	process(char const *s, ...)
{
	va_list	numbers;

	va_start(numbers, s);
	printf("number: %d\n", va_arg(numbers, int));
	printf("number: %d\n", va_arg(numbers, int));
	va_end(numbers);
}

int	main(int argc, char **argv)
{
	int	c;
	int is_number;

	if (argc > 2)
	{
		c = 1;
		while (argv[c] != NULL)
		{
			is_number = validate_parameters(argv[c]);
			// TODO - add to list and process
			// process(is_number);
			c++;
		}
	}
	if (argc == 2)
		ft_extract_numbers(argv[c]);
	else 
		ft_show_error();
	return (0);
}
