/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:31:54 by cmarques          #+#    #+#             */
/*   Updated: 2026/02/11 17:46:51 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_STR
# define FT_STOCK_STR
typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}			t_stock_str;
#endif