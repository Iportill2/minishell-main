/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:47:46 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/11/29 10:25:12 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_open_w_c_t(char *s, t_data *d)
{
	if (d->not_access == 1)
		return (1);
	d->fdout = open(s, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	try_access_readable_writeable_executable(s, d);
	if (d->not_writeable == 1)
		return (ft_error_iker(23, d), g_result = 1, 1);
	if (d->fdout == -1)
		return (ft_error_iker(23, d), g_result = 1, 1);
	dup2 (d->fdout, STDOUT_FILENO);
	d->sem_out = 1;
	g_result = 0;
	return (0);
}

int	ft_open_w_c_a(char *s, t_data *d)
{
	if (d->not_access == 1)
		return (1);
	d->fdout = open(s, O_WRONLY | O_CREAT | O_APPEND, 0644);
	try_access_readable_writeable_executable(s, d);
	if (d->not_writeable == 1)
	{
		ft_error_iker(23, d);
		g_result = 1;
		return (1);
	}
	dup2 (d->fdout, STDOUT_FILENO);
	d->sem_out = 1;
	g_result = 0;
	return (0);
}

int	ft_open_rd(char *s, t_data *d)
{
	d->fdin = open(s, O_RDONLY);
	try_access_readable_writeable_executable(s, d);
	if (d->not_access == 1)
	{
		d->not_access = 1;
		d->s = s;
		g_result = 1;
		ft_error_iker(22, d);
		return (1);
	}
	if (d->not_readable == 1)
	{
		d->s = s;
		g_result = 1;
		ft_error_iker(23, d);
		dup2(d->original_stdout, STDOUT_FILENO);
		return (1);
	}
	dup2 (d->fdin, STDIN_FILENO);
	d->sem_in = 1;
	return (0);
}

int	ft_here_doc(char *s, t_data *d, int i)
{
	int		fd;
	char	*str;
	char	*here_plus_s;

	g_result = 0;
	d->s = s;
	d->here_doc = ft_strdup(d->array_input_clear[i + 1]);
	fd = open (".temp", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	str = get_next_line(0);
	here_plus_s = ft_strjoin(d->here_doc, "\n");
	while (ft_strcmp(str, here_plus_s) != 0 && str && g_result == 0)
	{
		write(fd, str, ft_strlen(str));
		free(str);
		str = get_next_line(0);
	}
	free(str);
	free(here_plus_s);
	ft_open_rd(".temp", d);
	close(fd);
	d->sem_in = 0;
	return (0);
}

int	ft_redir_sign(t_data *d, int i)
{
	int	error;

	error = 0;
	while (d->array_pipe_redir && d->array_pipe_redir[i] && \
	d->array_pipe_redir[i][0] != '|')
	{
		if (!strcmp(d->array_pipe_redir[i], ">"))
			error = ft_open_w_c_t(d->array_input_clear[i + 1], d);
		else if (!strcmp(d->array_pipe_redir[i], ">>"))
			error = ft_open_w_c_a(d->array_input_clear[i + 1], d);
		else if (!strcmp(d->array_pipe_redir[i], "<"))
			error = ft_open_rd(d->array_input_clear[i + 1], d);
		else if (!strcmp(d->array_pipe_redir[i], "<<"))
			error = ft_here_doc(d->array_input_clear[i + 1], d, i);
		i++;
	}
	return (error);
}
