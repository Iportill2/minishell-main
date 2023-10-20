/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:02:59 by manue             #+#    #+#             */
/*   Updated: 2023/10/19 19:32:29 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern t_data	*g_data;

int	ft_dollar_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != ' '&& s[i] != '"' && s[i] != '\'')
		i++;
	printf("$len = %i\n", i);
	return (i);
}


char	**ft_ar_input_clear(void)
{
	int		i;
	int		j;
	char	**ar;
	size_t	len;
	char	d;
	char	*dolar;

	i = 0;
	while (g_data->array_input[i])
		i++;
	ar = (char **) malloc (sizeof(char*) * (i + 1));
	if(!ar)
		return (NULL);
	i = 0;
	
	while (g_data->array_input[i])
	{
		len = 1;
		d = 'x';
		j = 0;
		dolar = 0;
		while(g_data->array_input[i][j])
		{
			if (g_data->array_input[i][j] == '"' || g_data->array_input[i][j] == '\'')
			{
				if (g_data->array_input[i][j] == d)
				{
					d = 'x';
					j++;
				}
				else if (d == 'x')
				{
					d = g_data->array_input[i][j];
					j++;
				}
				else
				{
					j++;
					len++;
				}
			}
			else
			{
				j++;
				len++;
			}
			if (g_data->array_input[i][j] && g_data->array_input[i][j] == '$' && d != '\'')
			{
				printf("d: %c\n", d);
				j = j + ft_dollar_len(&g_data->array_input[i][j + 1]);
				//len = len + ft_dollar_expand_len(&g_data->array_input[i][j + 1]);
			}
			printf("len = %zu\n", len);
		}
		i++;
	}
	//printf("len = %zu\n", len);
	return (NULL);
}

void	*ft_del(char **array, int j)
{
	int	i;

	i = 0;
	while (i < j)
		free(array[i++]);
	free(array);
	return (NULL);
}

char	*ft_subsplit(char const *s, char c, int i)
{
	int		len;
	char	*str;
	int		start;
	char	d;

	start = i;
	len = 1;
	while (s[i] != '\0' && s[i] != c &&  s[i] != '|')
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			d = s[i++];
			len++;
			while (s[i] && s[i] != d)
			{
				len++;
				i++;
			}
			if (s[i])
			{
				i++;
				len++;
			}
		}
		else
		{
			while (s[i] && s[i] != c && s[i] != '"' && s[i] != '\'')
			{
				i++;
				len++;
			}
		}
	}
	//printf("len: %i\n", len);
	i = 0;
	str = (char *) malloc (sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	while (i < len - 1)
		str[i++] = s[start++];
	str[i] = '\0';
	//printf("str:%s\n", str);
	//printf("str_len:%zu\n", ft_strlen(str));
	return (str);
}

int	ft_strcount(const char *s, char c)
{
	int		i;
	int		snbr;
	int		ok;
	char	d;

	i = 0;
	snbr = 0;
	ok = 1;
	while (s[i] != '\0')
	{
		if (s[i] != c && ok == 1)
		{
			snbr++;
			ok = 0;
		}
		if (s[i] == '"' || s[i] == '\'')
		{
			d = s[i++];
			while(s[i] && s[i] != d)
				i++;
		}
		if (s[i])
			i++;
		if (s[i] == c)
			ok = 1;
	}
	//printf("count = %i\n", snbr);
	return (snbr);
}

char	**ft_split_quote(char const *s, char c)
{
	char	**array;
	char	*str;
	int		i;
	int		j;

	if (!s)
		return (0);
	array = (char **) malloc (sizeof(char *) * ((ft_strcount(s, c)) + 1));
	if (array == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i] != '\0')
	{
		if (s[i] != c)
		{
			str = ft_subsplit(s, c, i);
			if (!str)
				return (ft_del(array, j));
			array[j++] = str;
			i = i + ft_strlen(str) - 1;
		}
	}
	array[j] = NULL;
	return (array);
}
