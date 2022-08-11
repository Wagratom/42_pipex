/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:58:24 by bankai            #+#    #+#             */
/*   Updated: 2022/08/11 08:39:54 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <sys/wait.h>

typedef struct s_data
{
	int		argc;
	char	**argv;
	char	**envp;
	int		index;
	int		file[2];
	char	**paths;
	char	**cmd;
	char	*path;
}			t_data;

void	verific_erros(int file, int rtn, char *cmd);

void	open_files(t_data *data);

void	here_doc(t_data *data);

void	creat_paths(t_data *data);

void	start_pipex(t_data *data);

int		find_cmd(t_data *data);

void	my_clear(char **array, char *path);

#endif
