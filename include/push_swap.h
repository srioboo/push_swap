/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:23:13 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/09 16:58:42 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "operations.h"
# include "../libft/src/libft.h"

// TODO - delete - for testing only
# include <stdio.h>

# define FALSE 0
# define TRUE 1

/**
 * @brief Retrieve parameters, test if valid and return list
 */
t_list *ft_process_parameters(int argc, char **argv);

/* ************************************************************************** */
/* Validate                                                                   */
/* ************************************************************************** */

/**
 * @brief Test if a string is a number
 */
int		ft_validate_isnumber(char *s);

/**
 * @brief Test if the number already exists
 */
int		ft_validate_isrepeated(char *s, t_list *lst);

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
 * 
 * @param new_list list
 */
void	ft_sort(t_list *new_list);

/* ************************************************************************** */
/* Operations Push                                                            */
/* ************************************************************************** */

/**
 * @brief takes the first element on top on list a and puts in on list b
 * 
 * @param orig list
 * @param dest list
 * @return modify destination list
 */
t_list	*ft_push(t_list *orig, t_list *dest, char *op);

/* ************************************************************************** */
/* Operations Rotate                                                          */
/* ************************************************************************** */

/**
 * @brief swift elements one position, first element become last.
 * 
 * @param lst to rotate
 * @return the result list
 */
t_list	*ft_rotate(t_list *lst, char *op);

/* ************************************************************************** */
/* Operations Rev rotate                                                      */
/* ************************************************************************** */

/**
 * @brief swift elements one position, last element become first.
 * 
 * @param lst to rotate
 * @return the result list
 */
t_list	*ft_rev_rotate(t_list *lst, char *op);

/* ************************************************************************** */
/* Operations Swap                                                            */
/* ************************************************************************** */

/**
 * @brief swap the first 2 elements at the top of the stack
 * 
 * @param lst to apply the change
 * @param op operation to realice OP_SWAP_A or OP_SWAP_B
 * @return the new list
 */
t_list	*ft_swap(t_list *lst, char *op);

#endif