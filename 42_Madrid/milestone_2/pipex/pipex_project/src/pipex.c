/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:22:21 by frromero          #+#    #+#             */
/*   Updated: 2024/12/22 13:32:54 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This program simulates the pipex command. It creates a pipe, forks a child
   process to execute the first command, and a parent process to execute
   the second. It handles file input/output and error checking for command
   execution:      ./pipex infile "cat" "sort" outfile */

#include "../inc/pipex.h"

static void	child_one(int *fd_pipe, char **argv, char **envp)
{
	int		fd_infile;
	char	**cmd;
	char	*path;

	cmd = get_cmd(argv[2]);
	path = get_path(cmd[0], envp);
	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile < 0)
		error("file Error");
	close(fd_pipe[0]);
	dup2(fd_infile, STDIN_FILENO);
	dup2(fd_pipe[1], STDOUT_FILENO);
	if (!path)
	{
		free_tab(cmd);
		write(2, "Error: Command not found\n", 25);
		exit(EXIT_FAILURE);
	}
	execve(path, cmd, envp);
	error("execve Error");
}

static void	child_two(int *fd_pipe, char **argv, char **envp)
{
	int		fd_outfile;
	char	**cmd;
	char	*path;

	cmd = get_cmd(argv[3]);
	path = get_path(cmd[0], envp);
	fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd_outfile < 0)
		error("file Error");
	close(fd_pipe[1]);
	dup2(fd_outfile, STDOUT_FILENO);
	dup2(fd_pipe[0], STDIN_FILENO);
	if (!path)
	{
		free_tab(cmd);
		write(2, "Error: Command not found\n", 25);
		exit(EXIT_FAILURE);
	}
	execve(path, cmd, envp);
	error("execve Error");
}
static void	wait_for_children(pid_t pid1, pid_t pid2)
{
	int	sta;

	waitpid(pid1, &sta, 0);
	if (WIFEXITED(sta))
	{
		int status = WEXITSTATUS(sta);
		if (status != 0)
			exit(EXIT_FAILURE);
	}
	waitpid(pid2, &sta, 0);
	if (WIFEXITED(sta))
	{
		int status = WEXITSTATUS(sta);
		if (status != 0)
			exit(EXIT_FAILURE);
	}
}

static void	pipex(char **argv, char **envp)
{
	int		fd_pipe[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd_pipe) < 0)
		error("pipe Error");
	pid1 = fork();
	if (pid1 < 0)
		error("fork Error");
	if (pid1 == 0)
		child_one(fd_pipe, argv, envp);
	pid2 = fork();
	if (pid2 < 0)
		error("fork Error");
	if (pid2 == 0)
		child_two(fd_pipe, argv, envp);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	wait_for_children(pid1, pid2); /* Proceso padre esperando*/
}

int	main(int argc, char **argv, char **envp)
{
	check_input(argc, argv);
	pipex(argv, envp);
	return (0);
}
