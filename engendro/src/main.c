/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:31:57 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/17 16:49:05 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_data	*g_data;

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_set_imput(void)
{
	int		i;
	int		j;
	char	*temp;

	temp = malloc(sizeof(char) * \
	(ft_strlen(g_data->input) + g_data->add_space + 1));
	i = 0;
	j = 0;
	temp[j++] = g_data->input[i++];
	while (g_data->input[i])
	{
		if (g_data->input[i - 1] == '|' && g_data->input[i] != ' ' && \
		g_data->input[i] != '\0')
			temp[j++] = ' ';
		if (g_data->input[i - 1] == '<' && g_data->input[i] != '<' && \
		g_data->input[i] != ' ' && g_data->input[i] != '\0')
			temp[j++] = ' ';
		if (g_data->input[i - 1] == '>' && g_data->input[i] != '>' && \
		g_data->input[i] != ' ' && g_data->input[i] != '\0')
			temp[j++] = ' ';
		if (g_data->input[i - 1] != '<' && g_data->input[i - 1] != '>' && g_data->input[i - 1] != '|' && \
		g_data->input[i - 1] != ' ' && (g_data->input[i] == '<' || g_data->input[i] == '>'  || g_data->input[i] == '|'))
			temp[j++] = ' ';
		temp[j++] = g_data->input[i++];
	}
	temp[j++] = '\0';
	free (g_data->input);
	g_data->input = temp;
	printf("input_ok:\n%s\n", g_data->input);
}

void	input_check(void)
{
	int	i;

	i = 0;
	g_data->add_space = 0;
	while (g_data->input[i])
	{
		if (g_data->input[i] != '<' && g_data->input[i] != '>' && \
		g_data->input[i] != '|'  && g_data->input[i] != ' ' && \
		(g_data->input[i + 1] == '<' || g_data->input[i + 1] == '>' || \
		g_data->input[i + 1] == '|'))
			g_data->add_space++;
		if (g_data->input[i] == '<' && g_data->input[i + 1] != '<' && \
		g_data->input[i + 1] != ' ' && g_data->input[i + 1] != '\0')
			g_data->add_space++;
		if (g_data->input[i] == '>' && g_data->input[i + 1] != '>' \
		&& g_data->input[i + 1] != ' ' && g_data->input[i + 1] != '\0')
			g_data->add_space++;
		if (g_data->input[i] == '|' && (g_data->input[i + 1] != ' ') && \
		g_data->input[i + 1] != '\0')
			g_data->add_space++;
		i++;
	}
	//printf("add_space = %i\n", g_data->add_space);
}


int	main(void)
{
	g_data = (t_data *) malloc (sizeof(t_data));
	ft_get_path();
	while (1)
	{
		g_data->input = readline(G"Minitxel > "W);
		if (g_data->input == NULL)
		{
			printf("\nFinishing Minitxel...\n");
			break ;
		}
		add_history(g_data->input);
		if(ft_error() == 0)
		{
			input_check();
			if(g_data->add_space)
				ft_set_imput();
		}
		
		//free(input);
	}
	return (0);
}
