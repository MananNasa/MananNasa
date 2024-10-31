#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node* Start = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    Start->data = 1;
    Start->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    struct Node *ptr;

    ptr = Start;
    int x; 
    printf("Enter the element you have to find : ");
    scanf("%d",&x);

    while(ptr->next != NULL)
    {
        if(x==ptr->data)
        {
            printf("Yes");
            break;
        }
        else
        {
            printf("element %d is not in the list ",x);
            ptr = ptr->next;
            
        }
    }

    return 0;
}
