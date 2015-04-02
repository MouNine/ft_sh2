/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell2.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 10:46:25 by eboeuf            #+#    #+#             */
/*   Updated: 2015/04/01 16:09:03 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL2_H
# define FT_MINISHELL2_H

# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

typedef enum 		e_sym
{
	colon, pipes, append, redir_in, redir_out, redir_dest, unknown
}					t_sym;

typedef struct 		s_token
{
	t_sym			token;
	char			*str;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct		s_env
{
	char			**env;
	char			**env_orig;
	char			*path;
	char			**args;
	int				access;
}					t_env;

t_env				*recup_env(void);
void				ft_init_env(char **env);
char				*ft_getenv(char *s);

int					ft_checkspace(char *s);
char				*ft_clean(char *cmd);
void				print_env(char **env);
void				print_shell(t_env *env);

void				ft_builtins(t_env *env);

char				**create_blank_env(t_env *env, int i);
int					ft_destroy(char **env);
t_env				*set_env(const char *n, const char *v, int ow, t_env *e);
int					ft_found(char *s, t_env *env);
t_env				*ft_unsetenv(const char *n, t_env *env);

char				*ft_glue(char **tmp);
char				*ft_news(char **tmp);
char				*ft_trim(char *s);
char				*ft_copy(char *s);
char				*ft_red(char *p, char *e);
void				ft_checkaccess(char *s, t_env *env, int ip);
t_env				*ft_docd(char *path, t_env *env, int ih, int ip);
t_env				*ft_cd(char *path, t_env *env);

t_env				*get_access_exec(t_env *env);
int					ft_fork(t_env *env);

t_token				*init_token(void);

t_sym				is_op(char *str);

#endif
