/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:22:21 by frromero          #+#    #+#             */
/*   Updated: 2024/12/19 00:25:25 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This program simulates the pipex command. It creates a pipe, forks a child
	process to execute the first command, and a parent process to execute
	the second. It handles file input/output and error checking for command
	execution:      ./pipex infile "cat" "sort" outfile */

#include "../inc/pipex.h"

static void	closed(int *fd, int file)
{
	close(file);
	close(fd[0]);
	close(fd[1]);
}

static void	child_process(int *fd, char **argv, char **envp)
{
	int		infile;
	char	**cmd;
	char	*path;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		error(argv[1]);
	}
	cmd = get_cmd(argv[2]);
	path = get_path(cmd[0], envp);
	if (!path)
	{
		free_tab(cmd);
		write(2, "Error: Command not found\n", 25);
		exit(EXIT_FAILURE);
	}
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	closed(fd, infile);
	execve(path, cmd, envp);
	error("Error");
}

static void	parent_process(int *fd, char **argv, char **envp)
{
	int		outfile;
	char	**cmd;
	char	*path;

	cmd = get_cmd(argv[3]);
	path = get_path(cmd[0], envp);
	if (!path)
	{
		free_tab(cmd);
		write(2, "Error: Command not found\n", 25);
		exit(EXIT_FAILURE);
	}
	outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		free_tab(cmd);
		free(path);
		error(argv[4]);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	closed(fd, outfile);
	execve(path, cmd, envp);
	error("Error");
}

static void	pipex(char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;
	int		pipe_result;

	pipe_result = pipe(fd);
	if (pipe_result == -1)
		error("pipe Error");
	pid = fork();
	if (pid == -1)
		error("fork Error");
	if (pid == 0)
		child_process(fd, argv, envp);
	else
	{
		parent_process(fd, argv, envp);
		waitpid(pid, NULL, 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	check_input(argc);
	pipex(argv, envp);
	return (0);
}
