/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:22:21 by frromero          #+#    #+#             */
/*   Updated: 2024/12/18 17:53:21 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* PROYENCTO A RETIRAR y MODIFICAR PUEDE NO PASAR LA EVALUACIÓN */
/*
./pipex infile "cat" "cat" outfile; //Copia el contenido de `infile` sin
 	cambios en `outfile`.
./pipex infile "cat" "wc -l" outfile; / Cuenta las líneas de `infile` y guarda
	el número en `outfile`.
./pipex infile "grep 123" "wc -l" outfile;// Filtra líneas que contienen "123"
	y cuenta cuántas hay en `outfile`.
./pipex infile "cat" "sort" outfile;  // Ordena alfabéticamente las líneas de
	`infile` en `outfile`.
./pipex infile "cat" "uniq" outfile;  // Elimina líneas consecutivas duplicadas
	de `infile` en `outfile`.
./pipex infile "head -n 10" "tail -n 5" outfile; // Extrae las primeras 10
	líneas de `infile` y de esas, las últimas 5 a `outfile`.
./pipex infile "cat" "cut -c 1-2" outfile;// Extrae los primeros dos caracteres
	de cada línea de `infile` en `outfile`.
*/

# include"../inc/pipex.h"
/* PROYENCTO A RETIRAR y MODIFICAR PUEDE NO PASAR LA EVALUACIÓN */
void child_process(int *fd, char **argv)
{
	int infile;
	char *cmd_args[4];

	infile = open(argv[1], O_RDONLY);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(infile);
	close(fd[0]);
	close(fd[1]);
	cmd_args[0] = "/bin/sh";
	cmd_args[1] = "-c";
	cmd_args[2] = argv[2];
	cmd_args[3] = NULL;
	execve("/bin/sh", cmd_args, NULL);
	perror("Error executing the first command");
	exit(EXIT_FAILURE);
}

void parent_process(int *fd, char **argv)
{
	int outfile;
	char *cmd_args[4];

	outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	close(fd[0]);
	close(fd[1]);
	cmd_args[0] = "/bin/sh";
	cmd_args[1] = "-c";
	cmd_args[2] = argv[3];
	cmd_args[3] = NULL;
	execve("/bin/sh", cmd_args, NULL);
	perror("Error executing the second command");
	exit(EXIT_FAILURE);
}

void pipex(char **argv)
{
	int fd[2];
	pid_t pid;
	int pipe_result;

	pipe_result = pipe(fd);
	if (pipe_result == -1)
	{
		perror("Error creating the pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error in fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		child_process(fd, argv);
	else
	{
		close(fd[1]);
		parent_process(fd, argv);
		waitpid(pid, NULL, 0);
	}
}

int main(int argc, char **argv)
{
	check_input(argc);
	pipex(argv);
	return (0);
}
