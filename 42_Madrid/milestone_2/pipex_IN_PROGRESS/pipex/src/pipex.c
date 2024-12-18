/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:22:21 by frromero          #+#    #+#             */
/*   Updated: 2024/12/18 00:34:29 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
./pipex infile "cat" "cat" outfile;       // Copia el contenido de `infile` sin cambios en `outfile`.
./pipex infile "cat" "wc -l" outfile;     // Cuenta las líneas de `infile` y guarda el número en `outfile`.
./pipex infile "grep 123" "wc -l" outfile;// Filtra líneas que contienen "123" y cuenta cuántas hay en `outfile`.
./pipex infile "cat" "sort" outfile;      // Ordena alfabéticamente las líneas de `infile` en `outfile`.
./pipex infile "cat" "uniq" outfile;      // Elimina líneas consecutivas duplicadas de `infile` en `outfile`.
./pipex infile "head -n 10" "tail -n 5" outfile; // Extrae las primeras 10 líneas de `infile` y de esas, las últimas 5 a `outfile`.
./pipex infile "cat" "cut -c 1-2" outfile;// Extrae los primeros dos caracteres de cada línea de `infile` en `outfile`.
*/

# include"../inc/pipex.h"

void child_process(int *fd, char **argv)// Proceso hijo: Ejecuta el primer comando
{
	int infile;
	char *cmd_args[4];

	infile = open(argv[1], O_RDONLY); // Abre el archivo de entrada
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
	perror("Error executing the first command");// Si execve falla
	exit(EXIT_FAILURE);
}

void parent_process(int *fd, char **argv)// Proceso padre: Ejecuta el segundo comando
{
	int outfile;
	char *cmd_args[4];

	outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644); // Abre el archivo de salida
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
	perror("Error executing the second command");// Si execve falla
	exit(EXIT_FAILURE);
}

void pipex(char **argv)
{
	int fd[2];
	pid_t pid;
	int pipe_result;

	pipe_result = pipe(fd); // Crea el pipe
	if (pipe_result == -1)
	{
		perror("Error creating the pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork(); // Crea el proceso hijo
	if (pid == -1)
	{
		perror("Error in fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0) // Proceso hijo
		child_process(fd, argv);
	else // Proceso padre . Cierra extremos no usados por el padre
	{
		close(fd[1]);			  // El padre no escribe en el pipe
		parent_process(fd, argv); // Ejecuta el segundo comando
		waitpid(pid, NULL, 0);	  // Espera a que el hijo termine
	}
}

int main(int argc, char **argv)
{
	check_input(argc);
	pipex(argv);
	return (0);
}
