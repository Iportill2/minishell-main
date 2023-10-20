/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:30:08 by iportill          #+#    #+#             */
/*   Updated: 2023/10/20 11:49:51 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern t_data	*g_data;

int	ft_quote_space_check(char **s, char *in, int n)
{
	int		i;
	int 	j;
	int		k;

	i = 0;
	k = 0;
	while (i <= n)
	{
		j = 0;
		while(s[i][j])
		{
			if (s[i][j] == in[k])
			{
				j++;
				k++;
			}
			else
				k++;
		}
		i++;
	}
	if (in[k] == ' ')
		return(1);
	return (0);
}

int	ft_quote_space(int n)
{
	char	**s;

	s = g_data->array_input;
	/* printf("ar_input:%s\n", g_data->array_input[n]);
	printf("ar_input + 1:%s\n", g_data->array_input[n + 1]);
	printf("input:%s\n", g_data->input); */
	if (s[n + 1] != NULL && s[n][ft_strlen(s[n]) - 1] != '"' && \
	s[n][ft_strlen(s[n]) - 1] != '\'' && s[n + 1][0] != '"' && \
	s[n + 1][0] != '\'')
		return(1);
	else
		return (ft_quote_space_check(s, g_data->input, n));
	return (0);
}

void ft_putstr_custom(char *str, int n)
{
	int i=0;
	int j = 1;

	while(str[i])
	{
		if (str[i] == '$')
		{
			ft_dollar(str + i);
			j = 0;
		}
		else if (j == 1)
			write(1,&str[i],1);
		i++;
	}
	if (g_data->array_input[n + 1] !=  NULL && \
	ft_strcmp(g_data->array_input[n + 1], "|") && ft_quote_space(n))
		write(1," ",1);
}
void ft_putstr_custom_simple(char *str, int n)
{
	int	i;

	i = 1;
	while(str[i])
	{
		if(str[i]!='\'')
			write(1,&str[i],1);
		i++;
	}
	if (g_data->array_input[n + 1] !=  NULL && \
	ft_strcmp(g_data->array_input[n + 1], "|") && ft_quote_space(n))
		write(1," ",1);
}

void ft_putstr_custom_doble(char *str, int n)
{
	int i;

	(void)n;
	i = 1;
	while(str[i] != '\0')
	{
		if (str[i] == '$')
		{
			ft_dollar(str + i);
			while(str[i] != '\0' && str[i] != ' ')
				i++;
		}
		if(str[i] != '\0' && str[i]!='\"')
			write(1, &str[i], 1);
		i++;
	}
	if (g_data->array_input[n + 1] !=  NULL && \
	ft_strcmp(g_data->array_input[n + 1], "|") && ft_quote_space(n))
		write(1," ",1);
}

void ft_echo(int i)
{
	g_data->echo_jump = 1;
	if (!ft_strcmp(g_data->array_input[i],"\"-n\"") || !ft_strcmp(g_data->array_input[i],"\'-n\'") || \
	!ft_strcmp(g_data->array_input[i],"-n"))
	{
		g_data->echo_jump = 0;
		i++;
	}
	while (g_data->array_input[i])
	{
		if(g_data->array_input[i][0]=='"' || g_data->array_input[i][0]=='\'')
		{
			if(g_data->array_input[i][0]=='\'')
				ft_putstr_custom_simple(g_data->array_input[i], i);
			else if(g_data->array_input[i][0]=='"')
				ft_putstr_custom_doble(g_data->array_input[i], i);
		}
		else
			ft_putstr_custom(g_data->array_input[i], i);	
	i++;
	}
	if(g_data->echo_jump == 1)
	printf("\n");
}

void ft_recorre_el_array(void)
{
	int i=0;
	while(g_data->array_input[i])
	{
		if(ft_strcmp(g_data->array_input[i],"echo")==0 || ft_strcmp(g_data->array_input[i],"\"echo\"")==0 || ft_strcmp(g_data->array_input[i],"\'echo\'")==0)			
		{
			//printf("echo encontrado\n");
			ft_echo(i + 1);
			//break;
		}
		//printf("%s\n",g_data->array_input[i]);
		i++;
	}
	return ;
}