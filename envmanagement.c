/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envmanagement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 15:20:47 by gcadel            #+#    #+#             */
/*   Updated: 2015/10/07 16:25:17 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**sh_save_env(char ***env)
{
	char	**save;

	save = NULL;
	if (env && *env)
	{
		save = *env;
		return (NULL);
	}
	else
		return (save);
}

char	*sh_replace_home(char *path, char **env)
{
	char	*home_path;
	char	*pos;

	home_path = sh_get_env_part("HOME", env);
	if ((pos = ft_strstr(path, home_path)) && ft_strcmp("/", home_path) != 0)
	{
		path[0] = '~';
		path[1] = 0;
		ft_strcat(path, pos + ft_strlen(home_path));
	}
	return (path);
}

int		sh_get_env_pos(char *find, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(find, env[i], ft_strchr(env[i], '=') - env[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*sh_get_env_part(char *part, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(part, env[i], ft_strchr(env[i], '=') - env[i]) == 0)
			return (ft_strchr(env[i], '=') + 1);
		i++;
	}
	return (NULL);
}

char	**sh_parse_env(char *find, char **env)
{
	char	**array_path;
	char	*path;

	if ((path = sh_get_env_part(find, env)) == NULL)
		return (NULL);
	array_path = ft_strsplit(path, ':');
	return (array_path);
}
