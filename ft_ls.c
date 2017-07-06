/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 11:02:25 by nngwenya          #+#    #+#             */
/*   Updated: 2017/07/06 14:09:12 by nngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>

void	list_dir(int argc, char **argv)
{
	DIR	*output_file;
	struct	dirent *dir;

	output_file = opendir(".");
	if (argc == 1)
	{
		if (output_file)
		{
			while ((dir = readdir(output_file)) != NULL)
			{
				if (dir->d_name[0] != '.')
					printf("%s\n", dir->d_name);
			}
		}

	}
	else if (argc > 1)
	{
		perror("Directory can't open.");
		closedir(output_file);
	} 
}

int		main(int argc, char **argv)
{
	list_dir(argc, argv);
	return (0);                                                                                                                                               
}
