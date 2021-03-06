/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 16:07:04 by rpagot            #+#    #+#             */
/*   Updated: 2016/11/18 16:07:10 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	return (((unsigned int)c > 0100 && (unsigned int)c < 0133) ||
			((unsigned int)c > 0140 && (unsigned int)c < 0173));
}
