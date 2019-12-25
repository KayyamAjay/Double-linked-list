#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
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
void insertatbeg(int x)
{
    struct node *temp,*r;
    temp=(struct node *)malloc(sizeof(struct node));//creating temp node
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)// for 1st element to insert
    head=temp;//pointing head to temp
    else
    {
        r=head;//pointing r to head
        temp->next=r;//making connection between first node and new node
        r->prev=NULL;
        head=temp;//making head to point to newnode temp
    }
    
    
}
void insertatpos(int x,int pos)
{
    struct node *temp,*temp1;
    temp=(struct node *)malloc(sizeof(struct node));//creating temp node
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;
    if(pos==1)//inserting at position 1
    {
        temp1=head;
        temp->next=temp1;
        temp1->prev=temp;
        head=temp;
        
    }
    else
    {
        struct node *r;
        temp1=head;
        for(int i=0;i<pos-2;i++)//travesing till to the postion-1 to insert
        temp1=temp1->next;
        r=temp1->next;
        temp->next=temp1->next;
        temp1->next=temp;
        temp->prev=temp1;
        r->prev=temp;
        
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
 
    int n,i,x,pos;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        insertatbeg(x);
    }
    fdisplay();
    scanf("%d %d",&x,&pos);
    insertatpos(x,pos);
    fdisplay();
    


    return 0;
}
