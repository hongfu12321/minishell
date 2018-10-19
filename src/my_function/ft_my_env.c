/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:35:31 by fhong             #+#    #+#             */
/*   Updated: 2018/10/19 04:51:57 by fuhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

_Bool	ft_my_env(char **para, t_minienv *envp)
{
	int i = -1;

	if (para[1])
	{
		ft_putstr("env: Too many arguments\n");
		return (0);
	}
	while (envp->env[++i])
		ft_printf("%s\n", envp->env[i]);
	return (1);
}
