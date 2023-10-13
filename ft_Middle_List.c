/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Middle_List.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:34:05 by root              #+#    #+#             */
/*   Updated: 2023/10/11 21:41:00 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_list_size(struct ListNode *head)
{
    int i;
    struct ListNode *temp;

    temp = head;
    i = 0;
    while (temp)
    {
        i++;
        temp = temp->next;
    }
    return (i);
}
struct ListNode *middleNode(struct ListNode *head)
{
    struct ListNode *temp;
    int index;
    int size;

    temp = head;
    index = 0;
    size = ft_list_size(head);
    while (temp != NULL)
    {
        if (index == size / 2)
            return (temp);
        index++;
        temp = temp->next;
    }
    return (NULL);
}

void ft_push(struct ListNode **begin_list, int number)
{
    struct ListNode *new_node;

    new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (new_node == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    new_node->val = number;
    new_node->next = *begin_list;
    *begin_list = new_node;
}
void ft_print_list(struct ListNode *node)
{
    while (node)
    {
        printf("%d -> ", node->val);
        node = node->next;
    }
    printf("NULL\n");
}

void ft_free(struct ListNode *head)
{
    struct ListNode *temp;
    struct ListNode *next;

    temp = head;
    while (temp)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }
}

void ft_add(void *data)
{
    *(int *)data += 10;
}
void ft_list_foreach(struct ListNode *begin_list, void (*f)(void *))
{
    struct ListNode *temp;

    if (!begin_list || !f)
        return;
    temp = begin_list;
    while (temp)
    {
        (*f)(&temp->val);
        temp = temp->next;
    }
}

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
void ft_list_reverse(struct ListNode **begin_list)
{
    struct ListNode *prev;
    struct ListNode *current;
    struct ListNode *next;

    prev = NULL;
    current = *begin_list;
    next = NULL;
    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *begin_list = prev;
}

void ft_list_foreach_if(struct ListNode *begin_list, void (*f)(void *),
                        void *data_ref, int (*cmp)(const void *, const void *))
{
    struct ListNode *temp;

    temp = begin_list;
    while (temp)
    {
        if ((*cmp)(&temp->val, data_ref) == 0)
            (*f)(&temp->val);
        temp = temp->next;
    }
}

bool cmp1(const void *a, const void *b)
{
    return (*(int *)a == *(int *)b);
}
int search(void *arr, int n, int size_int, void *x, bool(cmp1)(const void *, const void *))
{
    char *ptr;
    int i;

    ptr = (char *)arr;
    i = 0;
    while (i < n)
    {
        if (cmp1(ptr + i * size_int, x))
            return (i);
        i++;
    }
    return (-1);
}
// I need to creat function ft_list_find which returns the
// address of the first element's.
struct ListNode *ft_list_find(struct ListNode *begin_list, void *deta_ref,
                              int (*cmp)(const void *, const void *))
{
    struct ListNode *temp;

    temp = begin_list;
    while (temp)
    {
        if ((*cmp)(&temp->val, deta_ref) == 0)
            return (temp);
        temp = temp->next;
    }
    return (NULL);
}
void free_fct(void *data)
{
    free(data);
}
void ft_list_remove_if(struct ListNode *begin_list, void *data_ref,
                       int (*cmp)(const void *, const void *), void (*free_fct)(void *))
{
    struct ListNode *temp = begin_list;
    struct ListNode *prev = NULL;

    while (temp)
    {
        if ((*cmp)(&temp->val, data_ref) == 0)
        {
            if (!temp)
                begin_list = temp->next;
            else
                prev->next = temp->next;

            struct ListNode *temp1 = temp;
            temp = temp->next;
            free_fct(temp1);
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
}