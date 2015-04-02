/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell2.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 10:46:25 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/30 14:56:17 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL2_H
# define FT_MINISHELL2_H

# define BUFF_SIZE 4096

# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct	s_env
{
	char		**env;
	char		**env_orig;
	char		**path;
	char		**args;
	int 		ret;

}				t_env;

t_env			*recup_env(void);
void			ft_init_env(char **env);
char			*ft_getenv(char *s);

char			**create_blank_env(t_env *env, int i);
int				ft_destroy(char **env);
t_env			*set_env(const char *n, const char *v, int ow, t_env *e);
int				ft_found(char *s, t_env *env);
t_env			*ft_unsetenv(const char *n, t_env *env);

char			*ft_glue(char **tmp);
char			*ft_news(char **tmp);
char			*ft_trim(char *s);
char			*ft_copy(char *s);
char			*ft_red(char *p, char *e);
void     		ft_checkaccess(char *s, t_env *env, int ip);
t_env			*ft_docd(char *path, t_env *env, int ih, int ip);
t_env			*ft_cd(char *path, t_env *env);

int        		ft_fork(char *line, char **args, char **path, t_env *env);

void			print_prompt();
void			print_env(t_env *env);
void			print_shell(t_env *env);
void			ft_builtins(char *line, t_env *env);

int				ft_checkspace(char *s);
char			*ft_clean(char *cmd);

#endif
