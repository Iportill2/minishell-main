/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:31:28 by iportill          #+#    #+#             */
/*   Updated: 2023/10/18 12:50:47 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern t_data	*g_data;

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void ft_env_dollar(char *str)
{

    g_data->string_env_dollar = getenv(str);
    if (g_data->string_env_dollar != NULL)
		ft_putstr(g_data->string_env_dollar);
	else
		ft_error_iker(7);
	//printf(R"FT_ENV_DOLLAR OK\n");
        //printf(M"%s"W, g_data->string_env_dollar);
    return;
}

void ft_dollar(char *str)
{
	int i=0;
	int len=ft_strlen(str);
	g_data->contenido_dollar=malloc(sizeof(char)*len);
	if(!g_data->contenido_dollar)
		ft_error_iker(8); 
	int e=0;
	while(str[i+e] && str[i+e] != '"' && str[i+e] != ' ')
	{
		if(str[i+e]=='$')
			i++;
		else
		{
			g_data->contenido_dollar[e]=str[i+e];
			e++;
		}
	}
	g_data->contenido_dollar[e] = '\0';
	ft_env_dollar(g_data->contenido_dollar);
}