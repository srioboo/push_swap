/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:23:13 by srioboo-          #+#    #+#             */
/*   Updated: 2025/02/28 11:10:55 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "include/libft.h"

// TODO - delete - for testing only
# include <stdio.h>

/**
 * 
 */
int		process_parameters(char **params);

/**
 * @brief retrieve parameters and test if are numbers
 */
int		validate_parameters(int argc, char **argv);

/**
 * @brief test if a string is a number
 */
int		ft_is_str_a_number(char *s);

/**
 * @brief show error message
 */
int		ft_show_error_msg(void);

/**
 * @brief process list sortening
 */
void	*ft_sort(t_list new_list);

#endif