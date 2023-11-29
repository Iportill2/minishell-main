/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote_clear.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:59:16 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/11/28 16:12:24 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_ar_input_set(int i, int len, char **ar, t_data *d)
{
	ar[i] = (char *) malloc (sizeof(char) * len);
	if (!ar[i])
		return (0);
	d->j = 0;
	d->k = 0;
	d->c = 'x';
	while (d->array_input[i][d->j])
	{
		if (d->array_input[i][d->j] == '"' || d->array_input[i][d->j] == '\'')
			ft_ar_input_set_quote(i, ar, d);
		else if (d->array_input[i][d->j] && d->array_input[i][d->j + 1] && \
		d->array_input[i][d->j] == '$' && d->array_input[i][d->j + 1] != ' ' \
		&& d->c != '\'')
			ft_ar_input_set_dolar(i, ar, d);
		else
			ar[i][d->k++] = d->array_input[i][d->j++];
	}
	ar[i][d->k] = '\0';
	return (0);
}

void	ft_ar_input_clear_no_quote(t_data *d)
{
	if (d->array_input[d->i][d->j] && d->array_input[d->i][d->j + 1] && \
	d->array_input[d->i][d->j] == '$' && d->array_input[d->i][d->j + 1] != ' '\
	&& d->c != '\'')
	{
		d->len = d->len + ft_dollar_len(&d->array_input[d->i][d->j + 1], d);
		d->content_dollar = NULL;
		d->j++;
		while (d->array_input[d->i][d->j] && d->array_input[d->i][d->j] != '"'\
		&& d->array_input[d->i][d->j] != ' '\
		&& d->array_input[d->i][d->j] != '$'\
		&& d->array_input[d->i][d->j] != '\'')
			d->j++;
	}
	else
	{
		d->j++;
		d->len++;
	}
}

void	ft_ar_input_clear_quote(t_data *d)
{
	if (d->c == 'x')
	{
		d->c = d->array_input[d->i][d->j];
		d->j++;
	}
	else if (d->c == d->array_input[d->i][d->j])
	{
		d->c = 'x';
		d->j++;
	}
	else
	{
		d->j++;
		d->len++;
	}
}

char	**ft_ar_input_clear(t_data *d)
{
	char	**ar;

	d->i = 0;
	while (d->array_input[d->i])
		d->i++;
	ar = (char **) malloc (sizeof(char *) * (d->i + 1));
	if (!ar)
		return (NULL);
	d->i = -1;
	while (d->array_input[++d->i])
	{
		d->len = 1;
		d->c = 'x';
		d->j = 0;
		while (d->array_input[d->i][d->j])
		{
			if (d->array_input[d->i][d->j] == '"' || \
			d->array_input[d->i][d->j] == '\'')
				ft_ar_input_clear_quote(d);
			else
				ft_ar_input_clear_no_quote(d);
		}
		ft_ar_input_set(d->i, d->len, ar, d);
	}
	return (ar[d->i] = NULL, ar);
}
