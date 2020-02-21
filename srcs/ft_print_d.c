/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:32:58 by afoulqui          #+#    #+#             */
/*   Updated: 2020/02/06 10:42:12 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_get_space(t_flags *flags, int len)
{
	int		space;

	space = 0;
	if (flags->nb_width < len)
		space = flags->nb_width - len;
	return (space);
}

int		ft_get_zero(t_flags *flags, int *len, int nb)
{
	int		zero;

	zero = 0;
	if (flags->zero == 0)
		return (0);
	if (flags->precision == 0 && nb == 0)
	{
		*len = 0;
		return (0);
	}
	if (flags->nb_precision > *len)
		zero = flags->nb_precision - *len;
	return (zero);
}

int		ft_print_d(va_list *args, t_flags *flags)
{
	int     nb;
	int 	len;
	int		zero;
	int		space;

	nb = (long)va_arg(*args, int);
	len = ft_find_intlen(nb);
	zero = ft_get_zero(flags, &len, nb);
	space = ft_get_space(flags, len + zero);
	if (flags->zero == 0 || flags->left == 0)
		ft_putnchar(' ', space);
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	ft_putnchar('0', (flags->zero) ? zero : space);
	if (len > 0)
		ft_putnbr(nb);
	if (flags->left == 1)
		ft_putnchar(' ', space);
	return (len + zero + space);
}