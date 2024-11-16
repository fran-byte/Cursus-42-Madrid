/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:41:56 by frromero          #+#    #+#             */
/*   Updated: 2024/11/16 14:42:28 by frromero         ###   ########.fr       */
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
	int fd = open("test", O_RDONLY);
	int fd2 = open("test2", O_RDONLY);
	int i = 0;
	while (i++ < 5)
	{
		get_next_line(fd, &line1);
		get_next_line(fd2, &line2);
		printf("%s:%s\n", line1, line2);
	}
	close(fd);
	close(fd2);
}
