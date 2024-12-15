/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:22:21 by frromero          #+#    #+#             */
/*   Updated: 2024/12/15 20:57:37 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

// Verifica que los argumentos sean válidos
void check_input(int argc, char **argv)
{
    if (argc != 5)
    {
        write(2, "Usage: ./pipex infile \"cmd1\" \"cmd2\" outfile\n", 44);
        exit(EXIT_FAILURE);
    }
}

// Abre un archivo con los permisos dados
int open_file(char *filename, int flags, int perms)
{
    int fd = open(filename, flags, perms);
    if (fd == -1)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    return fd;
}

// Proceso hijo 1: Ejecuta el primer comando
void child_process_1(int *fd, char **argv)
{
    int infile = open_file(argv[1], O_RDONLY, 0); // Abre el archivo de entrada

    // Redirige stdin al archivo de entrada
    dup2(infile, STDIN_FILENO);
    // Redirige stdout al extremo de escritura del pipe
    dup2(fd[1], STDOUT_FILENO);

    // Cierra descriptores innecesarios
    close(infile);
    close(fd[0]);
    close(fd[1]);

    // Ejecuta el primer comando
    char *cmd_args[] = {"/bin/sh", "-c", argv[2], NULL}; // Usamos /bin/sh -c para interpretar el comando
    execve("/bin/sh", cmd_args, NULL);

    // Si execve falla
    perror("Error ejecutando el primer comando");
    exit(EXIT_FAILURE);
}

// Proceso hijo 2: Ejecuta el segundo comando
void child_process_2(int *fd, char **argv)
{
    int outfile = open_file(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644); // Abre el archivo de salida

    // Redirige stdin al extremo de lectura del pipe
    dup2(fd[0], STDIN_FILENO);
    // Redirige stdout al archivo de salida
    dup2(outfile, STDOUT_FILENO);

    // Cierra descriptores innecesarios
    close(outfile);
    close(fd[0]);
    close(fd[1]);

    // Ejecuta el segundo comando
    char *cmd_args[] = {"/bin/sh", "-c", argv[3], NULL}; // Usamos /bin/sh -c para interpretar el comando
    execve("/bin/sh", cmd_args, NULL);

    // Si execve falla
    perror("Error ejecutando el segundo comando");
    exit(EXIT_FAILURE);
}

// Función principal del pipex
void pipex(char **argv)
{
    int fd[2];
    pid_t pid1, pid2;

    // Crea el pipe
    if (pipe(fd) == -1)
    {
        perror("Error creando el pipe");
        exit(EXIT_FAILURE);
    }

    // Crea el primer proceso hijo
    pid1 = fork();
    if (pid1 == -1)
    {
        perror("Error en fork para el primer proceso");
        exit(EXIT_FAILURE);
    }
    if (pid1 == 0) // Proceso hijo 1
        child_process_1(fd, argv);

    // Crea el segundo proceso hijo
    pid2 = fork();
    if (pid2 == -1)
    {
        perror("Error en fork para el segundo proceso");
        exit(EXIT_FAILURE);
    }
    if (pid2 == 0) // Proceso hijo 2
        child_process_2(fd, argv);

    // Cierra descriptores en el proceso padre
    close(fd[0]);
    close(fd[1]);

    // Espera a que los hijos terminen
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}

// Función principal
int main(int argc, char **argv)
{
    check_input(argc, argv);
    pipex(argv);
    return 0;
}

