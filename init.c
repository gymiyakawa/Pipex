/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:22:34 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/01/18 14:10:50 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

	// initializes all variables in the struct to zero or NULL
void	clean_init(t_data *p)
{
	p->pipe[0] = 0;
	p->pipe[1] = 0;
	p->fd_child1 = 0;
	p->fd_child2 = 0;
	p->env_path = NULL;
}

	// finds the correct PATH string in the enviroment variable.
	// returns a pointer to the fifth character of the string (after
	// the PATH=)

char	*pathfinder(char **envp)
{
	size_t i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5) == NULL)
			i++;
		else
			return (envp[i] + 5);
	}
	return (NULL);
}

	// breaks the path string into their respective addresses, originally
	// separated by ":". returns an array of strings containing each address.
	// finishes by placing a / at the end of each address line.

char	**pathsetter (char **envp)
{
	char	**res;
	char	*path_line;
	size_t	i;

	i = -1;
	res = NULL;
	path_line = NULL;
	path_line = pathfinder(envp);
	if (!path_line)
		return(NULL);
	res = ft_split(path_line, ':');
	while (res[++i])
	{
		ft_strjoin_free(res[i], "/");
	}
	return (res);
}