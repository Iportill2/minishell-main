/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pilot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:15:07 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/11/28 13:09:07 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_pipe_set_c(t_data *d)
{
	ft_redir_sign(d, d->i);
	if (d->sem_in == 0)
	{
		dup2(d->fda[0], STDIN_FILENO);
		close (d->fda[0]);
	}
	if (d->sem_out == 0)
		dup2(d->original_stdout, STDOUT_FILENO);
	d->sem_in = 0;
	d->sem_out = 0;
	ft_command_select(d);
	return (0);
}

int	ft_pipe_set_b(t_data *d)
{
	pipe(d->fdb);
	if (d->sem_in == 0)
	{
		dup2(d->fda[0], STDIN_FILENO);
		close (d->fda[0]);
	}
	if (d->sem_out == 0)
	{
		dup2(d->fdb[1], STDOUT_FILENO);
		close (d->fdb[1]);
	}
	d->fda[0] = d->fdb[0];
	d->fda[1] = d->fdb[1];
	d->sem_in = 0;
	d->sem_out = 0;
	return (0);
}

int	ft_pipe_set_a(t_data *d)
{
	if (pipe(d->fda) == -1)
		return (write(1, "Error creating pipe\n", 20), -1);
	if (d->sem_out == 0)
	{
		dup2(d->fda[1], STDOUT_FILENO);
		close (d->fda[1]);
	}
	d->sem_in = 0;
	d->sem_out = 0;
	return (0);
}

int	ft_pipe_check(t_data *d, int i, char c)
{
	while (d->array_pipe_redir[i])
	{
		while (d->array_pipe_redir[i] && d->array_pipe_redir[i][0] != '|')
			i++;
		if (d->array_pipe_redir[i] && d->array_pipe_redir[i][0] == '|')
		{
			if (c == 'a')
				ft_pipe_set_a(d);
			else if (c == 'b')
				ft_pipe_set_b(d);
			return (i + 1);
		}
	}
	return (i);
}

void	ft_pilot(t_data *d)
{
	d->i = 0;
	d->ar_only_com = ft_ar_only_com(d, d->i);
	d->sem_out = 0;
	ft_redir_sign(d, 0);
	d->i = ft_pipe_check(d, d->i, 'a');
	ft_command_select(d);
	ft_free_array(&d->ar_only_com);
	while (d->array_pipe_redir[d->i])
	{
		d->ar_only_com = ft_ar_only_com(d, d->i);
		d->j = d->i;
		ft_redir_sign(d, d->j);
		d->i = ft_pipe_check(d, d->i, 'b');
		if (d->array_pipe_redir[d->i] == NULL)
			ft_pipe_set_c(d);
		else
			ft_command_select(d);
		ft_free_array(&d->ar_only_com);
	}
	if (access(".temp", F_OK) == 0)
		unlink(".temp");
	dup2(d->original_stdin, STDIN_FILENO);
	dup2(d->original_stdout, STDOUT_FILENO);
}
