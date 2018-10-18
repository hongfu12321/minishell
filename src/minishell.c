/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:01:58 by fhong             #+#    #+#             */
/*   Updated: 2018/10/18 12:50:27 by fuhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd_dispatch	g_my_func[FUNC_NUM] = 
{
	{"exit", NULL, &ft_my_exit},
	//	{"cd", NULL, &ft_my_cd},
	{"echo", "n", &ft_my_echo}
	//	{"env", "iPSuv", &ft_my_env},
	//	{"setenv", NULL, &ft_my_setenv},
	//	{"unsetenv", NULL, &ft_my_unsetenv},
};

int				is_my_func(char **cmd)
{
	int ret;

	ret = -1;
	while (++ret < 2)
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
	path_table = get_path(envp);
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
	//ft_strdel(&name);
	//free(path_table);
	return (result);
}

void			run_cmd(pid_t pid, char **cmd, char **envp)
{
	int		ret;
	int		stat_loc;
	_Bool	result;

	ret = -1;
	result = 0;
	if (pid == 0)
	{
		if ((ret = is_my_func(cmd)) != -1)
			result = g_my_func[ret].fct(cmd, envp);
		else
			result = run_system_func(cmd, envp);
	}
	else if (pid < 0)
		ft_exit("Fail to create new process");
	waitpid(pid, &stat_loc, WUNTRACED);
	if (pid == 0 && result == 0)
		exit(0);
	if (pid > 0 && !ft_strcmp(cmd[0], "exit"))
		ft_exit("\033[1m\033[33mHave a good day~\033[0m\n");
}

int				main(int ac, char **av, char *envp[])
{
	char	*line;
	char	**cmd;
	char	**newenv;
	pid_t	pid;

	newenv = envp;
	if (ac != 1 && av[0])
		ft_exit (NULL);
	while(42)
	{
		ft_putstr(SHELLNAME);
		get_next_line(0, &line);
		if (*line)
		{
			cmd = ft_strsplit(line, ' ');
			pid = fork();
			run_cmd(pid, cmd, newenv);
			ft_strdel(&line);
			ft_tablefree(cmd);
		}
		ft_strdel(&line);
	}
}
