/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:18:46 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/16 15:20:31 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern t_data	*g_data;

void parseo_history(void)
{
	int i;
	int len=0;
	
	
	i = 0;
	while(g_data->history[i])
	{
		if (g_data->history[i] == '"')
		{
			i++;
			while(g_data->history[i] != '\0' && g_data->history[i] != '"' )
			{
				i++;
				len++;
			}
		}
	}
	printf("len = %d\n", len);
	printf("g_data->history = %s\n", g_data->history);
	printf("i = %d\n", i);
	return ;
}

void ft_get_path(void)
{
    char *nombre_variable;
	
	nombre_variable = "PATH"; // Reemplaza con el nombre de la variable de entorno que deseas consultar
    g_data->env = getenv(nombre_variable);
    if (g_data->env != NULL)
        printf(G" >>FUNCION GET_PATH<< El valor de la variable de entorno PATH es: %s\n", g_data->env);
	else
		ft_error_iker(3);
	printf(W"CHECK GET_PATH OK\n");
    return;
}
void 	repair_path(t_data *g_data)
{
	g_data->array_env=ft_split(g_data->env, ':');
	int i;
	char	*temp;
	
	i=0;
	//g_data->array_env[0] = NULL;
	if(g_data->array_env[0] == NULL)
		ft_error_iker(4);
	while(g_data->array_env[i])
	{
		temp= g_data->array_env[i];
		g_data->array_env[i] = ft_strjoin(g_data->array_env[i], "/");
		free(temp);
		//printf("array_env[%d] = %s\n", i, g_data->array_env[i]);
		i++;
	}
	printf(G"CHECK REPAIR_PATH OK\n");
}

char	*try_path_access(char **s1, char *s2)
{
	int		i;
	char	*executable_path;

	i = 0;
	while (s1[i])
	{
		executable_path = ft_strjoin(s1[i], s2);
		if (access(executable_path, F_OK) == 0)
			break ;
		free(executable_path);
		executable_path = NULL;
		i++;
	}
	printf(W"TRY_PATH_ACCESS %s\n", executable_path);
	return (executable_path);
}