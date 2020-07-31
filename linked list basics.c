#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
/*Given a reference (pointer to pointer) to the head of a list and int ,appends a new node at the end*/
void append(struct node **head_ref,int new_data)
{//allocate a new node
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *last = (*head_ref);//used in step 5.
    //put in the data
    new_node->data=new_data;
    //Since this will be the last node so the next section will be NULL
    new_node->link=NULL;
    /*if the linked list is empty ,then make the new node as head*/
    if(*head_ref==NULL)
    {
        *head_ref=new_node;
        return;
    }
    //Else traverse the linked list
    while(last->link!=NULL)
        last = last->link;
    //change the next of last node
    last->link=new_node;
    return;
}
//creating a void function for printing the list
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
    //start with the empty linked list
    struct node *head = NULL;
   append(&head,4);
   append(&head,65);
   printf("Entered list is\n");
   printlist(head);
   return 0;
}
