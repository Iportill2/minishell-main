/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:38:50 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/16 15:23:14 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

# define W "\033[0m"
# define R "\033[91m"
# define G "\033[92m"

typedef struct s_data
{
	int		add_space;
	char	*input;
	int		doble_comilla;
	int		comilla_simple;
	char	*history;
	char 	**array_history;
	int		error;
	int 	status;	
	char 	*env;
	char 	**array_env;
	char 	*env_repaired_access_check;
	char 	**cmd_split;
	pid_t 	pid;
	//char	*input_ok;
}			t_data;

extern t_data	*g_data;//esta linea a todos los archivos excepto main.

/*MAIN*/
int		main(void);
void	input_check(void);
void	ft_set_imput(void);

/*ERROR*/
int		ft_error(void);
int		ft_redir_pipe_error(void);
void 	ft_error_iker(int n);
void	comillas_pares(void);
/* PArshing */
void 	ft_get_path(void);

/* LIBFT */
size_t	ft_strlen(const char *s);
 char	**ft_split(char const *s, char c);
 char	*ft_strjoin(char const *s1, char const *s2);


#endif