/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:01:58 by fhong             #+#    #+#             */
/*   Updated: 2018/10/18 22:55:20 by fuhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd_dispatch	g_my_func[FUNC_NUM] = 
{
	{"exit", NULL, &ft_my_exit},
	{"cd", NULL, &ft_my_cd},
	{"echo", "n", &ft_my_echo},
	{"env", "iPSuv", &ft_my_env},
	{"setenv", NULL, NULL},
	{"unsetenv", NULL, NULL}
};

int				main(int ac, char **av, char **envp)
{
	int		i;
	char	*line;
	char	**cmd;

	if (ac != 1 && av[0])
		ft_exit (NULL);
	envp = create_env(envp, NULL, CREATE_ENV);
	while(42)
	{
		ft_putstr(SHELLNAME);
		get_next_line(0, &line);
		if (*line)
		{
			cmd = ft_strsplit(line, ';');
			i = -1;
			while (cmd[++i])
				run_cmd(cmd[i], envp);
			ft_strdel(&line);
			ft_tablefree(cmd);
		}
		ft_strdel(&line);
	}
	ft_tablefree(envp);
}
