/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_select.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:24:02 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/11/27 20:11:05 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_check_pipe(t_data *d)
{
	int	i;

	i = 0;
	while (d->array_input && d->array_input[i])
	{
		if (d->array_input[i][0] == '|')
		{
			d->pipe_check = 1;
			return ;
		}
		i++;
	}
	d->pipe_check = 0;
}

void	ft_command_select(t_data *d)
{
	ft_check_pipe (d);
	if (d->ar_only_com)
	{
		if (!ft_strcmp(d->ar_only_com[0], "echo"))
			ft_echo(1, d);
		else if (!ft_strcmp(d->ar_only_com[0], "pwd"))
			ft_get_print_cwd(d);
		else if (!ft_strcmp(d->ar_only_com[0], "cd"))
			ft_cd(1, d);
		else if (!ft_strcmp(d->ar_only_com[0], "export"))
			ft_export(1, d);
		else if (!ft_strcmp(d->ar_only_com[0], "unset"))
			ft_unset(1, d);
		else if (!ft_strcmp(d->ar_only_com[0], "env"))
			ft_print_env(d);
		else if (!ft_strcmp(d->ar_only_com[0], "exit"))
		{
			if (d->pipe_check)
				return ;
			else
				d->exit = 1;
		}
		else
			ft_try_path_access(d);
	}
}

int	ft_ar_only_comand_len(t_data *d, int i)
{
	int		j;

	j = 0;
	while (d->array_pipe_redir[i] && d->array_input[i][0] != '|')
	{
		if (!ft_strcmp (d->array_pipe_redir[i], "arg"))
		{
			i++;
			j++;
		}
		else if (d->array_pipe_redir[i + 1] != NULL)
			i = i + 2;
		else
			i++;
	}
	return (j);
}

char	**ft_ar_only_com(t_data *d, int i)
{
	int		j;
	char	**s;

	if (ft_ar_only_comand_len(d, i) == 0)
		return (NULL);
	s = (char **) malloc (sizeof(char *) * (ft_ar_only_comand_len(d, i) + 1));
	if (!s)
		return (NULL);
	j = i;
	i = 0;
	if (!ft_strcmp (d->array_pipe_redir[j], "arg"))
		s[i++] = ft_strdup(d->array_input_clear[j++]);
	else
		j++;
	while (d->array_input_clear[j] && d->array_input[j][0] != '|')
	{
		if (!ft_strcmp (d->array_pipe_redir[j], "arg") && \
		!ft_strcmp (d->array_pipe_redir[j - 1], "arg"))
			s[i++] = ft_strdup(d->array_input_clear[j++]);
		else
			j++;
	}
	s[i++] = NULL;
	return (s);
}

char	**ft_array_pipe_redir(t_data *d)
{
	int		i;
	char	**s;

	i = 0;
	while (d->array_input_clear[i])
		i++;
	s = malloc (sizeof(char *) * (i + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (d->array_input_clear[i])
	{
		if ((d->array_input_clear[i][0] == '|' || \
		d->array_input_clear[i][0] == '<' || \
		d->array_input_clear[i][0] == '>') && \
		(d->array_input[i][0] != '"' && d->array_input[i][0] != '\''))
			s[i] = ft_strdup(d->array_input_clear[i]);
		else
			s[i] = ft_strdup("arg");
		i++;
	}
	s[i] = NULL;
	return (s);
}
