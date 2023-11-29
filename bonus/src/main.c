/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:31:57 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/11/28 13:06:57 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

#include <termios.h>

void	ft_set_home(t_data *d)
{
	int	i;
	int	j;
	int	k;

	d->home = NULL;
	i = 0;
	while (d->custom_env[i])
	{
		if (!ft_strncmp(d->custom_env[i], "HOME=", 5))
		{
			j = 5;
			k = 0;
			while (d->custom_env[i][j++])
				k++;
			d->home = (char *) malloc (sizeof(char) * (k + 1));
			k = 0;
			j = 5;
			while (d->custom_env[i][j])
				d->home[k++] = d->custom_env[i][j++];
			d->home[k] = '\0';
			break ;
		}
		i++;
	}
}

void	ft_g_data_set(int argc, char **argv, char **env, t_data	*d)
{
	(void)argc;
	(void)argv;
	g_result = 0;
	d->original_stdout = dup(1);
	d->fdout = d->original_stdout;
	d->original_stdin = dup(0);
	d->fdin = d->original_stdin;
	ft_custom_env(env, d);
	if (!ft_get_path(d))
		ft_repair_path(d);
	ft_cleaning_oldpwd(d);
	ft_set_home(d);
}

int	ft_bucle(t_data	*d)
{
	while (1)
	{
		if (!d->exit)
			d->input = readline("Minitxel > ");
		if (d->input == NULL || d->exit == 1)
			return (ft_free(d));
		if (d->input)
			add_history(d->input);
		d->array_input = ft_split_quote(d->input, ' ', d);
		d->array_input_clear = ft_ar_input_clear(d);
		d->array_pipe_redir = ft_array_pipe_redir(d);
		if (ft_error(d) == 0)
			ft_pilot(d);
		ft_free_part(d);
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_data	*d;

	d = (t_data *) calloc (sizeof(t_data), 1);
	if (!d)
		return (1);
	ft_g_data_set(argc, argv, env, d);
	ft_signal();
	ft_bucle(d);
	return (0);
}
