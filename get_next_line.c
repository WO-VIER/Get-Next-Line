/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:33:46 by vwautier          #+#    #+#             */
/*   Updated: 2024/10/31 20:27:46 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static t_list	**save = NULL;
	char 	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0) // Test read pour vois si le fichier est lisible
		return (NULL);
	
	//ssize_t read(int fd, void *buffer, size_t BUFFER_SIZE); retourne le nombre de bytes lu 

}

int read_and_save(int fd, void *buffer, t_list **save)
{
	ssize_t i;
	ssize_t size;
	int 	finded;
	t_list 	*currentNode;
	

	finded = 0;
	while (!finded)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		currentNode = ft_lstnew(buffer);
		ft_lstadd_back(save, currentNode);
		while (i < size)
		{
			if ((char *)buffer[i++] == '\n')
				finded++;			
		}
		
	}
	
}

add to stach 
{

}

extract line 
{

}
int main()
{
	char *line;
	int fd;

	int fd = open("truc.txt", O_RDONLY);
    if (fd == -1)
        return (NULL); 
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return(0);
		free(line);
	}
	
}