/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:17:16 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/01/18 10:45:24 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
	Every process has a process id, which is an int. 
	using fork, you can use 
	int id = fork (); 
	id = 0 means its the child process
	id = -1 is an error
	id = !0 means it's the main process
*/


// int main ()
// {
// 	int id = fork();
// 	if (id == 0)
// 	{
// 		printf("this is the child process\n");
// 	}
// 	else 
// 		printf("this is the main process\n");
// }

/* using the wait functions
	stops execution until the a process finishes executing.
	needs a pointer to the process id int.
*/


// using three processes

// #include <unistd.h>

// int main (int ac, char **av)
// {
// 	int id = fork();
// 	int n;

// 	if (id  == 0)
// 		n = 1;
// 	else
// 		n = 6;
// 	if (id != 0)
// 		wait(&id);
// 	int i;
// 	for (i = n; i < n + 5; i++)
// 	{
// 		printf("%d ", i);
// 	}
// 	return 0;
// }

// int main (int ac, char **av)
// {
// 	char *arr [] = { "ping", "google.com", NULL};
// 	int pid;
// 	int err;


// 	pid = fork();
// 	if (pid == -1)
// 		return 1;

// 	if (pid == 0)
// 	{
// 		int file;
// 		file = open("pingResult.txt", O_WRONLY | O_CREAT, 0777);
// 		if (file == -1)
// 			return (2);

// 		dup2(file, STDOUT_FILENO);
// 		close(file);

// 		err = execlp("ping", "ping", "-c", "3", "google.com", NULL);
// 		if (err == -1)
// 		{
// 			printf("execv error. Program not found.\n");
// 			return (2);
// 		}
	
// 	}
// 	else
// 	{
// 		int wait_status;
// 		wait(&wait_status);
// 		if (WIFEXITED(wait_status))
// 		{
// 			int statusCode = WEXITSTATUS(wait_status);
// 			if (statusCode == 0)
// 				printf("Success!\n");
// 			if (statusCode != 0)
// 				printf("Failure with status code %d\n", statusCode);
// 		}

// 		printf("\n\nsome post-process\n");
// 	}
// 	return 0;
// }

// 2 processes
// 1) child process should generate random numbers and send them to the parent
// parent is going to sum all the number and print the result


//  Sending a string through a pipe
// #include <string.h>

// int main (int ac, char **av)
// {
// 	int pfd[2];
// 	int pid;
	
// 	if (pipe(pfd) == -1)
// 		return (1);
// 	pid = fork();
// 	if (pid < 0)
// 		return (2);
// 	if (pid == 0)
// 	{
// 		// child process
// 		close(pfd[0]);
// 		int n;
// 		n = 0;
// 		char str[200];
// 		printf("input string: ");
// 		fgets(str, 200, stdin);
// 		str[strlen(str) - 1] = '\0';
// 		n = strlen(str) + 1;
// 		if (write (pfd[1], &n, sizeof(int)) < 0)
// 			return (4); 
// 		if (write (pfd[1], str, sizeof(char) * n) < 0)
// 			return (3);
// 		close(pfd[1]);
// 	}
// 	else
// 	{
// 	// parent process
// 	close(pfd[1]);
// 	char str[200];
// 	int n;

// 	if (read(pfd[0], &n, sizeof(int)) < 0)
// 		return (5);
// 	if (read(pfd[0], str, sizeof(char) * n) < 0)
// 		return (6);
// 	printf("received: %s \n", str);
// 	close(pfd[0]);
// 	wait(NULL);
// 	}
// 	return (0);
// }

// simulating the pipe function

// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>
// #include <sys/wait.h>

// int main (int ac, char **av)
// {
// 	int pipefd[2];
// 	int	pid1;
// 	int pid2;
// 	if (pipe(pipefd) == -1)
// 		return (1);
// 	pid1 = fork();
// 	if (pid1 < 0)
// 		return (2);
// 	if (pid1 == 0)
// 	{
// 		// first child process
// 		dup2(pipefd[1], STDOUT_FILENO);
// 		close(pipefd[0]);
// 		close(pipefd[1]);
// 		execlp("ping", "ping", "-c", "2", "google.com", NULL);
// 	}

// 	pid2 = fork();
// 	if (pid2 < 0)
// 		return (3);
// 	if (pid2 == 0)
// 	{
// 		// second child processs
// 		dup2(pipefd[0], STDIN_FILENO);
// 		close(pipefd[0]);
// 		close(pipefd[1]);
// 		execlp("grep", "grep", "ms", NULL);
// 	}

// 	close(pipefd[0]);
// 	close(pipefd[1]);

// 	waitpid (pid1, NULL, 0);
// 	waitpid (pid2, NULL, 0);

// 	return (0);
// }

// simulating multiple pipes

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int ac, char ** av)
{
	int pipefd[3][2];
	int i;
	for (i = 0; i < 3 ; i++)
	{
		if (pipefd[i] < 0)
			return (1);
	}
	
	int pid1 = fork();
	if (pid1 < 0)
		return (2);
	if (pid1 == 0)
	{
		
		
		
		
	}
	
	return (0);
}