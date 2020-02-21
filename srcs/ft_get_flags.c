/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 09:29:20 by afoulqui          #+#    #+#             */
/*   Updated: 2020/02/20 09:46:19 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_flag_width(char *str, t_flags *flags, va_list *list)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_find_index("123456789*", str[i]) != -1 && str[i - 1] != '.')
		{
			flags->width = 1;
			flags->nb_width = ft_find_nb(str, list);
		}
		i++;
	}
	if (flags->nb_width < 0)
	{
		flags->nb_width *= -1;
		flags->left = 1;
	}
}

int			ft_flag_zero(char *str)
{
	int		i;

	i = 0;
	if (str[0] == '0')
		return (1);
	while (str[i])
	{
		if (str[i] == '0' && (ft_find_index("0123456789.", str[i - 1]) == -1))
			return (1);
		i++;
	}
	return (0);
}

void		ft_reset_flags(t_flags *flags)
{
	flags->precision = 0;
	flags->left = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->nb_width = 0;
	flags->nb_precision = 0;
}

void		ft_init_flags(char *str, t_flags *flags, va_list *list)
{
	int		nb;
	int		i;

	ft_reset_flags(flags);
	if (ft_find_index(str, '-') != -1)
		flags->left = 1;
	if (ft_find_index(str, '.') != -1)
		flags->precision = 1;
	flags->zero = ft_flag_zero(str);
	ft_flag_width(str, flags, list);
	i = 0;
	while (str[i])
	{
		if (str[i] == '.'|| str[i] == '0')
		{
			nb = ft_find_nb(&str[i + 1], list);
			if (nb < 0)
				flags->precision = 0;
			else
				flags->nb_precision = nb;
		}
		i++;
	}
	if (flags->left == 1 || flags->precision == 1)
		flags->zero = 0;
}