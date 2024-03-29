/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:25:12 by yrhiba            #+#    #+#             */
/*   Updated: 2024/02/07 15:17:55 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "header.h"

# ifdef __linux__
#  include <sys/types.h>
#  include <readline/history.h>
#  include <sys/wait.h>
#  include <readline/readline.h>
# elif defined(__APPLE__) && defined(__MACH__)
#  include "readline/history.h"
#  include "readline/readline.h"
# endif
# include <dirent.h>
# include <errno.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <termios.h>
# include <unistd.h>

#endif
