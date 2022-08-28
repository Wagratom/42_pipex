/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 05:18:10 by wwallas-          #+#    #+#             */
/*   Updated: 2022/08/28 05:18:13 by wwallas-         ###   ########.fr       */
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
