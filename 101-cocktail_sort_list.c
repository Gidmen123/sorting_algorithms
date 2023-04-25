#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list.
 *
 * @node1: Pointer to the first node to swap.
 * @node2: Pointer to the second node to swap.
 * @list: Pointer to the head node of the list.
 *
 * Description: This function swaps two adjacent nodes in a doubly linked list
 *              by changing the pointers of the surrounding nodes. It also
 *              updates the head of the list if necessary.
 *
 * Return: Nothing.
 */
void swap_nodes(listint_t *node1, listint_t *node2, listint_t **list)
{
    if (node1 == NULL || node2 == NULL || list == NULL || *list == NULL)
        return;

    if (node1->prev != NULL)
        node1->prev->next = node2;
    else
        *list = node2;

    if (node2->next != NULL)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;
    node1->prev = node2;
    node2->next = node1;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *                      using the Cocktail shaker sort algorithm.
 *
 * @list: Pointer to the head node of the doubly linked list to be sorted.
 *
 * Description: This implementation uses the concept of two pointers moving
 *              in opposite directions through the list, sorting the elements
 *              by swapping adjacent nodes as needed. The algorithm is similar
 *              to bubble sort, but with the added feature of moving the pointers
 *              in both directions. The list is sorted in-place.
 *
 * Return: Nothing.
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *left = *list, *right = NULL, *curr = NULL;
    bool swapped = true;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (swapped)
    {
        swapped = false;

        /* Move the right pointer to the last unsorted element */
        curr = left;
        while (curr->next != right)
        {
            if (curr->n > curr->next->n)
            {
                swap_nodes(curr, curr->next, list);
                print_list(*list);
                swapped = true;
            }
            else
                curr = curr->next;
        }

        if (!swapped)
            break;

        swapped = false;

        /* Move the left pointer to the last unsorted element */
        right = curr;
        curr = right->prev;
        while (curr != left->prev)
        {
            if (curr->n > curr->next->n)
            {
                swap_nodes(curr, curr->next, list);
                print_list(*list);
                swapped = true;
            }
            else
                curr = curr->prev;
        }

        left = left->next;
    }
}
