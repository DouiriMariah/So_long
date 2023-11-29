/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:49:22 by mdouiri           #+#    #+#             */
/*   Updated: 2022/02/28 16:50:38 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include "define.h"
#include <stdlib.h> 

t_node	*ft_lstnew(char *content)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_node *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

t_node	*ft_lstlast(t_node *lst)
{
	int	len;
	int	i;

	if (!lst)
		return (NULL);
	i = 0;
	len = ft_lstsize(lst);
	while (i < len && ((lst->next) != NULL))
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}

void	ft_lstadd_back(t_node **alst, t_node *new)
{
	t_node	*last;

	last = NULL;
	if (!alst && !new)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		last = ft_lstlast(*alst);
		last->next = new;
	}
}
