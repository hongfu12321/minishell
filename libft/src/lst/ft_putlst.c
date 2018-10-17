/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 16:08:20 by fhong             #+#    #+#             */
/*   Updated: 2018/07/14 21:04:58 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_putlst(t_list *lst)
{
	while (lst)
	{
		ft_putstr(lst->content);
		ft_putstr("\n");
		lst = lst->next;
	}
}
