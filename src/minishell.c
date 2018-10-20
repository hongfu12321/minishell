/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:01:58 by fhong             #+#    #+#             */
/*   Updated: 2018/10/19 16:20:52 by fhong            ###   ########.fr       */
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

t_minienv		*init_env(char **envp)
{
	t_minienv	*new_env;
	int			len;

	len = 0;
	while (envp[len])
		len++;
	if (!(new_env = (t_minienv *)malloc(sizeof(t_minienv))))
		ft_exit("Initial env fuck up\n");
	new_env->env = (char **)malloc(sizeof(char *) * (len + 1));
	new_env->env[len] = NULL;
	while (envp[--len])
		new_env->env[len] = ft_strdup(envp[len]);
	return (new_env);
}

void			free_env(t_minienv *envp)
{
	ft_tablefree(envp->env);
	free(&envp);
}

int				main(int ac, char **av, char **envp)
{
	int			i;
	char		*line;
	char		**cmd;
	t_minienv	*mini_env;

	(ac != 1 && av[0]) ? ft_exit(NULL) : 0;
	mini_env = init_env(envp);
	ft_putstr("\033[1m\033[92mWelcome!\033[0m Make great code today\n");
	while (42)
	{
		ft_putstr(SHELLNAME);
		get_next_line(0, &line);
		if (*line)
		{
			cmd = ft_strsplit(line, ';');
			i = -1;
			envp = mini_env->env;
			while (cmd[++i])
				run_cmd(cmd[i], mini_env);
			ft_strdel(&line);
			ft_tablefree(cmd);
		}
		ft_strdel(&line);
	}
	free_env(mini_env);
}
