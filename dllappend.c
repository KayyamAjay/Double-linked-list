#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;//pointing head to null
void append(int x)
{
    struct node *temp,*r;
    temp=(struct node *)malloc(sizeof(struct node));//creating temp node
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)// for 1st element to insert
    {
        head=temp;//pointing head to temp
    }
    else//other than 1st element
    {
        r=head;//pointing r to head
        while(r->next!=NULL)//travesing till the last node
        r=r->next;
        r->next=temp;//making forward connection between last node and newly created temp node
        temp->prev=r;//making backward connection between last node and newly created temp node
        
    }
    
}
void fdisplay()//forword display
{
    struct node *p;
    p=head;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void rdisplay()//reverse display
{
    struct node *p;
    p=head;
    while(p->next!=NULL)//travesing till last node
    p=p->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->prev;
    }
}
int main()
{
    
    int n,i,x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        append(x);
    }
    fdisplay();
    printf("\n");
    rdisplay();

    return 0;
}
