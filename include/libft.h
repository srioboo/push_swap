/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:43:54 by srioboo-          #+#    #+#             */
/*   Updated: 2024/12/27 18:34:25 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

/**
 * @brief Check if is an alphabetic character
 *
 * @details Given a numeric value, it will check if this is a alphabetic
 * character, equivalent to ft_isalpha || ft_isdigit
 * @param num integer
 * @return (1) when c is an alphabetic value and (0) when it is not
 */
int		ft_isalpha(int num);

/**
 * @brief Give the string lenght
 *
 * @details Given a string, will return the lenght of this string
 * @param str with the string to treat
 * @return the string lenght
 */
size_t	ft_strlen(const char *str);

/**
 * @brief Transform a string representing a number to an integer
 *
 * @details Given a string of character it will return the integer found in the
 * string
 * @param nptr string representing a number to find th integer
 * @return return the integer
 */
int		ft_atoi(const char *nptr);

/**
 * @brief Split a string delimiting by the given char
 *
 * @details Split a string in substring using the given char as delimiter
 * @param s string to divide
 * @param c char used as delimiter
 * @return return an array of substring
 */
char	**ft_split(char const *s, char c);

/**
 * @brief Get a substring in a string from a position given
 *
 * @details Return a substring in the given string with a max lenght of len and
 * startin at the start given position
 * @param s the string to work with
 * @param start the start position of the substring
 * @param len lenght of the result string
 * @return return the substring
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Returns a pointer that is a duplicatate of the string s
 *
 * @details Returns a pointer that is a duplicatate of the string s
 * @param s string to duplicate
 * @return return the string duplicated
 */
char	*ft_strdup(const char *s);

#endif
