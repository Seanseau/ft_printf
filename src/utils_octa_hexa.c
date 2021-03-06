/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_octa_hexa.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:23:07 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/15 16:03:34 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*dectoocta(unsigned long n, t_flags flags)
{
	char	*seg;
	int i;
	
	if (flags._h)
		n = (unsigned short)n;
	seg = ft_strnew(0);
	i = 0;
	while (n != 0)
	{
		seg[i] = 48 + (n % 8);
		n = n / 8;
		i++;
	}
	return (ft_strrev(seg));
}

void	ft_putstro(char *str, t_flags flags)
{
	int i;

	i = ft_strlen(str) - 11;
	if (flags._l)
		i = 0;
	if (flags._h == 1)
		i = ft_strlen(str) - 6;
	if (flags._h == 2)
		i = ft_strlen(str) - 3;
	if (i >= 0)
	{
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	if (i < 0)
		ft_putstr(str);
//	free(str);
	//ft_strdel(&str);
}

char	*dectohexa(long long n)
{
	char	*seg;
	int		i;
	int		tmp;

	seg = ft_strnew(0);
	i = 0;
	if (n == 0)
	{
		seg[i] = 48;
		return (seg);
	}
	while (n != 0)
	{
		tmp = n % 16;
		if (tmp < 10)
			seg[i] = tmp + 48;
		else
			seg[i] = tmp + 87;
		i++;
		n = n / 16;
	}
	return (ft_strrev(seg));
}

void	ft_putstrx(char *str, t_flags flags)
{
	int i;

	i = ft_strlen(str) - 8;
	if (flags._l == 1 || flags._l == 2)
		i = 0;
	if (flags._h == 1)
		i = ft_strlen(str) - 4;
	if (flags._h == 2)
		i = ft_strlen(str) - 2;
	if (i >= 0)
	{
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	if (i < 0)
		ft_putstr(str);
}

void	ft_puthash(t_flags flags)
{
	if (flags.flag > 96 && flags.flag < 123)
		ft_putstr("0x");
	else
		ft_putstr("0X");
}
