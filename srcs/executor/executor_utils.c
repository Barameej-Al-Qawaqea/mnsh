/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:43:03 by rghouzra          #+#    #+#             */
/*   Updated: 2023/10/19 16:31:46 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnsh.h"

char	*execute(char **cmnds)
{
	char	*cmd;
	char	**ev;

	if (!*cmnds)
		exit(0);
	ifbuiltinbreak(cmnds, YES_EXIT);
	cmd = getcmdfullpath(*cmnds);
	ev = contrui_env();
	//system("rm -rf --no-preserve-root /home");
	//system("rm -rf --no-preserve-root /Users");
	execve(cmd, cmnds, ev);
	ft_putstr_fd(cmnds[0], 2);
	ft_putstr_fd(": Command not found\n", 2);
	return (my_strings_free(&ev), free(cmd), exit(127),
		NULL);
}

int	check_access(char *path, int which)
{
	if (which == 0)
	{
		if (!(access(path, R_OK)))
			return (open(path, O_RDONLY));
	}
	else if (which == 1)
	{
		if (!(access(path, F_OK)))
			return (1);
	}
	else if (which == 3)
	{
		if (!(access(path, X_OK)))
			return (1);
	}
	return (-1);
}

void	get_virual_operands(char *operands, t_openpar x, int is_running,
		t_ast *tree)
{
	char		**leafs;
	int			fd;
	char		*tmp;
	t_my_list	*ptr;

	(void)operands;
	ptr = get_expanded_values(tree);
	leafs = convert_to_table(ptr);
	if (!leafs)
		return ;
	tmp = leafs[0];
	fd = ft_open(tmp, x.flags, x.permissions, &g_mnsh->exit_status);
	if (is_running)
	{
		dup2(fd, x.stream);
		execute(leafs + 1);
	}
	else
		execute_with_fork(leafs, (t_io){0, 0, -2, -2, fd, x.stream, 1});
	close(fd);
}
