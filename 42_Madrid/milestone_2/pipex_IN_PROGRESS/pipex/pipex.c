/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:22:21 by frromero          #+#    #+#             */
/*   Updated: 2024/12/16 20:04:05 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"pipex.h"

void check_input(int argc, char **argv)
{
	if (argc != 5)
	{
		write(2, "\nUsage: ./pipex infile \"cmd1\" \"cmd2\" outfile\n\n", 46);
		exit(EXIT_FAILURE);
	}
}

int open_file(char *filename, int flags, int perms)
{
	int fd;

	fd = open(filename, flags, perms);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void child_process(int *fd, char **argv)// Proceso hijo: Ejecuta el primer comando
{
	int infile;
	char *cmd_args[4];

	infile = open_file(argv[1], O_RDONLY, 0); // Abre el archivo de entrada
	dup2(infile, STDIN_FILENO);// Redirige stdin al archivo de entrada
	dup2(fd[1], STDOUT_FILENO);// Redirige stdout al extremo de escritura del pipe
	close(infile);// Cierra descriptores innecesarios
	close(fd[0]);
	close(fd[1]);
	cmd_args[0] = "/bin/sh";// Prepara los argumentos para execve
	cmd_args[1] = "-c";
	cmd_args[2] = argv[2];
	cmd_args[3] = NULL;
	execve("/bin/sh", cmd_args, NULL);// Ejecuta el primer comando
	perror("Error ejecutando el primer comando");// Si execve falla
	exit(EXIT_FAILURE);
}

void parent_process(int *fd, char **argv)// Proceso padre: Ejecuta el segundo comando
{
	int outfile;
	char *cmd_args[4];

	outfile = open_file(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644); // Abre el archivo de salida


	dup2(fd[0], STDIN_FILENO);// Redirige stdin al extremo de lectura del pipe
	dup2(outfile, STDOUT_FILENO);// Redirige stdout al archivo de salida
	close(outfile);// Cierra descriptores innecesarios
	close(fd[0]);
	close(fd[1]);
	cmd_args[0] = "/bin/sh";// Prepara los argumentos para execve
	cmd_args[1] = "-c";
	cmd_args[2] = argv[3];
	cmd_args[3] = NULL;
	execve("/bin/sh", cmd_args, NULL);// Ejecuta el segundo comando
	perror("Error ejecutando el segundo comando");// Si execve falla
	exit(EXIT_FAILURE);
}

void pipex(char **argv)// Función principal del pipex
{
	int fd[2];
	pid_t pid;
	int pipe_result;

	pipe_result = pipe(fd); // Crea el pipe
	if (pipe_result == -1)
	{
		perror("Error creando el pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork(); // Crea el proceso hijo
	if (pid == -1)
	{
		perror("Error en fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0) // Proceso hijo
	{
		child_process(fd, argv);
	}
	else // Proceso padre . Cierra extremos no usados por el padre
	{
		close(fd[1]);			  // El padre no escribe en el pipe
		parent_process(fd, argv); // Ejecuta el segundo comando
		waitpid(pid, NULL, 0);	  // Espera a que el hijo termine
	}
}

int main(int argc, char **argv)
{
	check_input(argc, argv);
	pipex(argv);
	return (0);
}
