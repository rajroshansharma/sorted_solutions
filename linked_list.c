#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void append(struct node **head_ref,int new_data)
{
    //let's start by making a node
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *last = (*head_ref);
    //let's put the data
    new_node->data = new_data;
    new_node->link = NULL;
    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    //else traverse the list
    while(last->link!=NULL)
        last = last->link;
    //change the next of last node
    last->link = new_node;
    return;

}
void printlist(struct node *node)
{
    while(node!=NULL)
    {
        printf("%d->",node->data);
        node=node->link;
    }
    printf("NULL");
}
int main()
{
    int choice,new_data;
    struct node *head=NULL;
    //append(&head,67);

    do
    {
        printf("Enter your choice\n##...0...## for stop 1 for continue ");
        scanf("%d",&choice);
        printf("Enter the element : ");
        scanf("%d",&new_data);
        append(&head,new_data);
    }while(choice!=0);

    printf("Your linked list is \n");
    printlist(head);

    return 0;
}
