/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:33:46 by vwautier          #+#    #+#             */
/*   Updated: 2024/11/07 17:23:17 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.c"

char *get_next_line(int fd)
{
	static t_list	*save = NULL;
	char 			*line;
	//ssize_t			bytes_read;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0) // Test read pour vois si le fichier est lisible
		return (NULL);
	//ssize_t read(int fd, void *buffer, size_t BUFFER_SIZE); retourne le nombre de bytes lu 
	line = NULL;
	read_save(&save, fd); //jUSTE MALLOC LA LISTE
	line = extract_line(save); //EXTRAIT LA LIGNE malloc
	/*
	ft_lstclear(&save);
	if(!line)
		return (NULL);
	*/
	return(line);
}
/*
int free_all(t_list *list, char *line)
{
	ft_lstclear(&list);
	free(line);

	list = NULL;
	line = NULL;
	return (1);
}*/

char *extract_line(t_list *list)
{
	char *line;
	char *content;
	size_t len;
	t_list *current;

	if (!list)
		return (NULL);
	current = list;
	len = size_content(list);
	line = malloc(sizeof(char) * (len + 1));
	line[len] = '\0';
	while (current != NULL)
	{
		content = (char *)current->content;
		while (*content != '\0')
		{
			*line = *content++;
			*line++;
		}
		current = current->next;
	}
	return (line);
}


void read_save(t_list **save, int fd)
{
	ssize_t sizeRead;
	t_list 	*currentNode;
	char 	*buffer[BUFFER_SIZE + 1];
	
	while(!have_new_line_last(&save))
	{
		sizeRead = read(fd, buffer, BUFFER_SIZE);
		if (sizeRead == -1 || sizeRead == 0)
			return ;
		buffer[sizeRead] = '\0';
		currentNode = ft_lstnew(ft_strdup((const char*)buffer));
		if(!currentNode)
		{
			ft_lstclear(&save);
			save = NULL;
		}
		ft_lstadd_back(save, currentNode);
	}
}

int main()
{
	int fd;
	char *line = NULL;

	fd = open("truc.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	printf("%s",line);

	while (0)
	{
		
		/*
		if (line == NULL)
		{
			free(line);
			line = NULL;
			close(fd);
			break;
		}
		*/
	}
	return 0;
}

/*
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
*/
/*
int main()
{
	size_t BUFFER_SIZE = 4;
	char line[BUFFER_SIZE + 1];
	line [BUFFER_SIZE] = '\0';
	int fd;
	int byte_read;

	//structure
	t_list	*head = NULL;
	t_list	*currentNode = NULL;

	fd = open("truc.txt", O_RDONLY);
    if (fd == -1)
        return (0);
	
	byte_read = read(fd,line,BUFFER_SIZE);

	while (byte_read > 0)
	{
		line[byte_read] = '\0';
		//printf("%s\n", line);

		if (head == NULL)
		{
			head = ft_lstnew(ft_strdup(line));
			currentNode = head;
		}
		else
		{
			currentNode = ft_lstnew(ft_strdup(line));
			ft_lstadd_back(&head, currentNode);
		}
		
		byte_read = read(fd,line,BUFFER_SIZE);
	}


	int i = 0;
	size_t size = size_content(head);
	char *str = malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	populatestr(str, head);
	while (head != NULL)
	{
		printf("%s", (char *)head->content);
		head = head->next;
	}
	// ici j'ai toute ma chaine 
	printf("%d\n",size);
	

	

	ft_putstr_fd(1, str);


	close(fd);
	
}*/