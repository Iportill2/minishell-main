/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:58:31 by iportill          #+#    #+#             */
/*   Updated: 2023/11/29 10:28:27 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_father(t_data *d)
{
	waitpid(d->pid, &g_result, 0);
	wait(NULL);
	if (d->env_with_access)
	{
		free (d->env_with_access);
		d->env_with_access = NULL;
	}
	if (WIFSIGNALED(g_result))
	{
		if (WTERMSIG(g_result) == 2)
			g_result = 130;
		else if (WTERMSIG(g_result) == 3)
			g_result = 131;
	}
	else
		g_result = WEXITSTATUS(g_result);
	ft_signal();
}

void	ft_pipe_with_sons(t_data *d)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = ft_signal_child;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	d->pid = fork();
	if (d->pid == -1)
	{
		ft_error_iker(5, d);
		g_result = 1;
	}
	if (d->pid == 0)
	{
		if (execve(d->env_with_access, d->ar_only_com, \
		d->custom_env) == -1)
		{
			ft_error_iker(6, d);
			exit(127);
		}
	}
	else
		ft_father(d);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
