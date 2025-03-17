/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:23:13 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/11 23:31:04 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "operations.h"
# include "libft.h"

// TODO - delete - for testing only
# include <stdio.h>

#define FALSE 0
#define TRUE 1

typedef struct s_link_list
{
	int					index;
	int					index_last;
	int 				content;
	struct s_link_list	*prev;
	struct s_link_list	*next;
} t_link_list;

/* ************************************************************************** */
/* link list                                                                  */
/* ************************************************************************** */

t_link_list *link_lstlast(t_link_list *lst);
void		link_lstadd_back(t_link_list **lst, t_link_list *new);
t_link_list *link_lstnew(int value);
int			link_lstsize(t_link_list *lst);
void		link_lstadd_front(t_link_list **lst, t_link_list *new);

/**
 * @brief Retrieve parameters, test if valid and return list
 */
t_link_list *process_parameters(int argc, char **argv);

/* ************************************************************************** */
/* Validate                                                                   */
/* ************************************************************************** */

/**
 * @brief Test if a string is a number
 */
int		validate_isnumber(char *s);

/**
 * @brief Test if the number already exists
 */
int		validate_isrepeated(char *s, t_link_list *lst);

/* ************************************************************************** */
/* Utils                                                                      */
/* ************************************************************************** */

/**
 * @brief Show error message
 */
int		show_error_msg(void);

/**
 * @brief Show operation message in result
 */
void	show_op_msg(char *op);

/* ************************************************************************** */
/* Operations Main                                                            */
/* ************************************************************************** */

/**
 * @brief Process list sortening
 * 
 * @param new_list list
 */
void	op_sort(t_link_list *new_list, t_link_list *aux_list);

/**
 * @brief do sorting of a list of 3 elements
 */
void	tiny_short(t_link_list *lst, t_link_list *aux);

/**
 * @brief find de max value in a list
 */
int		find_max(t_link_list *lst);

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
t_link_list *op_push(t_link_list *orig, t_link_list *dest, char *op);

/* ************************************************************************** */
/* Operations Rotate                                                          */
/* ************************************************************************** */

/**
 * @brief swift elements one position, first element become last.
 * 
 * @param lst to rotate
 * @return the result list
 */
t_link_list *op_rotate(t_link_list *lst, char *op);

/* ************************************************************************** */
/* Operations Rev rotate                                                      */
/* ************************************************************************** */

/**
 * @brief swift elements one position, last element become first.
 * 
 * @param lst to rotate
 * @return the result list
 */
t_link_list *op_rev_rotate(t_link_list *lst, char *op);

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
t_link_list *op_swap(t_link_list *lst, char *op);

#endif