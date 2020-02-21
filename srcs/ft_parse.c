/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:57:58 by afoulqui          #+#    #+#             */
/*   Updated: 2020/02/20 09:50:30 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_init_functions(int (*functions[]) (va_list *, t_flags *))
{
	functions[0] = ft_print_c;
	functions[1] = ft_print_s;
	functions[2] = ft_print_p;
	functions[3] = ft_print_d;
	functions[4] = ft_print_d;
	functions[5] = ft_print_u;
	functions[6] = ft_print_x;
	functions[7] = ft_print_x2;
}

int		ft_parse(char *str, va_list *list, int *i)
{
	int			(*functions[8]) (va_list *, t_flags *);
	t_flags		flags;
	char		*tmp;
	int			len;
	int			j;

	if (str[0] == '%')
	{
		write(1, "%%", 1);
		*i += 1;
		return (1);
	}
	j = ft_find_end(str, TYPE_FIELD);
	if ((j == -1) || !(tmp = ft_strndup(str, j + 1)))
		return (0);
	ft_init_functions(functions);
	ft_init_flags(tmp, &flags, list);
	len = (*functions[ft_find_index(TYPE_FIELD, tmp[j])])(list, &flags);
	*i += j + 1;
	free(tmp);
	return (len);
}
