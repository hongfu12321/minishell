/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 14:24:07 by fhong             #+#    #+#             */
/*   Updated: 2018/10/17 20:53:44 by fuhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include		<sys/types.h>
# include		<sys/wait.h>
# include		"../libft/includes/libft.h"

# define		SHELLNAME	"\033[1m\033[34mFush%\033[0m "
# define		FUNC_NUM	6

typedef _Bool	(*myfunc)(char **para, char **envp);

typedef struct	s_cmd_dispatch
{
	char		*name;
	char		*flag;
	myfunc		fct;
}				t_cmd_dispatch;

/*
** minishell.c
*/

t_cmd_dispatch	g_my_func[FUNC_NUM];

/*
** my_function
*/

//_Bool			ft_my_cd(char **para, char **envp);
_Bool			ft_my_exit(char **para, char **envp);
//_Bool			ft_my_echo(char **para, char **envp);
//_Bool			ft_my_env(char **para, char **envp);
//_Bool			ft_my_setenv(char **para, char **envp);
//_Bool			ft_my_unsetsev(char **para, char **envp);

#endif
