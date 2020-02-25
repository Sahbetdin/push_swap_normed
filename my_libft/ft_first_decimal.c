/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:19:33 by btrifle           #+#    #+#             */
/*   Updated: 2019/09/25 18:25:04 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_first_decimal(int n)
{
	int dec;

	dec = 1;
	while (n > 9)
	{
		dec *= 10;
		n /= 10;
	}
	return (dec);
}
