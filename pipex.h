/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:17:36 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/01/18 13:22:14 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
/*
struct composition:
fds for infile and outfile
address for env path.
pipe variables?
*/

typedef struct s_data
{
	int pipe[2];
	int fd_child1;
	int fd_child2;
	char **env_path;
} t_data;

/*---------------- INITIALIZATION ------------------*/
char	*pathfinder(char **envp);
char 	**pathsetter (char **envp);
void	clean_init(t_data *p);

/*--------------- ERROR MANAGEMENT -----------------*/
int		check_args(int ac, char **av, char **envp);