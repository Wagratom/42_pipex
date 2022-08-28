/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 05:17:57 by wwallas-          #+#    #+#             */
/*   Updated: 2022/08/28 05:17:59 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	creat_paths(t_data *data)
{
	char	*paths;
	int		index;

	index = -1;
	while (data->envp[++index])
	{
		paths = ft_strnstr(data->envp[index], "PATH=/", 6);
		if (paths)
		{
			paths = ft_strchr(data->envp[index], '/');
			data->paths = ft_split(paths, ':');
			return ;
		}
	}
}
