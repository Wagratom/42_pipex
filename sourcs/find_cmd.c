/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:34:24 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/08/13 19:17:55 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	format_cmd(char	**str, int value, int sub)
{
	char	*tmp;
	int		index;
	int		asp;

	tmp = *str;
	asp = 0;
	index = -1;
	while (tmp[++index])
	{
		if (tmp[index] == 39)
			asp++;
		if (asp % 2 == 1 && tmp[index] == value)
			tmp[index] = sub;
	}
	tmp = NULL;
}

void	get_cmd(t_data *data)
{
	char	*tmp;
	int		index;

	format_cmd(&data->argv[data->index], 32, 1);
	data->cmd = ft_split(data->argv[data->index], ' ');
	index = -1;
	while (data->cmd[++index])
	{
		format_cmd(&data->cmd[index], 1, 32);
		tmp = data->cmd[index];
		data->cmd[index] = ft_strtrim(data->cmd[index], "'");
		free(tmp);
	}
	data->index++;
}

int	find_cmd(t_data *data)
{
	char	*tmp;
	char	*tmp1;
	int		index;

	index = -1;
	get_cmd(data);
	while (data->paths[++index])
	{
		tmp = ft_strjoin(data->paths[index], "/");
		tmp1 = ft_strjoin(tmp, data->cmd[0]);
		free(tmp);
		if (!access(tmp1, F_OK))
		{
			data->path = tmp1;
			return (1);
		}
		free(tmp1);
	}
	write(2, data->cmd[0], ft_strlen(data->cmd[0]));
	write(2, ": command not found\n", 20);
	my_clear(data->cmd, NULL);
	return (0);
}
