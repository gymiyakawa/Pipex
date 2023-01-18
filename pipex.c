/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:17:01 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/01/18 14:16:26 by gmiyakaw         ###   ########.fr       */
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

 an array of two integers is created and a pipe() call populates the array with two available file
 descriptors (usually the lowest two values available)



		for inits. check if envp is NULL or not. If it is, it means a terminal restart is required.
int execve(const char *pathname, char *const argv[],
                  char *const envp[]);



	check arguments handles errors
	assigns path and variables
	creates pipe, assigns fds to respective files
	forks twice: first child executes first command and assigns results to pipe start.
				second child executes second command, using pipe end as argument.
	parent process waits until both processes are finished and clean exits.

	errors in command are handled by bash itself.
*/

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data p;
	// protections / checking if arguments are valid and handling errors
	if (check_args(ac, av, envp) != 0)
		return (-1);
	// initializes arguments and variables
	clean_init(&p);
	// sets the path as an array of strings.
	p.env_path = pathsetter(envp);
	if (!p.env_path)
		{
			ft_printf("environment error, restart terminal.");
			return (2);
		}

// creates the pipe, must make a better error handling function for this
	if (pipe(p.pipe) == -1)
		return (3);
		
		
	p.fd_child1 = fork();
	// error check, make better error management.
	if (p.fd_child1 < 0)
		return (4);


		// is chil1d process?
	if (p.fd_child1 == 0)
	{
		char	*path;
		path = NULL;
		close(p.pipe[1]);
		//  change output to pipe.
		dup2(p.pipe[0], STDOUT_FILENO);
		// find the correct path using access. X_OK = executable?/permission
		while (p.env_path)
		{
			if (access(*p.env_path, X_OK) == 0)
				{
					path = ft_strdup(*p.env_path);
					break;
				}
			p.env_path++;
		}
		// execute first command.
		execve(path, &av[2], envp);
	}


	return (0);
}
