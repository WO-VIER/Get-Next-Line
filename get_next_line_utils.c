/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:36:36 by vwautier          #+#    #+#             */
/*   Updated: 2024/11/07 16:50:15 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pointer;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	pointer = *lst;
	while (pointer->next != NULL)
		pointer = pointer->next;
	pointer->next = new;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*pointer;
	t_list	*temp;

	if (lst == NULL)
		return ;
	pointer = *lst;
	while (pointer != NULL)
	{
		temp = pointer->next;
		free(pointer->content);
		free(pointer);
		pointer = temp;
	}
	*lst = NULL;
}

char *ft_strdup(const char *s)
{
	char *str;
	size_t len;
	if (!s)
		return(NULL);
	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if(!str)
		return (NULL);
	str[len] = '\0';
	len = 0;
	while(*s)
		str[len++] = *s++;
	return (str); 
}

size_t ft_strlen(const char *s)
{
	size_t i;
	if(!s)
		return (0);
	i = 0;
	while(s[i] != '\0' && s[i] != '\n') 
		i++;
	return(i);
}

size_t size_content(t_list *list)
{
	size_t size;
	t_list *current;

	if(!list)
		return (0);
	size = 0;
	current = list;

	while (current)
	{
		size = size + ft_strlen((char*)current->content);
		current = current->next;
	}
	return (size);
}

int have_new_line_last(t_list *list)
{
	char *content;
	t_list *last;

	if (!list)
		return(0);

	last = ft_get_last(list);

	if(last->next == NULL)
	{
		content = (char *)last->content;
		while(*content != '\0')
		{
			if(*content == '\n')
				return (1);
			*content++;
		}
	}
	return (0);
}

t_list *ft_get_last(t_list *list)
{
	t_list *current;

	current = list;
	while (current && current->next)
		current = current->next;
	return (current);
}

void populatestr(char *str, t_list *list)
{
	t_list 	*current;
	char 	*content;

	if(!str || !list)
		return ;
	current = list;
	content = (char *)current->content;
	while (current != NULL)
	{
		while(*content != '\0')
		{
			*str = *content++;
			*str++;
		}
		current = current->next;
		if(current != NULL)
			content = (char *)current->content;
	}
}

void ft_putchar_fd(int fd, char c)
{
	write(fd,&c,1);
}

void ft_putstr_fd(int fd, char *str)
{
	while(*str)
	{
		ft_putchar_fd(fd,*str++);
	}
}

int have_new_line(t_list *list)
{
	char *content;
	if (!list)
		return(0);
	while (list != NULL)
	{
		content = (char *)list->content;
		while(*content != '\0')
		{
			if (*content == '\n')
				return (1);
			*content++;
		}
		list = list->next;
	}
	return (0);
}
