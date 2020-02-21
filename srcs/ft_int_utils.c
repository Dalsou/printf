/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:32:58 by afoulqui          #+#    #+#             */
/*   Updated: 2020/02/06 10:42:12 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_find_intlen(int nb)
{
    int             len;

    len = 0;
    if (nb == 0)
        return (1);
    if (nb < 0)
        len = 1;
    while (nb != 0)
    {
        nb /= 10;
        len++;
    }
    return (len);
}

int     ft_find_ulen(unsigned int nb)
{
    unsigned int    len;

    len = 0;
    if (nb == 0)
        return (1);
    while (nb != 0)
    {
        nb /= 10;
        len++;
    }
    return (len);
}

int     ft_find_lenbase(long nb, int base)
{
    int             len;

    len = 0;
    while (nb >= base)
    {
        nb = nb / len;
        len++;
    }
    return (len + 1);
}

void	ft_putnbr(int n)
{
	long            nbr;

	nbr = n;
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	if (nbr <= 9)
		ft_putchar(nbr + '0');
}

int		ft_putnbr_base(long n, char *base)
{
	int             base_len;

	base_len = ft_strlen(base);
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= base_len)
		ft_putnbr_base(n / base_len, base);
	ft_putchar(base[n % base_len]);
	return (1);
}