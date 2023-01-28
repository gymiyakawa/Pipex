/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:17:01 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/01/27 18:35:19 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	plumber(t_data *p)
{
	pipe(p->pipe);
	if (p->fd_file1 >= 0)
		p->pid_child1 = fork();
	if (p->pid_child1 < 0)
		errmsg_exit(ERR_FORK);
	else if (p->pid_child1 == 0 && p->fd_file1 >= 0)
		first_child(p);
	p->pid_child2 = fork ();
	if (p->pid_child2 < 0)
		errmsg_exit(ERR_FORK);
	else if (p->pid_child2 == 0)
		second_child(p);
	close (p->pipe[0]);
	close (p->pipe[1]);
	waitpid(p->pid_child1, &p->status, 0);
	waitpid(p->pid_child2, &p->status, 0);
	return ;
}

int	main(int ac, char **av, char **envp)
{
	t_data	p;

	if (ac != 5)
		errmsg_exit(ERR_ARGC);
	init_struct(&p, av, envp);
	fd_setup(&p);
	env_pathfinder(&p);
	cmd_parsing(&p);
	plumber(&p);
	free_struct(&p);
	return (0);
}
