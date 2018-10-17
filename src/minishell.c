/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:01:58 by fhong             #+#    #+#             */
/*   Updated: 2018/10/17 16:57:01 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char *envp[])
{
	int		stat_loc;
	char	*line;
	char	**command;
	pid_t	pid;
	
	(void)envp;
	if (ac != 1 && av[0])
		ft_exit (SHELLNAME);
	while(42)
	{
		ft_putstr(SHELLNAME);
		get_next_line(0, &line);
		command = ft_split(line, ' ');
		pid = fork();
		if (pid == 0)
		{
			if (command[0])
		}
		else
			waitpid(pid, &stat_loc, WUNTRACED);
	}
}
