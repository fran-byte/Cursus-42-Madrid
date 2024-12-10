/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:03:33 by frromero          #+#    #+#             */
/*   Updated: 2024/11/11 17:50:41 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Ejercicios de preparación para push_swap*/
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

struct Person
{
	char	name[50];
	int	age;
	float	height;
	char	color[50];
}person;

void print_person_info(struct Person *p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Height: %.2f\n", p->height);
    printf("Color: %s\n\n", p->color);
}

int	main(int argc, char **argv)
{
	if (argc != 5)
		return (0);
	if (strlen(argv[1]) > 50 || strlen(argv[4]) > 50)
	{
		printf("\n\nmax. 50 caracters !\n\n");
		return (0);
	}
	strcpy(person.name, argv[1]);
	person.age = atoi(argv[2]);
	person.height = atof(argv[3]);
	strcpy(person.color, argv[4]);
	printf("%s\n  %d \n    %.2f\n      %s \n\n",person.name, person.age, person.height, person.color);
	print_person_info(&person);
	return (0);
}
