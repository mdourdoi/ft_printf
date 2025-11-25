/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:08:29 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/13 10:02:50 by mdourdoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_create_list(t_list	*lst, void *(*f)(void *), int *flag_err)
{
	t_list	*new_node;

	if (!lst)
		return (NULL);
	new_node = ft_calloc(1, sizeof(t_list));
	if (!new_node)
	{
		*flag_err = 1;
		return (NULL);
	}
	new_node->content = f(lst->content);
	if (!new_node->content)
	{
		*flag_err = 1;
		free(new_node);
		return (NULL);
	}
	new_node->next = ft_create_list(lst->next, f, flag_err);
	return (new_node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*new_lst;
	int		error;
	int		*flag_err;

	if (!lst || !f || !del)
		return (NULL);
	error = 0;
	flag_err = &error;
	new_lst = ft_create_list(lst, f, flag_err);
	if (error == 1)
	{
		if (new_lst)
			ft_lstclear(&new_lst, del);
		return (NULL);
	}
	return (new_lst);
}
