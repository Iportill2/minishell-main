/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:58:31 by iportill          #+#    #+#             */
/*   Updated: 2023/10/17 17:26:55 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void pipe_with_sons()
{
	printf(Y"Ejecutando la funcion...pipe_with_sons\n");
	g_data->pid = fork();
	if(g_data->pid == -1)
		ft_error_iker(5);
	if(g_data->pid == 0)//hijo
	{
		printf(M"Soy el hijo\n");
		char *args[3];//cmd a ejecutar, argumento del cmd, NULL 
		args[0] = g_data->array_input[0];
		printf(W"args[0] = %s\n", args[0]);
		args[1] = g_data->array_input[1];
		printf("args[1] = %s\n", args[1]);
		args[2]=NULL;
		printf("args[2] = %s\n", args[2]);
		if(execve(g_data->array_env_with_access, args, NULL)==-1)//sin ponemos env enz de nULL u le ponemos env como parametro de entra peta
			ft_error_iker(6);
	}
	else//padre
	{
		waitpid(g_data->pid,&g_data->status,WNOHANG);
		printf(B"Soy el padre\n");
		return;
	}
}
int		ft_strcmp(const char *s1, const char *s2)
{
	int i;
	
	i = 0;
	while(s1[i] && s1[i] == s2[i])
		i++;
	return((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}