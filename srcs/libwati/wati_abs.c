/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_abs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:03:13 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:38:24 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	wati_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	wati_abs_f(float nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	wati_abs_d(double nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}
