/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 15:08:38 by fhong             #+#    #+#             */
/*   Updated: 2018/10/18 17:45:28 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				is_my_func(char **cmd)
{
	int ret;

	ret = -1;
	while (++ret < 4)
		if (ft_strcmp(cmd[0], g_my_func[ret].name) == 0)
			return (ret);
	return (-1);
}

char			**get_path(char **envp)
{
	int		i;
	char	**path;

	i = -1;
	path = NULL;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_strsplit(&envp[i][5], ':');
			break ;
		}
	}
	return (path);
}

_Bool			run_system_func(char **cmd, char**envp)
{
	int		i;
	char	**path_table;
	char	*path;
	char	*name;
	_Bool	result;

	result = 0;
	path_table = ft_strsplit(get_env_var(envp, "PATH"), ':');
	name = ft_strjoin("/", cmd[0]);
	i = 0;
	while (path_table[i++])
	{
		if (!path_table[i])
			path = cmd[0];
		else
			path = ft_strjoin(path_table[i], name);
		result = (execve(path, cmd, envp) == -1) ? 0 : 1;
		ft_strdel(&path);
	}
	ft_putstr("Command not found\n");
	free(path_table);
	return (result);
}

void			run_cmd(char *cmd, char **envp)
{
	int		ret;
	int		stat_loc;
	_Bool	result;
	char	**parse;
	pid_t	pid;

	ret = -1;
	result = 0;
	parse = ft_strsplit(cmd, ' ');
	if (*parse == NULL)
		return (ft_tablefree(parse));
	if ((ret = is_my_func(parse)) != -1)
		result = g_my_func[ret].fct(parse, envp);
	else
	{
		pid = fork();
		if (pid == 0)
		{
			result = run_system_func(parse, envp);
			exit(0);
		}
		else if (pid < 0)
			ft_exit("Fail to create new process");
		waitpid(pid, &stat_loc, WUNTRACED);
	}
	ft_tablefree(parse);
}
