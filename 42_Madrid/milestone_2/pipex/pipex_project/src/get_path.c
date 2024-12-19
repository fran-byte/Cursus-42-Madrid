/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 21:10:41 by frromero          #+#    #+#             */
/*   Updated: 2024/12/19 16:54:44 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Functions to find and construct the full path of a command by searching
	the PATH environment variable, splitting directories,
	and checking executable access. */

#include "../inc/pipex.h"

static char	*find_path_env(char **envp)
{
	while (*envp)
	{
		if (ft_strnstr(*envp, "PATH=", 5))
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

static char	**split_path_directories(char *path_env)
{
	return (ft_split(path_env, ':'));
}

static char	*construct_cmd_path(char *directory, char *cmd)
{
	char	*full_path;
	char	*command_path;

	full_path = ft_strjoin(directory, "/");
	if (!full_path)
		return (NULL);
	command_path = ft_strjoin(full_path, cmd);
	free(full_path);
	if (!command_path)
		return (NULL);
	if (access(command_path, X_OK) == 0)
		return (command_path);
	free(command_path);
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	char	*path_env;
	char	**directories;
	char	*command_path;
	int		i;

	path_env = find_path_env(envp);
	if (!path_env)
		return (NULL);
	directories = split_path_directories(path_env);
	if (!directories)
		return (NULL);
	i = 0;
	while (directories[i])
	{
		command_path = construct_cmd_path(directories[i], cmd);
		if (command_path)
		{
			free_tab(directories);
			return (command_path);
		}
		i++;
	}
	free_tab(directories);
	return (NULL);
}
