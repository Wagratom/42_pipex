/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:05:41 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/08/11 13:03:51 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	verific_erros(int file, int rtn, char *cmd)
{
	if (file == -1)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	if (rtn == -1)
	{
		write(2, cmd, ft_strlen(cmd));
		write(2, ": Error executing command\n", 26);
		exit(EXIT_FAILURE);
	}
}

void	my_clear(char	**array, char *path)
{
	int	index;

	index = -1;
	while (array[++index])
		free(array[index]);
	free(array);
	if (path)
		free(path);
}
