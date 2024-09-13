
#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *tmp, *to_delete;
    unsigned int i = 0;

    if (*head == NULL)
        return (-1);

    tmp = *head;

    /* If we are deleting the head node */
    if (index == 0)
    {
        to_delete = tmp;
        *head = tmp->next; /* Move head pointer to next node */
        if (*head != NULL)
            (*head)->prev = NULL;
        free(to_delete);
        return (1);
    }

    /* Traverse to the node before the one to delete */
    while (i < index && tmp != NULL)
    {
        tmp = tmp->next;
        i++;
    }

    /* If index is out of range */
    if (tmp == NULL)
        return (-1);

    to_delete = tmp;
    
    /* Update pointers of adjacent nodes */
    if (to_delete->prev)
        to_delete->prev->next = to_delete->next;

    if (to_delete->next)
        to_delete->next->prev = to_delete->prev;

    free(to_delete);

    return (1);
}
