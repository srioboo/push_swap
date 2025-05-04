/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:23:13 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/04 23:03:50 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "operations.h"
# include "libft.h"
# include "ft_printf.h"

# define FALSE 0
# define TRUE 1

typedef struct s_link_list
{
	int					index;
	int					index_last;
	int					content;
	struct s_link_list	*prev;
	struct s_link_list	*next;
	int					max_val;
	int					min_val;
}	t_link_list;

/* ************************************************************************** */
/* link list                                                                  */
/* ************************************************************************** */

/**
 * @brief get last linked list element
 */
t_link_list	*link_lstlast(t_link_list *lst);

/**
 * @brief add new element to linked list back
 */
void		link_lstadd_back(t_link_list **lst, t_link_list *new_list);

/**
 * @brief add new element to linked list front
 */
void		link_lstadd_front(t_link_list **lst, t_link_list *new_list);

/**
 * @brief create new linked list from value
 */
t_link_list	*link_lstnew(int value);

/** 
 * @brief get list size
 * 
 * @param the list
 * @return list size
*/
int			link_lstsize(t_link_list *lst);

/**
 * @brief Retrieve parameters, test if valid and return list
 */
t_link_list	*process_parameters(int argc, char **argv);

/* ************************************************************************** */
/* Validate                                                                   */
/* ************************************************************************** */

/**
 * @brief Test if a string is a number
 */
int			validate_isnumber(char *s);

/**
 * @brief Test if the number already exists
 */
int			validate_isrepeated(char *s, t_link_list *lst);

/* ************************************************************************** */
/* Utils                                                                      */
/* ************************************************************************** */

/**
 * @brief Show error message
 */
int			show_error_msg(void);

/**
 * @brief Show operation message in result
 */
void		show_op_msg(char *op);

/**
 * @brief get an int len
 */
int			ft_intlen(int i);

/**
 * @brief find max value
 */
int			set_max(int nb1, int nb2);

/**
 * @brief compare two numbers by binary
 */
int			binary_compare(int nb1, int nb2);

/* ************************************************************************** */
/* Operations Main                                                            */
/* ************************************************************************** */

/**
 * @brief Process list sortening
 * 
 * @param new_list list
 */
t_link_list	*op_sort(t_link_list *new_list, t_link_list *aux_list);

/**
 * @brief do full sorting
 */
void		full_sort(t_link_list **list_a, t_link_list **list_b);

/**
 * @brief do sorting of a list of 3 elements
 */
void		tiny_sort(t_link_list **list_a);

/* ************************************************************************** */
/* Operations Push                                                            */
/* ************************************************************************** */

/**
 * @brief takes the first element on top on list a and puts in on list b
 * 
 * @param orig list
 * @param dest list
 */
void		op_push(t_link_list **orig, t_link_list *dest, char *op);

/* ************************************************************************** */
/* Operations Rotate                                                          */
/* ************************************************************************** */

/**
 * @brief swift elements one position, first element become last.
 * 
 * @param lst to rotate
 */
void		op_rotate(t_link_list **lst, char *op);

/**
 * @brief swift elements one position, first element become last, in both list
 */
void		op_rotate_both(t_link_list **lsta, t_link_list **lstb);

/* ************************************************************************** */
/* Operations Rev rotate                                                      */
/* ************************************************************************** */

/**
 * @brief swift elements one position, last element become first.
 * 
 * @param lst to rotate
 */
void		op_rev_rotate(t_link_list **lst, char *op);

/* ************************************************************************** */
/* Operations Swap                                                            */
/* ************************************************************************** */

/**
 * @brief swap the first 2 elements at the top of the stack
 * 
 * @param lst to apply the change
 * @param op operation to realice OP_SWAP_A or OP_SWAP_B
 */
void		op_swap(t_link_list **lst, char *op);

#endif