/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:32:58 by afoulqui          #+#    #+#             */
/*   Updated: 2020/02/20 09:47:30 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_print_c(va_list *args, t_flags *flags)
{
	int c;
	int len;

	c = va_arg(*args, int);
	len = 0;
	if (flags->width == 1)
	{
		len = flags->nb_width;
		if (flags->left == 1)
		{
			ft_putchar(c);
			ft_putnchar(' ', flags->nb_width - 1);
		}
		else
		{
			ft_putnchar(' ', flags->nb_width - 1);
			ft_putchar(c);
		}
	}
	else
	{
		len = 1;
		ft_putchar(c);
	}
	return (len);
}