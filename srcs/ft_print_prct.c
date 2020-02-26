/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_prct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:33:01 by afoulqui          #+#    #+#             */
/*   Updated: 2020/02/26 17:35:02 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_print_prct(va_list *args, t_flags *flags)
{
	int		zero;
	int		len;
	int		space;
	char	c;

	c = ' ';
	len = 1;
	zero = 0;
	space = 0;
	if (flags->zero == 1)
		c = '0';
	if (flags->nb_width > flags->nb_precision && flags->left == 0)
		zero = ft_get_zero_u(flags, &len, 1);
	space = ft_get_space(flags, len + zero);
	if (flags->left == 0)
		ft_putnchar(c, space);
	ft_putnchar(' ', zero);
	if (len > 0)
		ft_putchar('%');
	if (flags->left == 1)
		ft_putnchar(c, space);
	return (len + zero + space);
}
