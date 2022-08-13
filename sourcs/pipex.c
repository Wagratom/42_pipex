/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:08:13 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/08/13 19:27:59 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_child(t_data *data)
{
	int	fd[2];
	int	pid;
	int	status;

	verific_erros(0, pipe(fd), "pipe");
	pid = fork();
	verific_erros(0, pid, "fork");
	if (pid == 0)
	{
		close(fd[0]);
		close(data->file[1]);
		dup2(data->file[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		execve(data->path, data->cmd, NULL);
	}
	close(fd[1]);
	waitpid(pid, &status, 0);
	my_clear(data->cmd, data->path);
	if (status)
	{
		my_clear(data->paths, NULL);
		exit(EXIT_FAILURE);
	}
	data->file[0] = fd[0];
}

void	exec_father(t_data *data)
{
	int	pid;
	int	status;

	pid = fork();
	verific_erros(0, pid, "fork");
	if (pid == 0)
	{
		dup2(data->file[0], STDIN_FILENO);
		dup2(data->file[1], STDOUT_FILENO);
		execve(data->path, data->cmd, NULL);
	}
	waitpid(pid, &status, 0);
	close(data->file[0]);
	close(data->file[1]);
	my_clear(data->cmd, data->path);
	my_clear(data->paths, NULL);
	if (status)
		exit(EXIT_FAILURE);
}

void	start_pipex(t_data *data)
{
	while ((data->index + 2) < data->argc)
	{
		if (find_cmd(data))
			exec_child(data);
	}
	if (!find_cmd(data))
	{
		my_clear(data->paths, NULL);
		exit(127);
	}
	exec_father(data);
	exit(EXIT_SUCCESS);
}
