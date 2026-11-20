/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhou <abouhou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 21:18:37 by abouhou           #+#    #+#             */
/*   Updated: 2026/11/20 16:09:38 by abouhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(char *nptr, int sign)
{
	int			i;
	long long	res;

	i = 0;
	res = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (res > (LLONG_MAX - nptr[i] - '0') / 10)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

int	ft_atoi(const char *nptr)
{
	int			sign;
	long long	res;

	res = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	return (ft_check(nptr, sign));
}
