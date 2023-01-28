/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_mgmt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:52:35 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/01/27 19:15:23 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(t_data *p)
{
	dup2(p->pipe[1], STDOUT_FILENO);
	close(p->pipe[0]);
	dup2(p->fd_file1, STDIN_FILENO);
	if (execve(p->cmd_path1, p->cmd_args1, p->envp) == -1)
		errno_exit(ERR_EXEC, errno);
}

void	second_child(t_data *p)
{
	dup2(p->pipe[0], STDIN_FILENO);
	close(p->pipe[1]);
	dup2(p->fd_file2, STDOUT_FILENO);
	if (execve(p->cmd_path2, p->cmd_args2, p->envp) == -1)
		errno_exit(ERR_EXEC, errno);
}
