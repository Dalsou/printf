/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:44:31 by afoulqui          #+#    #+#             */
/*   Updated: 2020/02/26 17:41:12 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnstr(char *str, int n)
{
	int		i;

	i = 0;
	while (str[i] && i < n)
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_find_strlen(char *str, t_flags *flags)
{
	int		len;

	len = ft_strlen(str);
	if (flags->precision == 1 && flags->nb_precision < ft_strlen(str))
		len = flags->nb_precision;
	return (len);
}

int		ft_print_s(va_list *args, t_flags *flags)
{
	char	*str;
	int		width;
	int		len;

	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	width = 0;
	len = ft_find_strlen(str, flags);
	if (flags->left == 1)
		ft_putnstr(str, len);
	if (flags->width == 1 && flags->nb_width > len)
	{
		ft_putnchar(' ', flags->nb_width - len);
		width = flags->nb_width - len;
	}
	if (flags->left == 0)
		ft_putnstr(str, len);
	return (len + width);
}
