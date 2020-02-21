/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:44:31 by afoulqui          #+#    #+#             */
/*   Updated: 2020/02/20 09:51:36 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_get_zero_u(t_flags *flags, int *len, unsigned int nb)
{
	int		        zero;

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

int		ft_print_u(va_list *args, t_flags *flags)
{
	unsigned int    nb;
	int 	        len;
	int		        zero;
	int		        space;

	nb = (long)va_arg(*args, unsigned int);
	len = ft_find_intlen(nb);
	zero = ft_get_zero_u(flags, &len, nb);
	space = ft_get_space(flags, len + zero);
	if (flags->zero == 0 || flags->left == 0)
		ft_putnchar(' ', space);
	ft_putnchar('0', (flags->zero) ? zero : space);
	if (len > 0)
		ft_putnbr((int)nb);
	if (flags->left == 1)
		ft_putnchar(' ', space);
	return (len + zero + space);
}