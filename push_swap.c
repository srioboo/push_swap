/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:23:19 by srioboo-          #+#    #+#             */
/*   Updated: 2025/02/25 10:30:01 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// retrieve parameters and test if are numbers
void	validate_parameters(char **argv)
{
	printf("parameter validation %s\n", *argv);
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

	if (argc > 1 && argv[0])
	{
		c = 1;
		while (argv[c] != NULL)
		{
			validate_parameters(&argv[c]);
			process(argv[1]);
			c++;
		}
	}
	else
		return (1);
	return (0);
}
