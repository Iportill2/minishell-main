/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:11:58 by iportill          #+#    #+#             */
/*   Updated: 2023/11/24 13:12:44 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_redir_error(char **s, t_data *d)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (strcmp(s[i], "arg") && (s[i + 1] == NULL || strcmp(s[i + 1],
					"arg")))
			return (ft_error_iker(8, d), 1);
		i++;
	}
	return (0);
}

int	ft_quote_error(char *s, t_data *d)
{
	char	c;
	int		i;

	i = 0;
	c = 'X';
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '"')
		{
			if (c == 'X')
				c = s[i];
			else if (c == s[i])
				c = 'X';
		}
		i++;
	}
	if (c == 'X')
		return (0);
	else
		return (ft_error_iker(1, d), g_result = 1, 1);
}
