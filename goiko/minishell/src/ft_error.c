/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:52:05 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/20 11:41:26 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern t_data	*g_data;

int	ft_quote_error(void)
{
	int 	i;
	char	**s;

	i = 0;
	s = g_data->array_input;
	while (s[i])
	{
		if (s[i][0] == '"' && s[i][ft_strlen(s[i]) - 1] != '"')
			return (printf(R"ERROR\n"W), 1);
		if (s[i][0] == '\'' && s[i][ft_strlen(s[i]) - 1] != '\'')
			return (printf(R"ERROR\n"W), 1);
		if (ft_strlen(s[i]) == 1 && (s[i][0] == '\'' || s[i][0] == '"'))
			return (printf(R"ERROR\n"W), 1);
		i++;
	}
	return (0);
}	

void ft_error_iker(int n)
{
	g_data->error = n;
	if (g_data->error == 1)
		printf(R"ERROR comillas dobles impares\n"W);
	if (g_data->error == 2)
		printf(R"ERROR comillas simples impares\n"W);
	if (g_data->error == 3)
		printf(R" >>FUNCION GET_PATH<< La variable de entorno 'PATH' no está definida.\n"W);
	if (g_data->error == 4)
		printf(R"%s\n","g_data->array_env[0] == NULL (no pudo alocar memoria en el SPLIT \n"W);
	if (g_data->error == 5)
		printf(R"Error al crear el proceso hijo GESTIONAR ESTA SALIDA\n"W);
	if (g_data->error == 6)
		printf(R"Error al ejecutar el CMD con  execve\n"W);
	if (g_data->error == 7)
		printf(R"Fallo en ft_env_dollar\n"W);
	if (g_data->error == 8)
		printf(R"Minitxel: syntax error near unexpected token `newline'\n"W);
	if (g_data->error == 9)
		printf("%s\n","g_data->error == 9 NO DEFINIDO\n"W);
	if (g_data->error == 10)
		printf("%s\n","g_data->error == 10 NO DEFINIDO\n"W);
	if (g_data->error == 11)
		printf("%s\n","g_data->error == 11 NO DEFINIDO\n"W);
	if (g_data->error == 12)
		printf("%s\n","g_data->error == 12 NO DEFINIDO\n");
	g_data->error = 0;
	//exit(EXIT_SUCCESS);
}

int	ft_redir_pipe_error(void)
{
	int	i;

	i = 0;
	while(g_data->input[i])
	{
		/* if (g_data->input[i] == '|' && g_data->input[i + 1] == '|')
			return (ft_error_iker(8), 1); */
		if (g_data->input[i] == '<' && g_data->input[i + 1] == '>')
			return (printf("Minitxel: syntax error near unexpected token `>'\n"));
		if (g_data->input[i] == '>' && g_data->input[i + 1] == '<')
			return (printf("Minitxel: syntax error near unexpected token `<'\n"));
		if (g_data->input[i] == '<' && g_data->input[i + 1] == '<' && \
		(g_data->input[i + 1] != '\0' && g_data->input[i + 2] == '<'))
			return (ft_error_iker(8), 1);
			if (g_data->input[i] == '>' && g_data->input[i + 1] == '>' && \
		(g_data->input[i + 1] != '\0' && g_data->input[i + 2] == '>'))
			return (printf("Minitxel: syntax error near unexpected token `>'\n"));
		i++;
	}
	return (0);
}

int	ft_error(void)
{
	if (ft_redir_pipe_error())
		return (1);
	/* if (ft_quote_error())
		return (1); */
	//ft_error_iker(n);
	return(0);
}