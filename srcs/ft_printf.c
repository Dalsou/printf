/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:00:02 by afoulqui          #+#    #+#             */
/*   Updated: 2020/02/20 09:52:42 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_printf(const char *src, ...)
{
	va_list		list;
	char		*str;
	int			len;
	int			i;

	if (src == NULL || (str = ft_strdup(src)) == NULL)
		return (0);
	va_start(list, src);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			len += ft_parse(&str[i + 1], &list, &i);
		else
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	va_end(list);
	free(str);
	return (len);
}