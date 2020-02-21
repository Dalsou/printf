/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:39:01 by afoulqui          #+#    #+#             */
/*   Updated: 2020/02/20 09:49:15 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_find_index(char *str, char element)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == element)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_find_end(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int		ft_find_nb(char *str, va_list *list)
{
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	if (str[i] == '-' )
		i++;
	if (str[i] == '*')
		nb = va_arg(*list, int);
	else if (ft_find_index("0123456789", str[i]) != -1)
	{
		while (str[i] && ft_find_index("0123456789", str[i]) != -1)
		{
			nb = nb * 10 + str[i] - '0';
			i++;
		}
	}
	return (nb);
}