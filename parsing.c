/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:35:42 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/01/27 19:15:10 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	cmd_parsing(t_data *p)
{
	p->cmd_args1 = ft_split(p->args[2], ' ');
	if (p->cmd_args1 == NULL)
		errmsg_exit(ERR_CMD);
	p->cmd_args2 = ft_split(p->args[3], ' ');
	if (p->cmd_args2 == NULL)
		errmsg_exit(ERR_CMD);
	p->cmd_path1 = cmd_pathfinder(p, p->cmd_args1);
	if (p->cmd_args1 == NULL)
		errmsg_exit(ERR_CMD);
	p->cmd_path2 = cmd_pathfinder(p, p->cmd_args2);
	if (p->cmd_path2 == NULL)
		errmsg_exit(ERR_CMD);
	return (0);
}

char	*cmd_pathfinder(t_data *p, char **cmd_arg)
{
	int		i;
	char	*tmp;
	char	*res;

	i = 0;
	while (p->env_path[i])
	{
		tmp = ft_strjoin(p->env_path[i], "/");
		res = ft_strjoin(tmp, cmd_arg[0]);
		free (tmp);
		if (access(res, F_OK | X_OK) == 0)
			return (res);
		free(res);
		i++;
	}
	return (NULL);
}
