/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:39:39 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/01/17 10:58:21 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	access, check commands.
	open, check and determines fd.

*/
#include "pipex.h"

int	check_args(int ac, char **av, char **envp)
{
	if (ac != 5)
	{
		ft_printf("error: invalid argument quantity. Required arguments = 4.");
		return (1);
	}
	if (!av[0] || !av[3])
	{
		ft_printf("error: invalid arguments. Filename required.");
		return (2);
	}
	if (!envp)
	{
		ft_printf("environment error: restart terminal.");
		return (3);
	}
	else
		return (0);
}
