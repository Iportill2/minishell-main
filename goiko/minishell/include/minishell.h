/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:38:50 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/19 13:41:57 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h> /*creo que es para el waitpid */

# define W "\033[0m"
# define R "\033[91m"
# define G "\033[92m"
# define B "\033[34m"
# define Y "\033[33m"/*AMARILLO Yellow*/
# define M "\033[35m"/*ROSA Magenta*/

typedef struct s_data
{
	int		echo_space;
	int		echo_jump;
	int		add_space;
	int		doble_comilla;
	int		comilla_simple;
	int		error;
	int 	status;	
	char 	*env;
	char 	**array_env;
	char 	*array_env_with_access;
	char	*history;
	char 	**array_history;
	char	*input;
	char	**array_input;
	char	**array_input_clear;
	char 	*env_repaired_access_check;
	char 	**cmd_split;
	char 	*env_dollar;
	char 	*string_env_dollar;
	char 	*contenido_dollar;
	pid_t 	pid;
	//char	*input_ok;
}			t_data;

extern t_data	*g_data;//esta linea a todos los archivos excepto main.

/*MAIN*/
int		main(int argc, char **argv,char **env);
void 	ft_save_env(char **env);
void	input_check(void);
void	ft_set_imput(void);

/*ERROR*/
int		ft_error(void);
int		ft_redir_pipe_error(void);
void 	ft_error_iker(int n);
void	comillas_pares(void);
/* PARSHING */
void 	try_path_access(char **s1, char *s2);
void 	ft_repair_path(void);
void 	ft_get_path(void);
void	ft_parseo_history(void);
void	ft_set_imput_ar(void);

/*PIPE*/
void 	pipe_with_sons();
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);

/* LIBFT */
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);

/*SPLIT_QUOTE*/
char	**ft_split_quote(char const *s, char c);
int		ft_strcount(const char *s, char c);
char	*ft_subsplit(char const *s, char c, int i);
void	*ft_del(char **array, int j);
char	**ft_ar_input_clear(void);

/*ECHO*/
void 	ft_recorre_el_array(void);
void 	ft_echo(int i);
void 	ft_putstr_custom(char *str, int n);
void 	ft_env_dollar(char *str);
void 	ft_putstr_custom_simple(char *str, int n);
void 	ft_putstr_custom_doble(char *str, int n);
int		ft_quote_space(int n);

/*DOLAR*/
void 	ft_dollar(char *str);
void 	ft_env_dollar(char *str);
void	ft_putstr(char *s);

#endif