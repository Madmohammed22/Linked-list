/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:33:56 by root              #+#    #+#             */
/*   Updated: 2023/10/11 20:34:00 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int	main(void)
{
    struct ListNode	*head;

    head = NULL;
    ft_push(&head, 3);
    ft_push(&head, 7);
    ft_push(&head, 2);
    ft_push(&head, 0);
    printf("Original List: ");
    ft_print_list(head);
    printf("The middle node of the list is node ");
    ft_print_list(middleNode(head));
    ft_list_foreach(head, ft_add);
    ft_print_list(head);
    return (0);
}
*/

/*
int	main(void)
{
    int	n;
    int	i;
    int	x;

    int arr[] = {2, 4, 5, 78, 5};
    n = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, n, sizeof(int), cmp);
    printf("Sorted array : ");
    i = 0;
    while (i < n)
    {
        printf("%d  ", arr[i]);
        i++;
    }
    x = 78;
    printf("\nValue %d at index %d\n", x,
            search(arr, n, sizeof(int), &x, cmp1));
    return (0);
}
*/

// All values will add to them 10 from function (ft_add)
// if the comparision returns 0 from (cmp).
// target_value set to 5 and the first value in linked list
// set to 0 which meean 5 - 5 == 0 so ft_list_foreach
// will work.

int main(void)
{
    struct ListNode *head;
    struct ListNode *temp;
    int i;
    int j;

    head = NULL;
    ft_push(&head, 3);
    ft_push(&head, 1);
    ft_push(&head, 8);
    ft_push(&head, 1);
    ft_list_reverse(&head);
    ft_print_list(head);
    int target_value = 1; // you want to compare against
    temp = head;

    i = 0;
    j = ft_list_size(temp);
    while (temp || i < j)
    {
        printf("Node[%d] = returns %d\n", i + 1, cmp(&temp->val, &target_value));
        temp = temp->next;
        i++;
        j--;
    }
    temp = head;
    ft_list_remove_if(head, &target_value, cmp, free_fct);
    ft_print_list(head);
    struct ListNode *found = ft_list_find(head, &target_value, cmp);
    if (found)
        printf("Found: %d\n", found->val);
    else
        printf("Target value not found.\n");

    // ft_list_foreach_if(head, ft_add, &target_value, cmp);
    ft_free(head);
    return (0);
}