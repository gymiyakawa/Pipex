/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:56:41 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/01/27 19:13:48 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

/*--------- ERROR MESSAGES -------------------------*/
# define ERR_ARGC "error: invalid number of arguments\n"
# define ERR_FD "error: unable to open file\n"
# define ERR_PATH "error: path not found. Restart terminal\n"
# define ERR_FORK "error: fork function failed\n"
# define ERR_CMD "error: invalid command\n"
# define ERR_EXEC "error: "

/*--------- STRUCT DEFINITION ----------------------*/

typedef struct s_data
{
	int		pipe[2];
	pid_t	pid_child1;
	pid_t	pid_child2;
	int		fd_file1;
	int		fd_file2;
	int		fd_valid;
	int		status;
	char	**env_path;
	char	**envp;
	char	**args;
	char	**cmd_args1;
	char	**cmd_args2;
	char	*cmd_path1;
	char	*cmd_path2;
}	t_data;

/*----- INITIALIZATION / EXIT ----------------------*/
void	init_struct(t_data *p, char **av, char **envp);
int		fd_setup(t_data *p);
int		env_pathfinder(t_data	*p);
void	free_struct(t_data *p);

/*----- ERROR MANAGEMENT ---------------------------*/
void	errno_exit(const char *msg, int n);
void	errmsg_exit(const char *msg);
/*----- ARGUMENT PARSING ---------------------------*/
int		cmd_parsing(t_data *p);
char	*cmd_pathfinder(t_data *p, char **cmd_arg);

/*----- PROCESS HANDLING ---------------------------*/
void	first_child(t_data *p);
void	second_child(t_data *p);

#endif