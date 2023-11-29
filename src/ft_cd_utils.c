/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:58:30 by iportill          #+#    #+#             */
/*   Updated: 2023/11/27 12:09:57 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_file_path(int i, t_data *d)
{
	if (access(d->array_input_clear[i], R_OK) == 0)
		ft_set_oldpwd(d);
	if (chdir(d->array_input_clear[i]))
	{
		d->s = d->array_input_clear[i];
		ft_error_iker(22, d);
		g_result = 1;
		return (1);
	}
	return (0);
}

int	ft_cd(int i, t_data *d)
{
	if (d->pipe_check)
		return (0);
	if (!d->ar_only_com[i] || d->ar_only_com[i][0] == '\0' \
	|| !ft_strcmp(d->array_input_clear[i], "--"))
		ft_cd_home(d);
	else if (d->ar_only_com[i] && \
	!ft_strcmp(d->ar_only_com[i], ".."))
	{
		ft_set_oldpwd(d);
		chdir("..");
	}
	else if (d->ar_only_com[i] && \
	!ft_strcmp(d->ar_only_com[i], "-"))
		ft_cd_hyphen(d);
	else if (d->ar_only_com[i] && \
	!ft_strcmp(d->ar_only_com[i], "~"))
		ft_cd_diacritic(d);
	else
		ft_file_path(i, d);
	return (0);
}
