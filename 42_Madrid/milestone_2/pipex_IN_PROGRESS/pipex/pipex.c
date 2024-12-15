/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:22:21 by frromero          #+#    #+#             */
/*   Updated: 2024/12/15 11:26:26 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"pipex.h"

void check_input(int argc, char **argv)
{
	if (argc < 5)
	{
		write(1, "\nParameter error", 17);
		write(1, "\nTry again, for example:", 24);
		write(1, "\n./pipex infile \"ls -l\" \"wc -l\" outfile\n", 44);
		program_exit();
	}
}

int open_file(char *ofile)
{
	int fd;

	fd = open(ofile, O_RDONLY);
	if (fd == -1)
	{
		perror("Open failed");
		program_exit();
	}
	return (fd);
}

void	child_process(int *fd, char **argv)
{
	close(fd[0]); //En CHILD NO usaremos la lectura[0] la CERRAMOS
	fd[1] = open_file(argv[1]); // Abrimos archivo (infile) fd[1]
	close(fd[1]); //cerramos ya que hemos terminado de leer

}
void	parent_process(int *fd, char **argv)
{
	close(fd[1]); //En PARENT NO usaremos la escritura[1] la CERRAMOS
	// llamamos a escribir outfile fd[0]
	close(fd[0]); //cerramos ya que hemos terminado de escribir

}
void	pipex(char **argv)
{
	int fd[2];
	pid_t	pid_c;

	pid_c = fork();
	pipe(fd);
	if(pid_c == -1)
	{
		perror("fork() Error: child not created");
		program_exit();
	}
	else if(pid_c == 0)
		child_process(fd, argv);
	else
		parent_process(fd, argv);

}


int	main(int argc, char **argv)
{
	check_input(argc, argv);
	pipex(argv);





	return (0);
}
