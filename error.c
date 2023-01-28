/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:34:44 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/01/27 19:15:41 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// used for commands, where execution would produce an errno
void	errno_exit(const char *msg, int n)
{
	perror(msg);
	exit(n);
}

// used for created functions where errno doesn't exist / is
// irrelevant.
void	errmsg_exit(const char *msg)
{
	ft_printf("%s\n", msg);
	exit (1);
}
