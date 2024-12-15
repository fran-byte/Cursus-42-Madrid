/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:41:56 by frromero          #+#    #+#             */
/*   Updated: 2024/11/16 15:55:53 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	char *line;

	printf("\nBUFFER_SIZE=%d\n\n", BUFFER_SIZE);

	int fd2 = open("test2", O_RDONLY);

	printf("%s", line = get_next_line(fd2));
	printf("%s", line = get_next_line(fd2));
	printf("%s", line = get_next_line(fd2));
	free(line);
	close(fd2);

	int fd1 = open("test1", O_RDONLY);

	printf("%s", line = get_next_line(fd1));
	printf("%s", line = get_next_line(fd1));
	printf("%s", line = get_next_line(fd1));
	free(line);
	close(fd1);

	int fd0 = open("test3", O_RDONLY);

	printf("%s", line = get_next_line(fd0));
	printf("%s", line = get_next_line(fd0));
	printf("%s", line = get_next_line(fd0));
	free(line);
	close(fd0);
}
