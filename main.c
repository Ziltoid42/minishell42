/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 15:21:28 by gcadel            #+#    #+#             */
/*   Updated: 2015/10/08 17:12:06 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	sh_execute_cmd(char *line, char ***sh_env, char **path)
{
	char	**av;
	int		n;
	char	*nl;

	if (!(nl = ft_epur_tab(line)))
		nl = line;
	av = ft_strsplit(nl, ';');
	n = 0;
	if (nl)
		free(nl);
	while (av[n])
	{
		if (!sh_search_builtin(av[n], sh_env))
			sh_execute_bin(av[n], sh_env, path);
		n++;
	}
	if (av)
		ft_arrfree(&av);
}

void	fork_process(char *path, char **env, char **av)
{
	pid_t	father;
	int		stat_loc;

	father = fork();
	save_cpid(&father);
	if (father != -1)
	{
		if (father == 0)
		{
			if (execve(path, av, env) == -1)
				ft_putendl_fd("Permission denied", 2);
			exit(0);
		}
		else
			waitpid(father, &stat_loc, 0);
	}
	if (WIFSIGNALED(stat_loc))
		sh_wrong_exit(WTERMSIG(stat_loc), path);
	father = 0;
	save_cpid(&father);
}

void	sh_free_memory(char *line, char **path)
{
	if (line)
		ft_strdel(&line);
	if (path)
		ft_arrfree(&path);
}

void	sh_loop(char **env)
{
	char	**sh_env;
	char	**path;
	char	*line;

	path = NULL;
	line = NULL;
	sh_env = ft_arrcpy(env);
	while (42)
	{
		sh_save_env(&sh_env);
		sh_prompt(&sh_env);
		if (get_next_line(0, &line) <= 0)
			exit(0);
		path = sh_parse_env("PATH", sh_env);
		sh_execute_cmd(line, &sh_env, path);
		sh_free_memory(line, path);
	}
}

int		main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	sh_signals();
	sh_loop(env);
	return (0);
}
