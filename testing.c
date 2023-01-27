/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:12:55 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/01/25 13:52:41 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_struct(t_data *p)
{
	printf("Variables:\n");
	printf("\tpid child1: %d\n", p->pid_child1);
	printf("\tpid child 2: %d\n", p->pid_child2);
	printf("\tfd file 1: %d\n", p->fd_file1);
	printf("\tfd file 2: %d\n", p->fd_file2);
	
	int i = -1;
	printf("env path:\n");
	while (p->env_path[++i])
		printf("\t%s\n", p->env_path[i]);
	i = -1;
	printf("arguments:\n");
	while(p->args[++i]) 
		printf("\t%s\n", p->args[i]);
	i = -1;
	printf("cmd args 1:\n");
	while (p->cmd_args1[++i])
		printf("\t%s\n", p->cmd_args1[i]);
	i = -1;
	printf("cmd args 2:\n");
	while (p->cmd_args2[++i])
		printf("\t%s\n", p->cmd_args2[i]);

	printf("cmd path1:\n");
	printf("\t%s\n", p->cmd_path1);

	printf("cmd path2: \n");
	printf("\t%s\n", p->cmd_path2);
	return ;
}
