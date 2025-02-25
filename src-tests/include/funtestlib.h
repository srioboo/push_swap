/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funtestlib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:31:43 by srioboo-          #+#    #+#             */
/*   Updated: 2025/02/25 15:36:32 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNTESTLIB_H
# define FUNTESTLIB_H

# include <assert.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <limits.h>
# include <stdarg.h>
// add libraries of the tested project
# include "../../push_swap.h"
# include "../../include/libft.h"

/** Constants **/
# define COLOR_RED "\033[0;31m"
# define COLOR_GREEN "\033[0;32m"
# define COLOR_WHITE "\033[0;37m"
# define COLOR_RESET "\033[0m"

/** Base functions */

/**
 * @brief print message at the start of the method
 *
 * @details It helps to know which method are executing
 * @param method_message the message to show at the start
 */
void	fun_start(const char *method_message);

/**
 * @brief print message at the end of the method
 *
 * @details It helps to know which method are finishing
 * @param method_message the message to show at the end
 */
void	fun_end(const char *method_message);

void	fun_test_header(int num);
void	fun_test_header_label(int num, char *str);
char	*fun_red(void);
char	*fun_green(void);
char	*fun_white(void);

/** Utils functions */

/**
 * @brief allocate the memory to the string to use **deprectated**
 *
 * @details Its allocate the memory for a text given
 * @param text string for memory allocation
 * @return the text
 */
char	*fun_method_name(char *text);

/**
 * @brief free memory in string
 *
 * @details utility to proper
 * @param text the string to free
 * @return the given string to NULL
 */
char	*fun_free_str(char *text);

/** Show data functions */

/**
 * @brief print a formated string
 *
 * @details Given a message text, it prints a formated string
 * for visualization purposes
 * @param message string to show data
 * @return nothing
 */
void	fun_show_data(char **message);

/**
 * @brief print a formated string
 *
 * @details Given a message text and two functions,
 * it prints a formated string for visualization purposes
 * @param forig function origin to compare
 * @param fnew function new to compare agains forig
 * @param message string to show data
 * @return nothing
 */
void	fun_show_orig_new(int (*f1)(const char *),
			int (*f2)(const char *), const char *message);

/** Assertions functions */

/**
 * @brief assert that two numbers are equals
 *
 * @details given two integers test if the two integers are equals or not
 * and print the results
 * @param orig int origin
 * @param new int to test agais origin
 */
void	fun_assert_int(int orig, int new);

/**
 * @brief assert that two numbers are equals, but using functions from the lib
 *
 * @details given two functions test if the two integers are equals or not
 * and print the results, also give two parameters to the funcions, a string
 * and a integer to test
 * @param f_orig funtion origin to test
 * @param new funtion to test agais origin
 * @param str string to pass to the funcions
 * @param int integer to pass to the functios
 */
void	fun_assert_int_fun(int (*f_ori)(const char *str, ...),
			int (*f_new)(const char *str, ...), const char *str, ...);

#endif
