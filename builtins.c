/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 15:20:11 by gcadel            #+#    #+#             */
/*   Updated: 2015/10/08 15:58:58 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		sh_bin_path(char **option, char **path, char ***env)
{
	int		i;
	char	*cmd;
	int		found;

	found = 0;
	i = 0;
	while (path[i])
	{
		if ((cmd = sh_search_bin(option[0], path[i])) != NULL)
		{
			fork_process(cmd, *env, option);
			ft_strdel(&cmd);
			found = 1;
		}
		i++;
	}
	return (found);
}

void	sh_notfound(char *av)
{
	char	*str;

	str = ft_strjoin("ft_minishell1: command not found: ", av);
	ft_putendl_fd(str, 2);
	ft_strdel(&str);
}

void	sh_builtin_exit(char **av)
{
	unsigned char val;

	val = 0;
	if (av && av[1])
	{
		if (ft_isdigit(av[1][0]))
			val = ft_atoi(av[1]);
		else
		{
			ft_putendl_fd("exit: Expression syntax.", 2);
			return ;
		}
	}
	exit(val);
}

int		sh_search_builtin2(char **option, char ***env, int state)
{
	if (ft_strcmp(option[0], "setenv") == 0)
	{
		sh_builtin_setenv(option, env);
		state = 1;
	}
	else if (ft_strcmp(option[0], "unsetenv") == 0)
	{
		sh_builtin_unsetenv(option, env);
		state = 1;
	}
	else if (ft_strcmp(option[0], "clear") == 0)
	{
		ft_putstr("\033[1;1H\033[2J]");
		state = 1;
	}
	else if (ft_strcmp(option[0], "env") == 0)
	{
		sh_builtin_env(option, env);
		state = 1;
	}
	return (state);
}

int		sh_search_builtin(char *av, char ***env)
{
	int		state;
	char	**option;

	if (!av || !env || !(*av))
		return (0);
	state = 0;
	option = ft_strsplit(av, ' ');
	if (option[0])
	{
		if (ft_strcmp(option[0], "cd") == 0)
		{
			sh_builtin_cd(option, env);
			state = 1;
		}
		else if (ft_strcmp(option[0], "exit") == 0)
		{
			sh_builtin_exit(option);
			state = 1;
		}
		else if (sh_search_builtin2(option, env, state))
			state = 1;
	}
	ft_arrfree(&option);
	return (state);
}
