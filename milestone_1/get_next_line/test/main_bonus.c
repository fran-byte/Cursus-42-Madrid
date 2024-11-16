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

#include "get_next_line_bonus.h"

int main()
{
	printf("BUFFER_SIZE=%d\n", BUFFER_SIZE);
	char *line1 = NULL;
	char *line2 = NULL;
	int fd = open("test1", O_RDONLY);
	int fd2 = open("test2", O_RDONLY);
	int i = 0;


	get_next_line(fd);
	get_next_line(fd2);
	printf("%s:%s\n", line1, line2);

	close(fd);
	close(fd2);


	printf("BUFFER_SIZE=%d\n", BUFFER_SIZE);
	int fd3 = open("test1", O_RDONLY);
	int fd4 = open("test2", O_RDONLY);
	i = 0;



	printf("%s\n", get_next_line(fd3));
	printf("%s\n", get_next_line(fd4));
	printf("%s\n", get_next_line(fd3));
	printf("%s\n", get_next_line(fd4));
	printf("%s\n", get_next_line(fd3));
	printf("%s\n", get_next_line(fd4));

	close(fd3);
	close(fd4);
}