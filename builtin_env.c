/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 15:19:28 by gcadel            #+#    #+#             */
/*   Updated: 2015/10/08 17:36:13 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	sh_builtin_env_use(void)
{
	ft_putendl_fd("env: usage: [i] [name=value ...] [utility [arg ...]]", 2);
}

void	sh_print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}

void	sh_builtin_env_exec(char **av, char ***new_env, char ***env, int i)
{
	char	**array_path;
	char	*new_cmd;

	while (av[i] && ft_strchr(av[i], '='))
		i++;
	if (av[i])
	{
		new_cmd = ft_joinarray(&av[i]);
		array_path = sh_parse_env("PATH", *new_env);
		if (array_path == NULL)
			array_path = sh_parse_env("PATH", *env);
		if (av[i])
			sh_execute_cmd(new_cmd, new_env, array_path);
		if (array_path)
			ft_arrfree(&array_path);
	}
	else
		sh_print_env(*new_env);
}

void	sh_builtin_env(char **av, char ***env)
{
	int		i;
	char	**new_env;
	int		arg_len;

	if (!av || !env || !(*av))
		return ;
	i = 1;
	if (av[i] && ft_strcmp(av[i], "-help") == 0)
		return (sh_builtin_env_use());
	if (av[i] && ft_strcmp(av[i], "-i") == 0)
	{
		i = 2;
		arg_len = ft_arrlen(av);
		if (!(new_env = (char**)malloc(sizeof(char *) * (arg_len + 1))))
			return ;
		new_env[0] = NULL;
		arg_len = 0;
	}
	else
		new_env = ft_arrcpy(*env);
	if (av[i] || ft_strchr(av[i], '='))
		sh_builtin_setenv(av, &new_env);
	sh_builtin_env_exec(av, &new_env, env, i);
	if (new_env)
		ft_arrfree(&new_env);
}
