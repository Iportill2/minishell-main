/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:56:29 by iportill          #+#    #+#             */
/*   Updated: 2023/11/24 16:07:00 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_getenv(char *name_variable, t_data *d)
{
	int		i;
	int		len_s;
	char	*s;

	i = 0;
	s = ft_strjoin(name_variable, "=");
	len_s = ft_strlen(s);
	while (d->custom_env && d->custom_env[i])
	{
		if (!ft_strncmp(d->custom_env[i], s, len_s))
			return (free (s), d->custom_env[i] + len_s);
		i++;
	}
	free(s);
	return (NULL);
}

void	ft_custom_env(char **env, t_data *d)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	d->custom_env = malloc(sizeof(char *) * (i + 1));
	i = 0;
	if (!d->custom_env)
		return ;
	while (env[i])
	{
		d->custom_env[i] = ft_strdup(env[i]);
		i++;
	}
	d->custom_env[i] = NULL;
}

char	*custom_getenv(const char *s, t_data *d)
{
	int	i;

	i = 0;
	while (d->custom_env[i])
	{
		if (strncmp(d->custom_env[i], s, ft_strlen(s)) == 0)
			break ;
		i++;
	}
	return (d->custom_env[i] + (ft_strlen(s)));
}
