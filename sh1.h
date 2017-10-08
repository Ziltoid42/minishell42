/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 15:21:47 by gcadel            #+#    #+#             */
/*   Updated: 2015/11/23 16:34:14 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH1_H
# define SH1_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct stat	t_stat;
void	fork_process(char *path, char **env, char **av);
void	sh_free_memory(char *line, char **path);
void	free_memory(char *line, char **path);
void	sh_loop(char **env);
void	sh_execute_cmd(char *line, char ***sh_env, char **path);
char	*sh_replace_home(char *path, char **env);
int		sh_get_env_pos(char *find, char **env);
char	**sh_save_env(char ***env);
char	*sh_get_env_part(char *part, char **env);
char	**sh_parse_env(char *find, char **env);
int		sh_acess(char *path);
char	*sh_search_bin(char *line, char *dirpath);
int		sh_isbin(char *path);
void	sh_prompt(char ***env);
void	sh_execute_bin(char *av, char ***env, char **path);
int		sh_bin_path(char **option, char **path, char ***env);
int		sh_search_builtin(char *av, char ***env);
int		sh_search_builtin2(char **option, char ***env, int state);
void	sh_notfound(char *av);
void	sh_builtin_exit(char **av);
void	sh_builtin_cd(char **av, char ***env);
void	sh_builtin_cd_open(char *dir, char ***env);
void	sh_builtin_env_use(void);
void	sh_print_env(char **env);
void	sh_builtin_env_exec(char **av, char ***new_env, char ***env, int i);
void	sh_builtin_env(char **av, char ***env);
void	sh_builtin_setenv(char **av, char ***env);
void	sh_builtin_setenv_mng(char *name, char *value, char ***env);
void	sh_builtin_setenv_replace(char *name, char *value, char **env);
void	sh_builtin_setenv_add(char *name, char *value, char ***env);
void	sh_unsetenv_usage(void);
void	sh_builtin_delete(int n, char **av, char ***env);
void	sh_builtin_unsetenv(char **av, char ***env);
pid_t	save_cpid(pid_t *father);
void	sh_signal_handle(int signum);
void	sh_sig_to_exit(int signum);
void	sh_signals2(void);
void	sh_signals(void);
void	sh_wrong_exit(int signum, char *son);
void	sh_wrong_exit2(int signum);

#endif
