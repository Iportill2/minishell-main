/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:52:05 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/16 12:45:57 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern t_data	*g_data;

void	comillas_pares(void)
{
	int i;
	
	i = 0;
	while(g_data->input[i])
	{
		if (g_data->input[i] == '"')
			g_data->doble_comilla++;
		if (g_data->input[i] == '\'')
			g_data->comilla_simple++;
		i++;
	}
	if (g_data->doble_comilla % 2 != 0)
		ft_error_iker(1);
	if (g_data->comilla_simple % 2 != 0)
		ft_error_iker(2);
	printf("COMILLAS_PARES OK\n");
	g_data->doble_comilla = 0;
	g_data->comilla_simple = 0;
}

void ft_error_iker(int n)
{
	g_data->error = n;
	if (g_data->error == 1)
		printf(R"ERROR comillas dobles impares\n");
	if (g_data->error == 2)
		printf(R"ERROR comillas simples impares\n");
	if (g_data->error == 3)
		printf(R" >>FUNCION GET_PATH<< La variable de entorno 'PATH' no está definida.\n");
	if (g_data->error == 4)
		printf(R"%s\n","g_data->array_env[0] == NULL (no pudo alocar memoria en el SPLIT \n");
	if (g_data->error == 5)
		printf("%s\n","g_data->error == 5 NO DEFINIDO\n");
	if (g_data->error == 6)
		printf("%s\n","g_data->error == 6 NO DEFINIDO\n");
	if (g_data->error == 7)
		printf("%s\n","g_data->error == 7 NO DEFINIDO\n");
	if (g_data->error == 8)
		printf("%s\n","g_data->error == 8 NO DEFINIDO\n");
	if (g_data->error == 9)
		printf("%s\n","g_data->error == 9 NO DEFINIDO\n");
	if (g_data->error == 10)
		printf("%s\n","g_data->error == 10 NO DEFINIDO\n");
	if (g_data->error == 11)
		printf("%s\n","g_data->error == 11 NO DEFINIDO\n");
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
		if (g_data->input[i] == '|' && g_data->input[i + 1] == '|')
			return (printf("Minitxel: ESto es del bonus payaso\n"));
		if (g_data->input[i] == '<' && g_data->input[i + 1] == '>')
			return (printf("Minitxel: syntax error near unexpected token `>'\n"));
		if (g_data->input[i] == '>' && g_data->input[i + 1] == '<')
			return (printf("Minitxel: syntax error near unexpected token `<'\n"));
		if (g_data->input[i] == '<' && g_data->input[i + 1] == '<' && \
		(g_data->input[i + 1] != '\0' && g_data->input[i + 2] == '<'))
			return (printf("Minitxel: syntax error near unexpected token `<'\n"));
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
	comillas_pares();
	//ft_error_iker(n);
	return(0);
}