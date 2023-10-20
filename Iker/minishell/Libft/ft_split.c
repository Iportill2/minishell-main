/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:31:34 by iportill          #+#    #+#             */
/*   Updated: 2023/07/18 15:40:10 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_size(char const *s, char c)
{
	int	count;
	int	trigger;

	count = 0;
	trigger = 0;
	while (*s)
	{
		if (*s != c && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (*s == c)
			trigger = 0;
		s++;
	}
	return (count);
}

static int	ft_size_word(char const *s, char c, int start)
{
	int	end;

	end = 0;
	while (s[start] != c && s[start])
	{
		end++;
		start++;
	}
	return (end);
}

static char	**ft_free(char **split, size_t word)
{
	while (word > 0)
	{
		--word;
		free(split[word]);
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	n_word;
	size_t	word;
	int		start;
	int		end;

	n_word = ft_count_size(s, c);
	split = (char **)malloc((n_word + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	word = -1;
	start = 0;
	while (++word < n_word)
	{
		while (s[start] == c)
			start++;
		end = ft_size_word(s, c, start);
		split[word] = ft_substr(s, start, end);
		if (!split[word])
			return (ft_free(split, word));
		start = start + end;
	}
	split[word] = 0;
	return (split);
}
