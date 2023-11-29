/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:28:27 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/11/24 15:49:44 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_subsplit(char const *s, char c, int i, t_data *d)
{
	d->start = i;
	d->len = 1;
	while (s[i] != '\0' && s[i] != c)
	{
		if (ft_subplit_pipe_redir(s, i, d))
			break ;
		else if (s[i] == '"' || s[i] == '\'')
			i = ft_subplit_quote(s, i, d);
		else
		{
			while (s[i] && s[i] != c && s[i] != '|' && s[i] != '"' && \
			s[i] != '<' && s[i] != '|' && s[i] != '>')
			{
				i++;
				d->len++;
			}
		}
		if (s[i] == '|' || s[i] == '<' || s[i] == '>')
			break ;
	}
	return (ft_subsplit_create (s, d));
}

void	ft_pipe_redir_count(const char *s, t_data *d)
{
	if (s[d->i] == '|')
	{
		d->i++;
		d->snb++;
		d->oks = 1;
	}
	if (s[d->i] == '<' || s[d->i] == '>')
	{
		d->i++;
		if (s[d->i] == '<' || s[d->i] == '>')
			d->i++;
		d->snb++;
		d->oks = 1;
	}
}

int	ft_strcount(const char *s, char c, t_data *d)
{
	d->i = 0;
	d->snb = 0;
	d->oks = 1;
	while (s[d->i] != '\0')
	{
		ft_pipe_redir_count(s, d);
		if (s[d->i] && s[d->i] != c && d->oks == 1)
		{
			d->snb++;
			d->oks = 0;
		}
		if (s[d->i] == '"' || s[d->i] == '\'')
		{
			d->c = s[d->i++];
			while (s[d->i] && s[d->i] != d->c)
				d->i++;
		}
		if (s[d->i])
			d->i++;
		if (s[d->i] == c)
			d->oks = 1;
	}
	return (d->snb);
}

char	**ft_split_quote(char const *s, char c, t_data *d)
{
	char	**array;
	char	*str;
	int		i;
	int		j;

	if (!s)
		return (0);
	array = (char **) malloc (sizeof(char *) * ((ft_strcount(s, c, d)) + 1));
	if (array == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i] != '\0')
	{
		if (s[i] != c)
		{
			str = ft_subsplit(s, c, i, d);
			if (!str)
				return (ft_del(array, j));
			array[j++] = str;
			i = i + ft_strlen(str) - 1;
		}
	}
	array[j] = NULL;
	return (array);
}
