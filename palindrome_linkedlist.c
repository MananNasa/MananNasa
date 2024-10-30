#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node 
{
    int data;
    struct Node* next;
};

void insertNode(struct Node** head_ref, int new_data) 
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) 
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

struct Node* reverseList(struct Node* head) 
{
    struct Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

bool isPalindrome(struct Node* head) 
{
    if (head == NULL || head->next == NULL)
        return true;

    struct Node *slow_ptr = head, *fast_ptr = head;
    struct Node *second_half = NULL, *prev_of_slow_ptr = head;
    struct Node *mid_node = NULL;
    bool is_palindrome = true;

    while (fast_ptr != NULL && fast_ptr->next != NULL) 
    {
        fast_ptr = fast_ptr->next->next;
        prev_of_slow_ptr = slow_ptr;
        slow_ptr = slow_ptr->next;
    }

    if (fast_ptr != NULL) 
    {
        mid_node = slow_ptr;
        slow_ptr = slow_ptr->next;
    }

    second_half = reverseList(slow_ptr);

    struct Node* first_half = head;
    while (second_half != NULL) 
    {
        if (first_half->data != second_half->data) 
        {
            is_palindrome = false;
            break;
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }

    second_half = reverseList(second_half);
    
    if (mid_node != NULL) 
    {
        prev_of_slow_ptr->next = mid_node;
        mid_node->next = second_half;
    }
    else 
    {
        prev_of_slow_ptr->next = second_half;
    }

    return is_palindrome;
}

int main() 
{
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the data for each node:\n");
    for (int i = 0; i < n; ++i) 
    {
        scanf("%        d", &data);
        insertNode(&head, data);
    }

    if (isPalindrome(head))
        printf("The linked list is a palindrome.\n");
    else
        printf("The linked list is not a palindrome.\n");

    return 0;
}
