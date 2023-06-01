/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:21:11 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/01 01:08:15 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

void	env(int ac, char **av, int status)
{
	t_my_list	*it;

	(void)av;
	if (ac > 1)
	{
		printf("env:: To many Argument\n");
		if (status == YES_EXIT)
			exit(127);
		g_mnsh->exit_status = 127;
		return ;
	}
	it = g_mnsh->env_list;
	while (it)
	{
		printf("%s=%s\n", ((char **)it->data)[0], ((char **)it->data)[1]);
		it = it->next;
	}
	if (status == YES_EXIT)
		exit(EXIT_SUCCESS);
	g_mnsh->exit_status = EXIT_SUCCESS;
}
