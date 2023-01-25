/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:17:01 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/01/25 15:59:58 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
It must take 4 arguments:
• file1 and file2 are file names.
• cmd1 and cmd2 are shell commands with their parameters.
It must behave exactly the same as the shell command below:
$> < file1 cmd1 | cmd2 > file2


 III.1 Examples
$> ./pipex infile "ls -l" "wc -l" outfile
Should behave like: < infile ls -l | wc -l > outfile $> ./pipex infile "grep a1" "wc -w" outfile
Should behave like: < infile grep a1 | wc -w > outfile



		for inits. check if envp is NULL or not. If it is, it means a terminal restart is required.
int execve(const char *pathname, char *const argv[],
                  char *const envp[]);

*/

#include "pipex.h"

void	plumber(t_data *p)
{
	pipe(p->pipe);
	p->pid_child1 = fork();
	if (p->pid_child1 < 0)
		errmsg_exit(ERR_FORK);
	else if (p->pid_child1 == 0)
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
	{
		ft_printf("error: wrong number of arguments\n");
		exit(1);
	}
	init_struct(&p, av, envp);
	fd_setup(&p);
	env_pathfinder(&p);
	cmd_parsing(&p);
	plumber(&p);
	// print_struct(&p);
	free_struct(&p);
	return (0);
}
