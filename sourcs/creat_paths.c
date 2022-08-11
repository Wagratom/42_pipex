/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 22:21:01 by bankai            #+#    #+#             */
/*   Updated: 2022/08/10 22:08:50 by wjuneo-f         ###   ########.fr       */
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
