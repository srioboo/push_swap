/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:23:13 by srioboo-          #+#    #+#             */
/*   Updated: 2025/07/06 20:04:39 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

# define FALSE 0
# define TRUE 1

# define OP_SWAP_A "sa"
# define OP_SWAP_B "sb"
# define OP_PUSH_A "pa"
# define OP_PUSH_B "pb"
# define OP_ROTATE_A "ra"
# define OP_ROTATE_B "rb"
# define OP_ROTATE_BOTH "rr"
# define OP_REV_ROTATE_A "rra"
# define OP_REV_ROTATE_B "rrb"
# define OP_REV_ROTATE_BOTH "rrr"

typedef struct s_link_list
{
	int					size;
	int					index;
	int					index_last;
	int					content;
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
 * @brief free memory from size
 */
void		link_lstclear(t_link_list **lst);

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

/**
 * @brief Validate integer limit
 */
int			validate_is_integer(char *s);

/**
 * @brief validate if is ordered
 */
int			is_list_sorted(t_link_list **ls);

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
 * @brief update min and max
 */
void		update_min_max(t_link_list *lst);

/**
 * @brief ascii to long
 */
long		ft_atol(const char *cton);

/**
 * @brief array size
 */
int			ft_arrsize(char **arr);

/* ************************************************************************** */
/* Operations Main                                                            */
/* ************************************************************************** */

/**
 * @brief Process list sortening
 * 
 * @param new_list list
 */
void		op_sort(t_link_list **new_list, t_link_list **aux_list);

/**
 * @brief do full sorting
 */
void		full_sort(t_link_list **list_a, t_link_list **list_b);

/**
 * @brief do sorting of a list of 3 elements
 */
void		tiny_sort(t_link_list **list_a, int list_size);

/**
 * @brief do sorting of a list of 5 elements
 */
void		medium_sort(t_link_list **list_a, t_link_list **list_b);

/**
 * @brief find the min position
 */
int			find_min_pos(t_link_list *a, int min_val);

/* ************************************************************************** */
/* Operations Push                                                            */
/* ************************************************************************** */

/**
 * @brief takes the first element on top on list b and puts in on list a
 * 
 * @param orig list
 * @param dest list
 */
void		push_to_a(t_link_list **orig, t_link_list **dest);

/**
 * @brief takes the first element on top on list a and puts in on list b
 * 
 * @param orig list
 * @param dest list
 */
void		push_to_b(t_link_list **orig, t_link_list **dest);

/* ************************************************************************** */
/* Operations Rotate                                                          */
/* ************************************************************************** */

/**
 * @brief swift elements one position, first element become last.
 * 
 * @param lst to rotate
 */
void		op_rotate(t_link_list **lst, char *op);

void		rotate_a(t_link_list **lst);
void		rotate_b(t_link_list **lst);

/**
 * @brief swift elements one position, first element become last, in both list
 */
void		rotate_both(t_link_list **lsta, t_link_list **lstb);

/* ************************************************************************** */
/* Operations Rev rotate                                                      */
/* ************************************************************************** */

/**
 * @brief swift elements one position, last element become first.
 * 
 * @param lst to rotate
 */
void		op_rev_rotate(t_link_list **lst, char *op);

void		rev_rotate_a(t_link_list **lst);
void		rev_rotate_b(t_link_list **lst);

/* ************************************************************************** */
/* Operations Swap                                                            */
/* ************************************************************************** */

/**
 * @brief swap the first 2 elements at the top of the stack a
 * 
 * @param lst to apply the change
 */
void		swap_a(t_link_list **lst);

/**
 * @brief swap the first 2 elements at the top of the stack b
 * 
 * @param lst to apply the change
 */
void		swap_b(t_link_list **lst);

/* ************************************************************************** */
/* Logs                                                                       */
/* ************************************************************************** */
void		log_lst_data(t_link_list *lstest, char *label);

/* ************************************************************************** */
/* Normalize                                                                  */
/* ************************************************************************** */
void		normalize_list(t_link_list *a);

#endif