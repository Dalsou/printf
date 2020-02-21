/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:44:31 by afoulqui          #+#    #+#             */
/*   Updated: 2020/02/20 09:51:36 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_find_strlen(char *str, t_flags *flags)
{
	int		len;

	len = ft_strlen(str);
	if (flags->precision == 1)
	{
		if (flags->nb_precision < ft_strlen(str))
			len = flags->nb_precision;
	}
	return (len);
}

int		ft_print_s(va_list *args, t_flags *flags)
{
	char	*str;
	int		len;

	str = va_arg(*args, char *);
	if (!str)
	{
		ft_putstr("(null)");
		return (ft_strlen("(null)"));
	}
	len = ft_find_strlen(str, flags);
	if (flags->left == 1)
		ft_putnstr(str, len);
	if (flags->width == 1)
	{
		ft_putnchar(' ', flags->nb_width - len);
		if (flags->nb_width > len)
			len = flags->nb_width;
	}
	if (flags->left == 0)
		ft_putnstr(str, len);
	return (len);
}