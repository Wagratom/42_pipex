/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:49:06 by bankai            #+#    #+#             */
/*   Updated: 2022/08/13 23:46:42 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_data(t_data *data, int argc, char *argv[], char *envp[])
{
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	data->index = 2;
	data->path = NULL;
	data->file[1] = -1;
	open_files(data);
}

void	open_files(t_data *data)
{
	if (!ft_strncmp("here_doc", data->argv[1], 8))
		here_doc(data);
	data->file[0] = open(data->argv[1], O_RDONLY, 0777);
	verific_erros(data->file[0], 0, NULL);
	if (data->file[1] == -1)
	data->file[1] = open(data->argv[data->argc - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0777);
	verific_erros(data->file[1], 0, NULL);
}

void	here_doc(t_data *data)
{
	char	*line;

	data->file[0] = open("/tmp/temp", O_CREAT | O_RDWR | O_TRUNC, 0777);
	verific_erros(data->file[0], 0, NULL);
	data->file[1] = open(data->argv[data->argc - 1],
			O_WRONLY | O_CREAT | O_APPEND, 0777);
	verific_erros(data->file[1], 0, NULL);
	line = get_next_line(STDIN_FILENO);
	while (ft_strncmp(line, data->argv[2], (ft_strlen(line) - 1)))
	{
		write(data->file[0], line, ft_strlen(line));
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	close(data->file[0]);
	data->index = 3;
	data->argv[1] = "/tmp/temp";
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	if (argc >= 5)
	{
		init_data(&data, argc, argv, envp);
		creat_paths(&data);
		start_pipex(&data);
	}
	else
	{
		write(2, "Error: Invalid number of arguments\n", 35);
		exit(EXIT_FAILURE);
	}
	return (0);
}
