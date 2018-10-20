/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 07:43:45 by fuhong            #+#    #+#             */
/*   Updated: 2018/10/19 16:18:48 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

_Bool	ft_my_echo(char **para, t_minienv *envp)
{
	_Bool	flag;
	int		i;

	(void)envp;
	i = 0;
	flag = 0;
	if (para[1] && !ft_strcmp(para[1], "-n"))
		flag = 1;
	while (para[++i])
	{
		(flag && i == 1) && i++;
		ft_putstr(para[i]);
		if (para[i + 1])
			ft_putchar(' ');
	}
	if (!flag)
		ft_putchar('\n');
	return (1);
}
