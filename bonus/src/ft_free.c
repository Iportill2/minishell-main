/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:09:15 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/11/28 16:12:17 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* void	ft_print_toito(t_data *g_data)
{
	int	i;

	printf("1INPUT array:\n");
	i = 0;
	while (g_data->array_input[i])
	{
		printf("g_data->array_input[%d] = %s\n",i , g_data->array_input[i]);
		i++;
	}
	printf("\n");	
	printf("2INPUT array clear:\n");
	i = 0;
	while (g_data->array_input_clear && g_data->array_input_clear[i])
	{
		printf("g_data->array_input_clear[%d] = %s\n",i , \
		g_data->array_input_clear[i]);
		i++;
	}
	printf("\n");
	i = 0;
	printf("2INPUT array pipe redir:\n");
	while (g_data->array_pipe_redir && g_data->array_pipe_redir[i])
	{
		printf("g_data->array_pipe_redir[%d] = %s\n",i , \
		g_data->array_pipe_redir[i]);
		i++;
	}
	printf("\n");
	
	printf("\n");
	i = 0;
	printf("only comand:\n");
	while (g_data->ar_only_com && g_data->ar_only_com[i])
	{
		printf("only comand [%i] = %s\n",i, g_data->ar_only_com[i]);
		i++;
	}
	printf("\n");
} */

void	ft_free_array(char ***s)
{
	int	i;

	i = 0;
	if (*s)
	{
		while ((*s)[i])
			free((*s)[i++]);
		free (*s);
	}
	*s = NULL;
}

int	ft_free_part(t_data *d)
{
	free(d->input);
	d->input = NULL;
	ft_free_array(&d->array_input);
	ft_free_array(&d->array_input_clear);
	ft_free_array(&d->array_pipe_redir);
	ft_free_array(&d->ar_only_com);
	return (0);
}

int	ft_free(t_data *d)
{
	if (d->input)
	{
		free (d->input);
		d->input = NULL;
	}
	if (d->env_with_access)
	{
		free (d->env_with_access);
		d->env_with_access = NULL;
	}
	if (d->current_directory)
		free (d->current_directory);
	free(d->home);
	ft_free_array(&d->array_env);
	ft_free_array(&d->array_input);
	ft_free_array(&d->array_input_clear);
	ft_free_array(&d->array_pipe_redir);
	ft_free_array(&d->ar_only_com);
	ft_free_array(&d->custom_env);
	free(d);
	printf("exit\n");
	return (0);
}
