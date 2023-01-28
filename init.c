/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:01:00 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/01/27 18:41:48 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_struct(t_data *p, char **av, char **envp)
{
	p->pipe[0] = 0;
	p->pipe[1] = 0;
	p->pid_child1 = 0;
	p->pid_child2 = 0;
	p->fd_file1 = 0;
	p->fd_file2 = 0;
	p->fd_valid = 0;
	p->status = 0;
	p->env_path = NULL;
	p->envp = envp;
	p->args = av;
	p->cmd_path1 = NULL;
	p->cmd_path2 = NULL;
}

// if infile is invalid, the program still runs the second
// set of commands, but skips the first. As per bash.
int	fd_setup(t_data *p)
{
	p->fd_file1 = open(p->args[1], O_RDONLY);
	if (p->fd_file1 < 0)
		ft_printf("error: no such file or directory\n");
	p->fd_file2 = open(p->args[4], O_RDWR | O_TRUNC | O_CREAT, 0666);
	if (p->fd_file2 < 0)
		errmsg_exit(ERR_FD);
	return (0);
}

//  look for string starting with PATH= in the environment array
// split that line into a string array using : as separator

int	env_pathfinder(t_data	*p)
{
	int		i;
	char	*tmp;

	i = 0;
	while (p->envp[i] && ft_strnstr(p->envp[i], "PATH=", 5) == 0)
		i++;
	if (!p->envp[i])
	{
		errmsg_exit(ERR_PATH);
	}
	tmp = p->envp[i] + 5;
	p->env_path = ft_split(tmp, ':');
	return (0);
}

void	free_struct(t_data *p)
{
	if (p->env_path)
		ft_free_array(p->env_path);
	if (p->cmd_args1)
		ft_free_array(p->cmd_args1);
	if (p->cmd_args2)
		ft_free_array(p->cmd_args2);
	if (p->cmd_args1)
		free(p->cmd_path1);
	if (p->cmd_path2)
		free(p->cmd_path2);
	return ;
}
