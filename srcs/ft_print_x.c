/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:32:58 by afoulqui          #+#    #+#             */
/*   Updated: 2020/02/06 10:42:12 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_u_to_hex(unsigned  int nb, char *base, t_flags *flags)
{
    int     len;
    int     zero;
    int     space;
    char    c;

    len = 0;
    zero = 0;
    space = 0;
    c = ' ';
    if (flags->zero == 1)
        c = '0';
    if (nb != 0 && flags->nb_precision != 0 && flags->precision == 0)
        len = ft_find_lenbase(nb, 16);
    if (flags->precision == 1 && flags->nb_precision > len)
        zero = flags->nb_precision - len;
    if (flags->width > len + zero)
        space = flags->width - (len + zero);
    if (flags->left == 0)
        ft_putnchar(c, space);
    ft_putnchar('0', zero);
    if (len > 0)
        ft_putnbr_base(nb, base);
    if (flags->left == 1)
        ft_putnchar(c, space);
    return (len + space + zero);
}

int     ft_print_x(va_list *args, t_flags *flags)
{
    long    nb;
    nb = va_arg(*args, unsigned int);
    return (ft_u_to_hex(nb, "0123456789abcdef", flags));
}

int     ft_print_x2(va_list *args, t_flags *flags)
{
    long    nb;
    nb = va_arg(*args, unsigned int);
    return (ft_u_to_hex(nb, "0123456789ABCDEF", flags));
}