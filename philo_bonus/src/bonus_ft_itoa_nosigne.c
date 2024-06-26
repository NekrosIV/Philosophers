/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_nosigne.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:09:01 by kasingh           #+#    #+#             */
/*   Updated: 2024/06/26 17:24:55 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

static int	ft_count_digit(long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (10);
	if (n < 0)
	{
		n = n * -1;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	*ft_new_str(char *result, long int n, int digit)
{
	int	i;

	i = digit;
	if (n < 0)
	{
		n = n * -1;
	}
	while (0 < i)
	{
		result[--i] = n % 10 + '0';
		n = n / 10;
	}
	result[digit] = '\0';
	return (result);
}

/* ft_itoa: Convertit un entier en chaîne de caractères */
char	*ft_itoa_nosigne(long int n)
{
	char	*result;
	int		digit;

	digit = ft_count_digit(n);
	result = malloc((digit + 1) * sizeof(char));
	if (result == 0)
		return (0);
	return (ft_new_str(result, n, digit));
}
