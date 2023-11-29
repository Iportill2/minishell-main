/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:49:36 by iportill          #+#    #+#             */
/*   Updated: 2023/11/24 15:49:56 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	*ft_del(char **array, int j)
{
	int	i;

	i = 0;
	while (i < j)
		free(array[i++]);
	free(array);
	return (NULL);
}

char	*ft_subsplit_create(char const *s, t_data *d)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *) malloc (sizeof(char) * d->len);
	if (str == NULL)
		return (NULL);
	while (i < d->len - 1)
		str[i++] = s[d->start++];
	str[i] = '\0';
	return (str);
}

int	ft_subplit_quote(char const *s, int i, t_data *d)
{
	d->c = s[i++];
	d->len++;
	while (s[i] && s[i] != d->c)
	{
		d->len++;
		i++;
	}
	if (s[i])
	{
		i++;
		d->len++;
	}
	return (i);
}

int	ft_subplit_pipe_redir(char const *s, int i, t_data *d)
{
	if (s[i] == '|')
	{
		d->len++;
		return (1);
	}
	else if (s[i] == '<' || s[i] == '>')
	{
		d->len++;
		if (s[i + 1] == '<' || s[i + 1] == '>')
			d->len++;
		return (1);
	}
	return (0);
}
