/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:32:43 by root              #+#    #+#             */
/*   Updated: 2023/10/11 22:32:42 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST
# define FT_LIST

// Definition for singly-linked list.
struct				ListNode
{
	int				val;
	struct ListNode	*next;
};
# include <stdbool.h>

void				ft_add(void *data);
void				ft_push(struct ListNode **begin_list, int number);
void				ft_print_list(struct ListNode *node);
struct ListNode		*middleNode(struct ListNode *head);
void				ft_list_foreach(struct ListNode *begin_list,
						void (*f)(void *));
void				ft_list_foreach_if(struct ListNode *begin_list,
						void (*f)(void *), void *data_ref, int (*cmp)());
int					cmp(const void *a, const void *b);
bool				cmp1(const void *a, const void *b);
int					search(void *arr, int n, int size_int, void *x,
						bool(cmp1)(const void *, const void *));
int					ft_list_size(struct ListNode *head);
void				ft_list_reverse(struct ListNode **begin_list);
struct ListNode		*ft_list_find(struct ListNode *begin_list, void *deta_ref,
						int (*cmp)(const void *, const void *));

void				ft_free(struct ListNode *head);
void                free_fct(void *);
void	ft_list_remove_if(struct ListNode *begin_list, void *data_ref,
		int (*cmp)(const void *, const void *), void (*free_fct)(void *));
#endif
