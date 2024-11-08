/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:36:39 by vwautier          #+#    #+#             */
/*   Updated: 2024/11/07 15:55:17 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h> 
# include <stdio.h>

# ifndef BUFFER_SIZE
# 	define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
void	ft_lstclear(t_list **lst);
void read_save(t_list *save, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
char *ft_strdup(const char *s);
size_t ft_strlen(const char *s);
size_t size_content(t_list *list);
void populatestr(char *str, t_list *list);
void ft_putchar_fd(int fd, char c);
void ft_putstr_fd(int fd, char *str);
int have_new_line(t_list *list);
int have_new_line_last(t_list *list);
t_list *ft_get_last(t_list *list);
char *extract_line(t_list *list);
char *get_next_line(int fd);

#endif