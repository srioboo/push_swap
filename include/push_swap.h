/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:23:13 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/07 13:17:30 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "operations.h"
# include "../libft/src/libft.h"

// TODO - delete - for testing only
# include <stdio.h>

/**
 * @brief Process the parameters
 */
int		process_parameters(char **params);

/* ************************************************************************** */
/* Validate                                                                   */
/* ************************************************************************** */

/**
 * @brief Retrieve parameters and test if are numbers
 */
int		ft_validate_parameters(int argc, char **argv);

/**
 * @brief Test if a string is a number
 */
int		ft_validate_isnumber(char *s);

/* ************************************************************************** */
/* Utils                                                                      */
/* ************************************************************************** */

/**
 * @brief Show error message
 */
int		ft_utils_show_error_msg(void);

/**
 * @brief Show operation message in result
 */
void	ft_utils_show_op_msg(char *op);

/* ************************************************************************** */
/* Operations Main                                                            */
/* ************************************************************************** */

/**
 * @brief Process list sortening
 */
void	ft_sort(t_list *new_list);

/* ************************************************************************** */
/* Operations Push                                                            */
/* ************************************************************************** */

/**
 * @brief takes the first element on top on list a and puts in on list b
 * 
 * @param origin list
 * @param destination list
 * @return modify destination list
 */
t_list	*ft_push(t_list *orig, t_list *dest, char *op);

/* ************************************************************************** */
/* Operations Rotate                                                          */
/* ************************************************************************** */

/**
 * @brief swift elements one position, first element become last.
 * 
 * @param list to rotate
 * @return the result list
 */
t_list	*ft_rotate(t_list *lst, char *op);

/* ************************************************************************** */
/* Operations Rev rotate                                                      */
/* ************************************************************************** */

/**
 * @brief swift elements one position, last element become first.
 * 
 * @param list to rotate
 * @return the result list
 */
t_list	*ft_rev_rotate(t_list *lst, char *op);

/* ************************************************************************** */
/* Operations Swap                                                            */
/* ************************************************************************** */

/**
 * @brief swap the first 2 elements at the top of the stack a
 * 
 * @param list to apply the change
 * @return the new list
 */
t_list	*ft_swap_a(t_list *lst);

/**
 * @brief swap the first 2 elements at the top of the stack b
 * 
 * @param list to apply the change
 * @return the new list
 */
t_list	*ft_swap_b(t_list *lst);

#endif