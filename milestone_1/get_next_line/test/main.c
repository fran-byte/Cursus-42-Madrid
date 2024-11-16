/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:41:56 by frromero          #+#    #+#             */
/*   Updated: 2024/11/16 15:07:43 by frromero         ###   ########.fr       */
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
	printf("BUFFER_SIZE=%d\n", BUFFER_SIZE);

	int fd2 = open("test2", O_RDONLY);

	printf("%s\n", get_next_line(fd2));
	printf("%s\n", get_next_line(fd2));
	printf("%s\n", get_next_line(fd2));
	close(fd2);

	printf("BUFFER_SIZE=%d\n", BUFFER_SIZE);
	int fd1 = open("test1", O_RDONLY);

	printf("%s\n", get_next_line(fd1));
	printf("%s\n", get_next_line(fd1));
	printf("%s\n", get_next_line(fd1));
	close(fd3);

	printf("BUFFER_SIZE=%d\n", BUFFER_SIZE);
	int fd0 = open("test3", O_RDONLY);

	printf("%s\n", get_next_line(fd0));
	printf("%s\n", get_next_line(fd0));
	printf("%s\n", get_next_line(fd0));
	close(fd3);
}
