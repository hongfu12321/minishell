/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 14:24:07 by fhong             #+#    #+#             */
/*   Updated: 2019/08/28 22:27:57 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <pwd.h>
# include <limits.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/includes/libft.h"

# define SHELLNAME	"\033[1m\033[34mFush%\033[0m "
# define FUNC_NUM	6
# define SET_ENV	0
# define CREATE_ENV	1

typedef struct	s_minienv
{
	char		**env;
}				t_minienv;

typedef struct	s_cmd_dispatch
{
	char		*name;
	char		*flag;
	_Bool		(*fct)(char **para, t_minienv *envp);
}				t_cmd_dispatch;

/*
** minishell.c
*/

t_cmd_dispatch	g_my_func[FUNC_NUM];

/*
** my_function
*/

_Bool			ft_my_exit(char **para, t_minienv *envp);
_Bool			ft_my_cd(char **para, t_minienv *envp);
_Bool			ft_my_echo(char **para, t_minienv *envp);
_Bool			ft_my_env(char **para, t_minienv *envp);
_Bool			ft_my_setenv(char **parse, t_minienv *envp);
_Bool			ft_my_unsetenv(char **parse, t_minienv *envp);

/*
** execute_cmd
*/

int				is_my_func(char **cmd);
_Bool			run_system_func(char **cmd, t_minienv *envp);
_Bool			run_builtin_func(char *cmd, t_minienv *envp, char **p, int ret);
void			run_cmd(char *cmd, t_minienv *envp);

/*
** handle_env.c
*/

int				search_env_index(char **envp, char *str);
char			*get_env_var(char **envp, char *str);

/*
** parse_cmd.c
*/

char			*parse_special_char(char *str, char **envp, char c);
char			**parse_cmd(char **envp, char *str);

#endif
