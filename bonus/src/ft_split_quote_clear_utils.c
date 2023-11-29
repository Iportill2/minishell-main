/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote_clear_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:52:13 by iportill          #+#    #+#             */
/*   Updated: 2023/11/28 13:07:48 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_dolar_question(t_data *d)
{
	int	i;

	d->content_dollar = ft_itoa(g_result);
	i = ft_strlen(d->content_dollar);
	return (i);
}

int	ft_dollar_len(char *s, t_data *d)
{
	int		i;
	char	*str;
	char	*dolar;

	i = 0;
	if (s[0] == '?')
		return (free(d->content_dollar), ft_dolar_question(d));
	while (s[i] && s[i] != ' ' && s[i] != '"' && s[i] != '\'' && s[i] != '$')
		i++;
	str = (char *) malloc (sizeof(char) * (i + 1));
	if (!s)
		return (ft_error_iker(4, d), g_result = 1, 0);
	i = 0;
	while (s[i] && s[i] != ' ' && s[i] != '"' && s[i] != '\'' && s[i] != '$')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	dolar = ft_getenv(str, d);
	if (dolar)
		d->content_dollar = dolar;
	else
		d->content_dollar = NULL;
	return (free (str), ft_strlen(dolar));
}

void	ft_ar_input_set_dolar(int i, char **ar, t_data *d)
{
	d->l = 0;
	ft_dollar_len(&d->array_input[i][d->j + 1], d);
	while (d->content_dollar && d->content_dollar[d->l])
		ar[i][d->k++] = d->content_dollar[d->l++];
	d->j++;
	while (d->array_input[i][d->j] && d->array_input[i][d->j] != '"' \
	&& d->array_input[i][d->j] != ' ' && d->array_input[i][d->j] != '$' \
	&& d->array_input[i][d->j] != '\'')
		d->j++;
}

void	ft_ar_input_set_quote(int i, char **ar, t_data *d)
{
	if (d->c == 'x')
	{
		d->c = d->array_input[i][d->j];
		d->j++;
	}
	else if (d->c == d->array_input[i][d->j])
	{
		d->c = 'x';
		d->j++;
	}
	else
		ar[i][d->k++] = d->array_input[i][d->j++];
}
