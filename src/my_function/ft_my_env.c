/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:35:31 by fhong             #+#    #+#             */
/*   Updated: 2018/10/18 17:47:31 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

_Bool	ft_my_env(char **para, char **envp)
{
	int i = -1;

	if (para[1])
	{
		ft_putstr("env: Too many arguments\n");
		return (0);
	}
	while (envp[++i])
		ft_printf("%s\n", envp[i]);
	return (1);
}
