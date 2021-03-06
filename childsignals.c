/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childsignals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 15:20:24 by gcadel            #+#    #+#             */
/*   Updated: 2015/10/07 16:00:28 by gcadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	sh_wrong_exit2(int signum)
{
	if (signum == SIGBUS)
		ft_putstr("bus error ");
	else if (signum == SIGSEGV)
		ft_putstr("segmentation fault ");
	else if (signum == SIGSYS)
		ft_putstr("invalid system call ");
	else if (signum == SIGALRM)
		ft_putstr("timeout ");
	else if (signum == SIGSTOP)
		ft_putstr("suspended (signal) ");
	else if (signum == SIGXCPU)
		ft_putstr("cpu limit exceeded ");
	else if (signum == SIGXFSZ)
		ft_putstr("size limit exceeded ");
	else if (signum == SIGVTALRM)
		ft_putstr("virtual time alarm ");
	else if (signum == SIGPROF)
		ft_putstr("profile signal shell");
	else if (signum == SIGUSR1)
		ft_putstr("user-defined signal 1 shell ");
	else if (signum == SIGUSR2)
		ft_putstr("user-defined singal 2 shell ");
}

void	sh_wrong_exit(int signum, char *son)
{
	if (signum == SIGPIPE)
		return ;
	if (signum == SIGINT)
	{
		ft_putchar('\n');
		return ;
	}
	ft_putstr("ft_minishell1: ");
	if (signum == SIGHUP)
		ft_putstr("hangup ");
	else if (signum == SIGILL)
		ft_putstr("illegal hardware instruction ");
	else if (signum == SIGTRAP)
		ft_putstr("trace trap shell ");
	else if (signum == SIGABRT)
		ft_putstr("abort ");
	else if (signum == SIGFPE)
		ft_putstr("floating point exception ");
	else if (signum == SIGEMT)
		ft_putstr("EMT instruction ");
	else if (signum == SIGKILL)
		ft_putstr("killed ");
	else
		sh_wrong_exit2(signum);
	ft_putendl(son);
}
