/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:52:05 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/11/28 16:34:44 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_error_iker(int n, t_data *d)
{
	if (n == 1)
		printf("ERROR comillas sin cerrar \n");
	else if (n == 2)
		printf("Minitxel: syntax error near unexpected token `||'\n");
	else if (n == 4)
		printf("Malloc error\n");
	else if (n == 5)
		printf("Error creating child process\n");
	else if (n == 6)
		printf("Minitxel: %s : command not found\n", d->ar_only_com[0]);
	else if (n == 8)
		printf("Minitxel: syntax error near unexpected token `newline'\n");
	else if (n == 9)
		printf("syntax error near unexpected token `>'\n");
	else if (n == 13)
		printf("syntax error near unexpected token `<'\n");
	else
		ft_error_iker_two(n, d);
}

void	ft_error_iker_two(int n, t_data *d)
{
	if (n == 14)
		printf("syntax error near unexpected token `<>'\n");
	else if (n == 15)
		printf("syntax error near unexpected token `<<'\n");
	else if (n == 16)
		printf("export: `%s': not a valid identifier\n", \
		d->ar_only_com[d->int_export]);
	else if (n == 20)
		printf("Minitxel: unset: `%s': not a valid identifier\n", \
		d->array_input_clear[1]);
	else if (n == 21)
		printf("Minitxel: %s: command not found\n", d->ar_only_com[0]);
	else if (n == 22)
		printf("Minitxel: %s: No such file or directory\n", d->s);
	else if (n == 23)
		printf("Minitxel: %s: Permission denied\n", \
		d->ar_only_com[0]);
	else if (n == 24)
		printf("Minitxel: syntax error near unexpected token `|'\n");
	else if (n == 25)
		printf("Minitxel: %s: is a directory\n", d->ar_only_com[0]);
	else if (n == 26)
		printf("Minitxel: %s: No such file or directory\n", \
		d->env_with_access);
	return ;
}

int	ft_redir_pipe_error_ext(int i, t_data *d)
{
	if ((d->input[i] == '>' && d->input[i + 1] == '<') && \
	(d->input[i + 1] != '\0' && d->input[i + 2] == '<'))
		return (ft_error_iker(15, d), g_result = 258, 1);
	if ((d->input[i] == '>' && d->input[i + 1] == '<') && \
	(d->input[i + 1] != '\0' && d->input[i + 2] == '>'))
		return (ft_error_iker(14, d), g_result = 258, 1);
	if ((d->input[i] == '<' && d->input[i + 1] == '>') && \
	(d->input[i + 1] != '\0' && d->input[i + 2] == '>'))
		return (ft_error_iker(9, d), g_result = 258, 1);
	if ((d->input[i] == '<' && d->input[i + 1] == '>') && \
	(d->input[i + 1] != '\0' && d->input[i + 2] == '<'))
		return (ft_error_iker(13, d), g_result = 258, 1);
	if ((d->input[i] == '>' && d->input[i + 1] == '>') && \
	(d->input[2] == '\0'))
		return (ft_error_iker(8, d), g_result = 258, 1);
	if ((d->input[i] == '<' && d->input[i + 1] == '<') && \
	(d->input[2] == '\0'))
		return (ft_error_iker(8, d), g_result = 258, 1);
	if ((d->input[i] == '>' && d->input[i + 1] == '>') && \
	(d->input[i + 1] != '\0' && d->input[i + 2] == '<'))
		return (ft_error_iker(13, d), g_result = 258, 1);
	if ((d->input[i] == '<' && d->input[i + 1] == '<') && \
	(d->input[i + 1] != '\0' && d->input[i + 2] == '>'))
		return (ft_error_iker(9, d), g_result = 258, 1);
	return (0);
}

int	ft_redir_pipe_error(t_data *d)
{
	d->i = 0;
	while (d->input[d->i])
	{
		if (d->input[d->i] == '|' && d->input[d->i + 1] == '\0')
			return (ft_error_iker(24, d), g_result = 258, 1);
		if (d->input[d->i] == '|' && d->input[d->i + 1] == '|')
			return (ft_error_iker(2, d), g_result = 258, 1);
		if (ft_redir_pipe_error_ext(d->i, d))
			return (1);
		if (d->input[d->i] == '<' && d->input[d->i + 1] == '<' && \
		(d->input[d->i + 1] != '\0' && d->input[d->i + 2] == '<'))
			return (ft_error_iker(8, d), g_result = 258, 1);
		if (d->input[d->i] == '>' && d->input[d->i + 1] == '>' && \
		(d->input[d->i + 1] != '\0' && d->input[d->i + 2] == '>'))
			return (ft_error_iker(9, d), g_result = 258, 1);
		if (d->input[d->i] == '>' && d->input[d->i + 1] == '<' && \
		d->input[2] == '\0')
			return (ft_error_iker(13, d), g_result = 258, 1);
		if (d->input[d->i] == '<' && d->input[d->i + 1] == '>')
			return (ft_error_iker(8, d), g_result = 258, 1);
		if (d->error != 0)
			break ;
		d->i++;
	}
	return (0);
}

int	ft_error(t_data *g_data)
{
	if (ft_quote_error(g_data->input, g_data))
		return (1);
	if (ft_redir_pipe_error(g_data))
		return (1);
	if (ft_redir_error(g_data->array_pipe_redir, g_data))
		return (1);
	return (0);
}
