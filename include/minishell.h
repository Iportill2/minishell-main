/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:38:50 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/11/27 18:33:26 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h> 
# include <fcntl.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <sys/stat.h>

extern int g_result;

typedef struct s_data
{
	int		cmd_not_access;
	int		cmd_not_readable;
	int		cmd_not_writeable;
	int		cmd_not_executable;
	int		not_access;
	int		not_readable;
	int		not_writeable;
	int		not_executable;
	int		i;
	int		j;
	int		k;
	int		l;
	int		oks;
	int		snb;
	int		start;
	int		len;
	int		sem_in;
	int		sem_out;
	int		fda[2];
	int		fdb[2];
	int		pipe_check;
	int		original_stdin;
	int		original_stdout;
	int		fdout;
	int		fdin;
	int		int_export;
	int		error;
	int		exit;
	int		echo_jump;
	char	c;
	char	*here_doc;
	char	*s;
	char	*input;
	char	*home;	
	char	*env_path;
	char	*env_with_access;
	char	*content_dollar;
	char	*current_directory;
	char	**array_env;
	char	**array_input;
	char	**array_input_clear;
	char	**array_pipe_redir;
	char	**ar_only_com;
	char	**custom_env;
	pid_t	pid;
}			t_data;

/*MAIN*/
int		main(int argc, char **argv, char **env);
int		ft_bucle(t_data	*g_data);
void	ft_g_data_set(int argc, char **argv, char **env, t_data	*g_data);
void	ft_set_home(t_data *g_data);

/*ERROR*/
int		ft_error(t_data *g_data);
void	ft_error_iker_two(int n, t_data *d);
int		ft_redir_pipe_error(t_data *g_data);
int		ft_redir_pipe_error_ext(int i, t_data *g_data);
void	ft_error_iker(int n, t_data *g_data);

/*ERROR_EXT*/
int		ft_quote_error(char *s, t_data *g_data);
int		ft_redir_error(char **s, t_data *g_data);

/*PILOT*/
void	ft_pilot(t_data *d);
int		ft_pipe_check(t_data *d, int i, char c);
int		ft_pipe_set_a(t_data *d);
int		ft_pipe_set_b(t_data *d);
int		ft_pipe_set_c(t_data *d);

/* PARSHING */
int		ft_try_path_access(t_data *g_data);
int		ft_access(t_data *d, int e);
int		ft_slash(t_data *d);
int		ft_slash_check(char *s);
void	try_access_readable_writeable_executable(char *s, t_data *d);

/*PARSHING_UTILS*/
void	ft_repair_path(t_data *d);
int		ft_get_path(t_data *d);

/*PIPE*/
int		ft_strcmp(const char *s1, const char *s2);
void	ft_pipe_with_sons(t_data *d);
void	ft_father(t_data *d);

/*SPLIT_QUOTE*/
char	**ft_split_quote(char const *s, char c, t_data *d);
int		ft_strcount(const char *s, char c, t_data *d);
void	ft_pipe_redir_count(const char *s, t_data *d);
char	*ft_subsplit(char const *s, char c, int i, t_data *d);

/*SPLIT_QUOTE_UTILS*/
int		ft_subplit_pipe_redir(char const *s, int i, t_data *d);
int		ft_subplit_quote(char const *s, int i, t_data *d);
char	*ft_subsplit_create(char const *s, t_data *d);
void	*ft_del(char **array, int j);

/*SPLIT_QUOTE_CLEAR*/
char	**ft_ar_input_clear(t_data *d);
void	ft_ar_input_clear_quote(t_data *d);
void	ft_ar_input_clear_no_quote(t_data *d);
int		ft_ar_input_set(int i, int len, char **ar, t_data *d);

/*SPLIT_QUOTE_CLEAR_UTILS*/
void	ft_ar_input_set_quote(int i, char **ar, t_data *d);
void	ft_ar_input_set_dolar(int i, char **ar, t_data *d);
int		ft_dollar_len(char *s, t_data *d);
int		ft_dolar_question(t_data *d);

/*COMMAND_SELECT*/
void	ft_command_select(t_data *d);
void	ft_check_pipe(t_data *d);
char	**ft_array_pipe_redir(t_data *d);
char	**ft_ar_only_com(t_data *d, int i);
int		ft_ar_only_comand_len(t_data *d, int i);

/*ECHO*/
int		ft_echo(int i, t_data *d);
void	ft_putstr_custom(char *str, int n, t_data *d);

/*GETCWD*/
void	ft_get_print_cwd(t_data *d);
void	ft_getcwd(t_data *d);
void	ft_print_current_directory(t_data *d);
int		ft_print_env(t_data *d);
void	ft_cleaning_oldpwd(t_data *d);

/*CD*/
int		ft_cd(int i, t_data *d);
int		ft_file_path(int i, t_data *d);
int		ft_cd_home(t_data *d);
int		ft_cd_hyphen(t_data *d);
int		ft_cd_diacritic(t_data *d);

/*CD_UTILS*/
int		ft_set_oldpwd(t_data *d);
int		ft_create_oldpwd(t_data *d);

/*EXPORT*/
int		ft_export(int i, t_data *d);
int		ft_export_error(char *s, t_data *d, int i);
int		ft_export_exec(char *s, t_data *d);
int		ft_export_change(int j, char *s, t_data *d);
int		ft_export_add(char *s, t_data *d);

/*EXPORT_UTILS*/
int		ft_export_no_arg(t_data *d);
int		ft_check_sort(char **ar);
int		ft_sort(char **ar);

/*UNSET*/
int		ft_unset(int i, t_data *d);
int		ft_unset_exec(int j, t_data *d);
int		ft_unstet_imput_error(int i, t_data *g_data);

/*FREE*/
int		ft_free(t_data *d);
int		ft_free_part(t_data *d);
void	ft_free_array(char ***s);
void	ft_print_toito(t_data *g_data);

/*SET_ENV*/
char	*ft_getenv(char *name_variable, t_data *d);
char	*custom_getenv(const char *s, t_data *d);
void	ft_custom_env(char **env, t_data *d);

/*REDIR*/
int		ft_redir_sign(t_data *d, int i);
int		ft_here_doc(char *s, t_data *d, int i);
int		ft_open_rd(char *s, t_data *d);
int		ft_open_w_c_a(char *s, t_data *d);
int		ft_open_w_c_t(char *s, t_data *d);

/*SIGNAL*/
void	ft_signal(void);
void	ft_signal_child(int signal);
void	ft_signal_father(int signal);

/*GNL*/
char	*get_next_line(int fd);

/* LIBFT */
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isalnum(int c);
char	*ft_itoa(int nb);
//void	*ft_calloc(size_t nmemb, size_t size);

#endif