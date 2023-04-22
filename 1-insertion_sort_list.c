#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 *                       ascending order using the Insertion sort algorithm.
 *
 * @list: Pointer to the head of the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *curr = (*list)->next;
    listint_t *prev, *next;

    while (curr != NULL)
    {
        prev = curr->prev;
        while (prev != NULL && prev->n > curr->n)
        {
            next = curr->next;
            if (prev->prev != NULL)
                prev->prev->next = curr;
            else
                *list = curr;
            curr->prev = prev->prev;
            curr->next = prev;
            prev->prev = curr;
            prev->next = next;
            if (next != NULL)
                next->prev = prev;

            prev = curr->prev;
            print_list(*list);
        }
        curr = curr->next;
    }
}

